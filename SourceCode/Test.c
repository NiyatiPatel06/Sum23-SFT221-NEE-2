#include "test.h"

#include <math.h>



int checkTruckIsEmpty(const double weight, int volume, struct TruckDetail truck)
{
	int result = 0;
	double weightPercentage = weight / MAX_WEIGHT;
	double volumePercentage = volume / double(MAX_VOLUME);

	if (weightPercentage <= 1 && volumePercentage <= 1)
	{ 

		if (weightPercentage >= volumePercentage) {
			if (weight <= truck.weightLeft) {
				truck.weightLeft -= weight;
				result = 1;
			}
		}
		else {
			if (volume <= truck.volumeLeft) {
				truck.volumeLeft -= volume;
				result = 1;
			}
		}
	}
	return result;
}


int checkValidSize(const double size)
{
	int i = 0;
	if (size == QUARTER_SIZE || size == HALF_SIZE || size == FULL_SIZE)
	{
		i = 1;
	}
	return i;
}
int validDestination(const int row, const char column)
{
	int i = 0; //0 == false

	if (row > 0 && row < 26)
	{
		if (column >= 'A' && column <= 'Y')
		{
			i = 1; // 1 == true
		}
	}

	return i;
}

int truckIndex findTruckForShipment(struct Map map, struct TruckDetail trucks[], int numTrucks, struct Shipment shipment)
{

}
