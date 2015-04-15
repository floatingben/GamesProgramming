#pragma once
#include "Tile.h"

class World
{
private:
	//vector of tiles of bush
	vector<Tile *> bushTiles;

	//indivdual apples
	Tile * apple1;
	Tile * apple2;
	Tile * apple3;
	Tile * apple4;
	Tile * apple5;
	Tile * apple6;
	Tile * apple7;
	Tile * apple8;
	Tile * apple9;
	Tile * apple10;

	//renders each apple
	bool renderApple1;
	bool renderApple2;
	bool renderApple3;
	bool renderApple4;
	bool renderApple5;
	bool renderApple6;
	bool renderApple7;
	bool renderApple8;
	bool renderApple9;
	bool renderApple10;

	
public:
	World();
	~World();
	void SetBush(GLuint GLtexID, int width, int height);
	void SetApple(GLuint GltextA, int width, int height);
	vector<Tile*> &GetBushTiles();
	
	//Gets each apple
	Tile* GetApple1(){ return apple1; }
	Tile* GetApple2(){ return apple2; }
	Tile* GetApple3(){ return apple3; }
	Tile* GetApple4(){ return apple4; }
	Tile* GetApple5(){ return apple5; }
	Tile* GetApple6(){ return apple6; }
	Tile* GetApple7(){ return apple7; }
	Tile* GetApple8(){ return apple8; }
	Tile* GetApple9(){ return apple9; }
	Tile* GetApple10(){ return apple10; }

	//Sets each apple
	void SetrenderApple1(bool value){ renderApple1 = value; }
	void SetrenderApple2(bool value){ renderApple2 = value; }
	void SetrenderApple3(bool value){ renderApple3 = value; }
	void SetrenderApple4(bool value){ renderApple4 = value; }
	void SetrenderApple5(bool value){ renderApple5 = value; }
	void SetrenderApple6(bool value){ renderApple6 = value; }
	void SetrenderApple7(bool value){ renderApple7 = value; }
	void SetrenderApple8(bool value){ renderApple8 = value; }
	void SetrenderApple9(bool value){ renderApple9 = value; }
	void SetrenderApple10(bool value){ renderApple10 = value; }
	
	void render();


};

