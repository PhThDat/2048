#include <iostream>
#include "cell.h"
#include "field.h"
#include <vector>

using namespace std;

int main()
{
    Field f;
    char s = 'i';
    while (s != 'e')
    {
        f.newCell();
        f.renderField();
        f.scanInteraction(s);
        f.printYOULOSE(f.ifCellsAreImmovable());
    }
    return 0;
}