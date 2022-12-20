#include "field.h"
#include <iostream>
#include <string>
#include <vector>

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

void Field::renderField()
{
    cout << "---------------------------------\n";
    cout << "|       |       |       |       |\n";
    cout << '|';
    if (!slotIsOccupied(1, 1))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(1, 2))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(1, 3))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(1, 4))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << "|\n";
    cout << "|       |       |       |       |\n";
    cout << "---------------------------------\n";
    cout << "|       |       |       |       |\n";
    cout << '|';
    if (!slotIsOccupied(2, 1))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(2, 2))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(2, 3))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(2, 4))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << "|\n";
    cout << "|       |       |       |       |\n";
    cout << "---------------------------------\n";
    cout << "|       |       |       |       |\n";
    cout << '|';
    if (!slotIsOccupied(3, 1))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(3, 2))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(3, 3))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(3, 4))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << "|\n";
    cout << "|       |       |       |       |\n";
    cout << "---------------------------------\n";
    cout << "|       |       |       |       |\n";
    cout << '|';
    if (!slotIsOccupied(4, 1))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(4, 2))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(4, 3))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << '|';
    if (!slotIsOccupied(4, 4))
        arrangeNumberSlot(to_string(valueStore).length());
    else if (valueStore == 0)
        for (int i = 1; i <= 7; i++)
            cout << ' ';
    cout << "|\n";
    cout << "|       |       |       |       |\n";
    cout << "---------------------------------\n";
}

bool Field::slotIsOccupied(int x1, int y1)
{
    Cell* temp = *(cellList.head_ref);
    if (temp->x == x1 && temp->y == y1)
    {
        valueStore = temp->value;
        return true;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            if (temp->x == x1 && temp->y == y1)
            {
                valueStore = temp->value;
                return true;
            }
        }
    }
    valueStore = 0;
    return false;
}

void Field::arrangeNumberSlot(int len)
{
    for (int i = 1; i <= (int)((7 - len) / 2); i++)
        cout << ' ';
    if (valueStore != 0)
        cout << valueStore;
    for (int i = 1; i <= 7 - (int)((7 - len) / 2) - len; i++)
        cout << ' ';
}

void Field::selectRandomFreeSlot()
{
    vector<int> g;
    for (int x = 1; x <= 4; x++)
    {
        if (!slotIsOccupied(x, 1) || !slotIsOccupied(x, 2) || !slotIsOccupied(x, 3) || !slotIsOccupied(x, 4))
            g.push_back(x);
    }
    int b = xorShift() % g.size();

    vector<int> a;
    for (int y = 1; y <= 4; y++)
    {
        if (!slotIsOccupied(g[b], y))
            a.push_back(y);
    }
    int c = xorShift() % a.size();

    xStore = g[b];
    yStore = a[c];
}

void Field::newCell()
{
    cellList.generateNewCell();
    selectRandomFreeSlot();
    cellList.lastCell()->x = xStore;
    cellList.lastCell()->y = yStore;
}

