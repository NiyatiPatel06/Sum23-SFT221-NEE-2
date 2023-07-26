#include <ctype.h>
#include <string.h>
#include "Test.h"
#include "mapping.h"
#include <math.h>

double returnDistance(const int loc1[2], const int loc2[2], double* minDest)
{
	if (loc1 == NULL || loc2 == NULL || minDest == NULL) {
		return -1; // Return the error code for null pointers
	}
	double calcValue = sqrt(pow((loc1[0] - loc2[0]), 2) + pow((loc1[1] - loc2[1]), 2));

	if (calcValue < *minDest)
	{
		*minDest = calcValue;
	}

	return calcValue;
}
int checkEmpty(const double weight, double weightLeft, int volumeLeft)
{
	int i = 0;

	if (weight <= weightLeft && volumeLeft > 0)
	{
		i = 1;
	}

	return i;
}
int checkSize(const double size)
{
	int i = 0;

	if (size == QUARTER_SIZE || size == HALF_SIZE || size == FULL_SIZE)
	{
		i = 1;
	}

	return i;
}

/*int validDestination(const int row, const char column)*/
int validDestination(const int row, const char* column)
{
	int i = 0; // 0 == false

	if (column != NULL && strlen(column) == 1) {

		if (row > 0 && row < 26)
		{
			// Convert the column to uppercase
			char upperColumn = toupper(column[0]); // Use column[0] to access the first character

			if (upperColumn >= 'A' && upperColumn <= 'Y')
			{
				i = 1; // 1 == true
			}
		}

	}
	return i;
}


