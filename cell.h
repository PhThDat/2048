#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

struct Cell
{
    int value;
    int x, y;
    bool mergeLock;
    void generateValue();
    Cell* next = null;
    Cell();
};

struct CellList
{
    Cell* head = new Cell();
    Cell** head_ref = new Cell*();
    Cell* lastCell();
    void setAsHead(Cell* h);
    void generateNewCell();
    void printValue();
    void deleteCell(int n);
    void generateCellCoordinate(Cell* c);
    void mergeCell(Cell* c1, Cell* c2);
    void allowMerge();
    bool ifCoordIsOccupied(int x1, int y1);
    int countCell();
    int getCellPosition(Cell* c);
    CellList();
};

#endif