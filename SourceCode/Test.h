#ifndef SDDS_TEST_H

#define SDDS_TEST_H


namespace sdds {

	const int MAX_WEIGHT = 1000; 

	const int MAX_VOLUME = 36; 



	struct TruckRoute {

		double minDistance;

		struct Route bestRoute;

	};

	struct TruckCapacity {

		int volumeLeft;

		double weightLeft;

	};

	struct Shipment {


		double weight;

		double box; 

		int row; 

		char column; 

	};

}
#endif�//�!SDDS_TEST_H