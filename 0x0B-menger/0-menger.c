#include "menger.h"

/**
 * menger - draws 2 dimensional menger
 * @level: menger square
 */
void menger(int level)
{
	int num, row, col, tmpRow, tmpCol, cr;

	num = pow(3, level);
	for (row = 0; row < num; row++)
	{
		for (col = 0; col < num; col++)
		{
			tmpRow = row;
			tmpCol = col;
			cr = '#';
			while (tmpRow || tmpCol)
			{
				if (tmpRow % 3 == 1 && tmpCol % 3 == 1)
					cr = ' ';
				tmpRow /= 3;
				tmpCol /= 3;
			}
			putchar(cr);
		}
		putchar('\n');
	}
}