void Field::cellMove(direction dir)
{
    Cell* temp = *(cellList.head_ref);
    switch (dir)
    {
    case UP:
        for (int y1 = 1; y1 <= 4; y1++)
        {
            for (int x1 = 2; x1 <= 4; x1++)
            {
                if (slotIsOccupied(x1, y1))
                {
                    if (temp->x == x1 && temp->y == y1)
                        ;
                    else while (temp->next != NULL)
                    {
                        if (!(temp->x == x1 && temp->y == y1))
                            temp = temp->next;
                        else break;
                    }
                    int a = temp->x;
                    for (int i = 1; i < a; i++)
                    {
                        Cell* temp1 = *(cellList.head_ref);
                        if (slotIsOccupied(temp->x - 1, temp->y))
                        {
                            if (temp->x == temp->x - 1 && temp->y == y1);
                            else while (temp1->next)
                            {
                                if (!(temp1->x == temp->x - 1 && temp1->y == temp->y))
                                    temp1 = temp1->next;
                                else break;
                            }
                        }

                        if (!slotIsOccupied(temp->x - 1, temp->y))
                            temp->x--;
                        else if (slotIsOccupied(temp->x - 1, temp->y) && temp->value == temp1->value)
                        {
                            temp->x = temp1->x;
                            temp->y = temp1->y;
                            cellList.mergeCell(temp, temp1);
                            break;
                        }
                    }
                    temp = *(cellList.head_ref);
                }
            }
        }
        break;
    case DOWN:
        for (int y1 = 1; y1 <= 4; y1++)
        {
            for (int x1 = 3; x1 >= 1; x1--)
            {
                if (slotIsOccupied(x1, y1))
                {
                    if (temp->x == x1 && temp->y == y1)
                        ;
                    else while (temp->next != NULL)
                    {
                        if (!(temp->x == x1 && temp->y == y1))
                            temp = temp->next;
                        else break;
                    }
                    int a = temp->x;
                    for (int i = 1; i < (4 - a); i++)
                    {
                        Cell* temp1 = *(cellList.head_ref);
                        if (slotIsOccupied(temp->x + 1, temp->y))
                        {
                            if (temp->x == temp->x + 1 && temp->y == y1);
                            else while (temp1->next)
                            {
                                if (!(temp1->x == temp->x + 1 && temp1->y == temp->y))
                                    temp1 = temp1->next;
                                else break;
                            }
                        }

                        if (!slotIsOccupied(temp->x + 1, temp->y))
                            temp->x++;
                        else if (slotIsOccupied(temp->x + 1, temp->y) && temp->value == temp1->value)
                        {
                            temp->x = temp1->x;
                            temp->y = temp1->y;
                            cellList.mergeCell(temp, temp1);
                            break;
                        }
                    }
                    temp = *(cellList.head_ref);
                }
            }
        }
        break;
    case LEFT:
        for (int x1 = 1; x1 <= 4; x1++)
        {
            for (int y1 = 2; y1 <= 4; y1++)
            {
                if (slotIsOccupied(x1, y1))
                {
                    if (temp->x == x1 && temp->y == y1)
                        ;
                    else while (temp->next != NULL)
                    {
                        if (!(temp->x == x1 && temp->y == y1))
                            temp = temp->next;
                        else break;
                    }
                    int a = temp->y;
                    for (int i = 1; i < a; i++)
                    {
                        Cell* temp1 = *(cellList.head_ref);
                        if (slotIsOccupied(temp->x, temp->y - 1))
                        {
                            if (temp->x == temp->x && temp->y == y1 - 1);
                            else while (temp1->next)
                            {
                                if (!(temp1->x == temp->x && temp1->y == temp->y - 1))
                                    temp1 = temp1->next;
                                else break;
                            }
                        }

                        if (!slotIsOccupied(temp->x, temp->y - 1))
                            temp->y--;
                        else if (slotIsOccupied(temp->x, temp->y - 1) && temp->value == temp1->value)
                        {
                            temp->x = temp1->x;
                            temp->y = temp1->y;
                            cellList.mergeCell(temp, temp1);
                            break;
                        }
                    }
                    temp = *(cellList.head_ref);
                }
            }
        }
        break;
    case RIGHT:
        for (int x1 = 1; x1 <= 4; x1++)
        {
            for (int y1 = 3; y1 >= 1; y1++)
            {
                if (slotIsOccupied(x1, y1))
                {
                    if (temp->x == x1 && temp->y == y1)
                        ;
                    else while (temp->next != NULL)
                    {
                        if (!(temp->x == x1 && temp->y == y1))
                            temp = temp->next;
                        else break;
                    }
                    int a = temp->y;
                    for (int i = 1; i < (4 - a); i++)
                    {
                        Cell* temp1 = *(cellList.head_ref);
                        if (slotIsOccupied(temp->x, temp->y + 1))
                        {
                            if (temp->x == temp->x && temp->y == y1 + 1);
                            else while (temp1->next)
                            {
                                if (!(temp1->x == temp->x&& temp1->y == temp->y + 1))
                                    temp1 = temp1->next;
                                else break;
                            }
                        }

                        if (!slotIsOccupied(temp->x, temp->y + 1))
                            temp->x--;
                        else if (slotIsOccupied(temp->x, temp->y + 1) && temp->value == temp1->value)
                        {
                            temp->x = temp1->x;
                            temp->y = temp1->y;
                            cellList.mergeCell(temp, temp1);
                            break;
                        }
                    }
                    temp = *(cellList.head_ref);
                }
            }
        }
    }
    cellList.allowMerge();
}

void Field::scanInteraction(char s)
{
    cin >> s;
    switch (s)
    {
    case 'a': case 'A':
        cellMove(LEFT);
        break;
    case 'w': case 'W':
        cellMove(UP);
        break;
    case 's': case 'S':
        cellMove(DOWN);
        break;;
    case 'd': case 'D':
        cellMove(RIGHT);
        break;
    default:
        scanInteraction(s);
    }
}

bool Field::ifCellsAreImmovable()
{
    if (cellList.countCell() == 16)
    {
        Cell* temp, *temp1, *temp2;
        for (int x1 = 1; x1 < 4; x1++)
        {
            temp2 = temp1 = temp = *(cellList.head_ref);
            if (y1 != 4)
            {
                if (temp->x == x1 && temp->y == y1);
                else while (temp->next)
                {
                    if (!(temp->x == temp->x && temp->y == temp->y))
                        temp = temp->next;
                    else break;
                }
                
                if (temp1->x == x1 && temp1->y == y1 + 1);
                else while (temp1->next)
                {
                    if (!(temp1->x == x1 && temp1->y == y1 + 1))
                        temp1 = temp1->next;
                    else break;
                }

                if (temp2->x == x1 + 1 && temp2->y == y1);
                else while (temp2->next)
                {
                    if (!(temp2->x == x1 + 1 && temp2->y == y1))
                        temp2 = temp2->next;
                    else break;
                }

                if (temp->value == temp1->value || temp->value == temp2->value)
                    return true;
            }
            else if (y1 == 4)
            {
                if (temp->x == x1 && temp->y == y1);
                else while (temp->next)
                {
                    if (!(temp->x == temp->x && temp->y == temp->y))
                        temp = temp->next;
                    else break;
                }
                
                if (temp1->x == x1 + 1 && temp1->y == y1);
                else while (temp1->next != NULL)
                {
                    if (!(temp1->x == x1 + 1 && temp1->y == y1))
                        temp1 = temp1->next;
                    else break;
                }
                if (temp->value == temp1->value)
                    return true;
            }
        }
    }
    return false;
}

void Field::printYOULOSE(bool check)
{
    if (check)
    {
        cout << "0       0     000     0      0      0           000      0000    00000000\n";
        cout << " 0     0    0     0   0      0      0         0     0   0    0   0\n";
        cout << "  0   0    0       0  0      0      0        0       0  0        0\n";
        cout << "   0 0     0       0  0      0      0        0       0   0000    00000000\n";
        cout << "    0      0       0  0      0      0        0       0       0   0\n";
        cout << "    0      0       0  0      0      0        0       0        0  0\n";
        cout << "    0       0     0    0    0       0         0     0   0    0   0\n";
        cout << "    0         000       0000        00000000    000      0000    00000000\n";
    }
}