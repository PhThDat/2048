#include "cell.h"
#include <iostream>
#include "time.h"

using namespace std;

static unsigned long m1 = 123456789, m2 = 362436069, m3 = 521288629;
unsigned long xorShift(void)
{
    srand(time(NULL));
    unsigned long t;
    m1 ^= m1 << 16;
    m1 ^= m1 >> 5;
    m1 ^= m1 << 1;

    t = m1;
    m1 = m2 + rand();
    m2 = m3;
    m3 = t ^ m1 ^ m2;

    return m3;
}

void Cell::generateValue()
{
    int a = 1 + xorShift() % 100;
    if (a <= 0)
        a *= -1;
    if (a <= 70)
        value = 2;
    else value = 4;
}

void CellList::generateCellCoordinate(Cell* c)
{
    c->x = xorShift() % 4 + 1;
    c->y = xorShift() % 4 + 1;
}

void CellList::setAsHead(Cell* c)
{
    *head_ref = c;
}

int CellList::countCell()
{
    int n = 1;
    Cell* temp = *head_ref;
    while (temp->next != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

int CellList::getCellPosition(Cell* c)
{
    if (c == *head_ref)
        return 1;
    Cell* temp = *head_ref;
    while (temp->next != c)
    {
        n++;
        temp = temp->next;
    }
    return ++n;
}

void CellList::generateNewCell()
{
    Cell* temp = new Cell();
    temp = *head_ref;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Cell();
    temp->next->generateValue();
}

void CellList::printValue()
{
    Cell* temp = new Cell();
    temp = *head_ref;
    while (temp->next != NULL)
    {
        cout << temp->value << ' ';
        temp = temp->next;
    }
    cout << temp->value << '\n';
}

void CellList::deleteCell(int n)
{
    if (n > countCell())
        return;
    else if (n == countCell())
    {
        Cell* temp = *head_ref;
        Cell* preTemp = temp;
        while (temp->next != NULL)
        {
            preTemp = temp;
            temp = temp->next;
        }
        preTemp->next = null;
        delete temp;        
    }
    else if (n == 1)
    {
        Cell* temp = *head_ref;
        *head_ref = temp->next;
        temp = NULL;
        delete temp;
    }
    else
    {
        int k = 1;
        Cell* temp = *head_ref;
        Cell* preTemp = temp;
        while (temp->next != NULL && k < n)
        {
            preTemp = temp;
            temp = temp->next;
            k++;
        }
        preTemp->next = temp->next;
        temp = NULL;
        delete temp;
    }
}

void CellList::allowMerge()
{
    Cell* temp = *head_ref;
    while (temp->next != NULL)
    {
        temp->mergeLock = false;
        temp = temp->next;
    }
}

Cell* CellList::lastCell()
{
    ell* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    return temp;
}

void CellList::mergeCell(Cell* c1, Cell* c2)
{
    c1->value += c2->value;
    deleteCell(getCellPosition(c2));
}

CellList::CellList()
{
    setAsHead(head);
    head->generateValue();
    generateCellCoordinate(head);
}

Cell::Cell()
{
    mergeLock = false;
}