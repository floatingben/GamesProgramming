#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define GLX_GLXEXT_LEGACY //Must be declared so that our local glxext.h is picked up, rather than the system one

#define _CRT_SECURE_NO_WARNINGS

//Headers 
#include <windows.h>
#include "windowOGL.h"
#include "GameConstants.h"
#include "cWNDManager.h"
#include "cInputMgr.h"
#include "cSoundMgr.h"
#include "cFontMgr.h"
#include "cSprite.h"
#include "Player.h"
#include "Tile.h"
#include "World.h"
#include "MainMenu.h"



int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR cmdLine,
                   int cmdShow)
{
	//Gives value to our timer
	float time = 30; 

	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);

    //Set our window settings
    const int windowWidth = 1024;
    const int windowHeight = 768;
    const int windowBPP = 16;

	//This is our window
	static cWNDManager* pgmWNDMgr = cWNDManager::getInstance();

	// This is the input manager
	static cInputMgr* theInputMgr = cInputMgr::getInstance();

	//// This is the sound manager
	static cSoundMgr* theSoundMgr = cSoundMgr::getInstance();

	//// This is the Font manager
	static cFontMgr* theFontMgr = cFontMgr::getInstance();

    //The example OpenGL code
    windowOGL theOGLWnd;
	
    //Attach our the OpenGL window
	pgmWNDMgr->attachOGLWnd(&theOGLWnd);

	// Attach the keyboard manager
	pgmWNDMgr->attachInputMgr(theInputMgr);

	//Attempt to create the window
	if (!pgmWNDMgr->createWND(windowWidth, windowHeight, windowBPP))
    {
        //If it fails

        MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
        return 1;
    }

	if (!theOGLWnd.initOGL(windowWidth, windowHeight)) //Initialize our example
    {
        MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
        return 1;
    }

	//Clear key buffers
	theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER);

	//// Load Sound
	LPCSTR gameSounds[1] = { "Audio/Theme.wav"};

	theSoundMgr->add("Theme", gameSounds[0]);


	//// Load Fonts
	LPCSTR gameFonts[2] = { "Fonts/digital-7.ttf", "Fonts/space age.ttf" };

	//theFontMgr->addFont("SevenSeg", gameFonts[0], 24);
	theFontMgr->addFont("Space", gameFonts[1], 24);

	//create texture for the bush
	cTexture texture;
	texture.createTexture("images\\bush.png");
	//create texture for the apple
	cTexture appletexture;
	appletexture.createTexture("images\\apple1.png");

	//sets texture in the world
	World world;
	world.SetBush(texture.getTexture(), texture.getTWidth(), texture.getTHeight());
	world.SetApple(appletexture.getTexture(), appletexture.getTWidth(), appletexture.getTHeight());
	
	Player pl(&world);
	pl.attachInputMgr(theInputMgr); // Attach the input manager to the sprite
	
	//textures and sprites declared
	cTexture textureBkgd;
	cSprite spriteBkgd;
	cTexture plText;
	cSprite plSprite;
	cTexture textureEndBkgd;
	cSprite spriteEndBkgd;
	cTexture textureStartBkgd;
	cSprite spriteStartBkgd;

		
		textureStartBkgd.createTexture("Images\\first.png");
		spriteStartBkgd.setTexture(textureStartBkgd.getTexture());
		spriteStartBkgd.setTextureDimensions(textureStartBkgd.getTWidth(), textureStartBkgd.getTHeight());
		spriteStartBkgd.setSpritePos(glm::vec2(textureStartBkgd.getTWidth() / 2, textureStartBkgd.getTHeight() / 2));

		textureBkgd.createTexture("Images\\dirt.jpg");
		spriteBkgd.setTexture(textureBkgd.getTexture());
		spriteBkgd.setTextureDimensions(textureBkgd.getTWidth(), textureBkgd.getTHeight());
		spriteBkgd.setSpritePos(glm::vec2(textureBkgd.getTWidth() / 2, textureBkgd.getTHeight() / 2));

		textureEndBkgd.createTexture("Images\\end.png");
		spriteEndBkgd.setTexture(textureEndBkgd.getTexture());
		spriteEndBkgd.setTextureDimensions(textureBkgd.getTWidth(), textureBkgd.getTHeight());
		spriteEndBkgd.setSpritePos(glm::vec2(textureBkgd.getTWidth() / 2, textureBkgd.getTHeight() / 2));

		
		plText.createTexture("Images\\girl.png");
		
		plSprite.setSpritePos(glm::vec2(122.0f, 600.0f));
		plSprite.setTexture(plText.getTexture());
		plSprite.setTextureDimensions(plText.getTWidth(), plText.getTHeight());

		pl.SetSprite(&plSprite);



		theSoundMgr->getSnd("Theme")->playAudio(AL_TRUE);

	
    //This is the mainloop, we render frames until isRunning returns false
	while (pgmWNDMgr->isWNDRunning())
	{
		spriteStartBkgd.render();
		if (theInputMgr->wasKeyPressed(VK_SPACE))
		{
				if (time <= 0)
				{
					time = 0;
					spriteEndBkgd.render();

				}
				else {
				
				spriteBkgd.render();
				pl.Render();
				world.render();
				string st = to_string((int)time);
				LPCSTR stri = st.c_str();
				theFontMgr->getFont("Space")->printText(stri, FTPoint(500.0f, -10.0f, 0.0f));
				
				string st1 = to_string((int)pl.GetScore());
				LPCSTR pscore = st1.c_str();
				theFontMgr->getFont("Space")->printText(pscore, FTPoint(450.0f, -10.0f, 0.0f));
				
			}
		}
		
		pgmWNDMgr->swapBuffers();

		pgmWNDMgr->processWNDEvents(); //Process any window events

        //We get the time that passed since the last frame
		float elapsedTime = pgmWNDMgr->getElapsedSeconds();
		time -= elapsedTime;
		

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		pl.Update(elapsedTime, &world);
		pl.Update(elapsedTime, &world);
			
		
		}
    
	theOGLWnd.shutdown(); //Free any resources
	pgmWNDMgr->destroyWND(); //Destroy the program window

    return 0; //Return success
}
