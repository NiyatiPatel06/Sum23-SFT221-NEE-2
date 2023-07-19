#ifndef SDDS_TEST_H
#define SDDS_TEST_H

#define MAX_WEIGHT 1000
#define MAX_VOLUME 36
#define QUARTER_SIZE 0.25
#define HALF_SIZE 0.5
#define FULL_SIZE 1.0


struct TruckTest {
	int volumeLeft; ////will be set to 36 at first
	double weightLeft; //will be set to 1000 at first
	struct Route route;
};

struct Shipment {
	double weight;
	double box; // 1/4 or 1/2 or 1 cubic meter
	int row; // 1 to 25
	char column; // A to Y
};

/*Finds the best truck for a shipment. 
It considers both the load on the truck, the size and weight of the shipment, 
and the route of the truck to try to place it on a truck that goes closest to the destination. 
If there is no truck that can deliver the shipment, it returns – 1.*/
int truckIndex findTruckForShipment(struct Map map, struct TruckDetail trucks[], int numTrucks, struct Shipment shipment);

/*The purpose of this function is to find a truck that is big enough to hold the shipment.
A truck is full when it hits either its maximum weight or maximum volume – whichever is reached first.
For example, if a truck already has 900 kilograms in it but only has 10 cubic meters of boxes. 
then the limiting factor must be taken as the weight. If another truck has 30 cubic meters of boxes 
but only 200 kilograms of cargo, then you must assume that it is limited in space rather than weight. 
When you compare two trucks to see which one has the most space remaining, we should look at the limiting factor for each truck as a percentage and compare the percentages.
If the limiting factor is greater than the volume or weight left for the truck, the function will return 1; otherwise, it will return 0. Additionally, if it returns 1, the function will subtract the weight from weightLeft and decrease the value of volumeLeft of the truck.
*/
int checkTruckIsEmpty(const double weight, int volume, struct TruckDetail truck);

/*The purpose of this function is to determine whether the provided size 
is equal to 1/4, 1/2, or 1. If it matches any of these values, 
the function will return 1, indicating true. Otherwise, it will return 0,
indicating false.*/
int checkSize(const double size);

/*The purpose of this function is to verify if the given row falls within 
the range of 1 to 25 and if the column is within the range of A to Y. 
If both conditions are satisfied, the function will return 1. 
Otherwise it will return 0.*/
int validDestination(const int row, const char column);

#endif // !SDDS_TEST_H