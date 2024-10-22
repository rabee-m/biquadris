#ifndef CELL_H
#define CELL_H

class Cell {
	char type;
	int row;
	int col;
	int id;
	int lvl;

	public:
	void setType(char _type);
	void setCoords(int _row, int _col);
	void setId(int _id);
	char getType();
	int getRow();
	int getCol();
	int getId();
	void setLvl(int i);
	int getLvl();
};

#endif
