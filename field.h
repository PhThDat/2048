#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <stdarg.h>
#include "cell.h"

using namespace std;

enum direction { UP, DOWN, LEFT, RIGHT };

struct Field
{
    int valueStore, xStore, yStore;
    CellList cellList;
    void renderField();
    void arrangeNumberSlot(int len);
    void selectRandomFreeSlot();
    void newCell();
    void cellMove(direction dir);
    void scanInteraction(char s);
    void printYOULOSE(bool check);
    bool ifCellsAreImmovable();
    bool slotIsOccupied(int x1, int y1);
    Field();
};

#endif