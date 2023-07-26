#ifndef TEST_H


#define TEST_H

#define MAX_WEIGHT 1000
#define MAX_VOLUME 36
#define QUARTER_SIZE 0.25
#define HALF_SIZE 0.5
#define FULL_SIZE 1.0

struct RouteTest {
	double minDestination;
	char* bestRoute;
};

struct TruckTest {
	int volumeLeft; ////will be set to 36 at first
	double weightLeft; //will be set to 1000 at first
};

struct Shipment {
	double weight;
	double box; // 1/4 or 1/2 or 1 cubic meter
	int row; // 1 to 25
	char column; // A to Y
};

/*This function calculates and returns the distance between two locations. 
If the calculated distance is smaller than the current minimum destination, 
it updates the minimum destination value to the newly calculated value.*/
double returnDistance(const int loc1[2], const int loc[2], double* minDest);

/*The purpose of this function is to determine whether the given weight is
less than or equal to weightLeft, while also checking if volumeLeft is 
greater than zero. If both conditions are true, the function will return 1; 
otherwise, it will return 0. Additionally, if the conditions are true, the function 
will subtract the weight from weightLeft and decrease the value of volumeLeft.*/
int checkEmpty(const double weight, double weightLeft, int volumeLeft);

/*The purpose of this function is to determine whether the provided size 
is equal to 1/4, 1/2, or 1. If it matches any of these values, 
the function will return 1, indicating true. Otherwise, it will return 0,
indicating false.*/
int checkSize(const double size);

/*The purpose of this function is to verify if the given row falls within 
the range of 1 to 25 and if the column is within the range of A to Y. 
If both conditions are satisfied, the function will return 1. 
Otherwise it will return 0.*/
int validDestination(const int row, const char* column);


#endif // !TEST_H