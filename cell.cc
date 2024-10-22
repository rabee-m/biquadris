#include "cell.h"

void Cell::setType(char _type) {
	type = _type;
}

void Cell::setId(int _id) {
	id = _id;
}

void Cell::setCoords(int _row, int _col) {
	row = _row;
	col = _col;
}

char Cell::getType() {
	return type;
}

int Cell::getRow() {
	return row;
}

int Cell::getCol() {
	return col;
}

int Cell::getId() {
	return id;
}

int Cell::getLvl() {
	return lvl;
}

void Cell::setLvl(int l) {
	lvl = l;
}
