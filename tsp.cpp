#include <iostream> //input/output
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath> //sqrt, round

struct City{
	int cityNum;
	int xcoord;
	int ycoord;
};

/***********************************************************************
* Name: printCities
* Parameters: This function takes a vector of City structs as a parameter.
* Description: This function prints the vector of cities to the screen
* to help with debugging.
************************************************************************/
void printCities(std::vector<City> cities){
	while (!cities.empty()){
		City c1 = cities.back();
		std::cout << c1.cityNum << " (" << c1.xcoord << "," << c1.ycoord 
				<< ")" << std::endl;
		cities.pop_back();
	}

	return;
}

/***********************************************************************
* Name: distance
* Parameters: x1, y1, x2, y2 coordinates for two points
* Description: This function calculates the distance between two points
* using the distance formula, and returns a rounded integer value for
* the distance calculated.
***********************************************************************/
int distance(int x1, int y1, int x2, int y2){
	int xdist = x1 - x2;
	int ydist = y1 - y2;
	double dist = sqrt(xdist * xdist + ydist * ydist);
	return round(dist);
}

/***********************************************************************
* Name: calcD
* Parameters: vector of City structs, cityNum1, cityNum2
* Description: This function calculates the distance between two cities
* in a list of cities by calling the distance formula.
***********************************************************************/
int calcD(std::vector<City> cities, int cityNum1, int cityNum2) {
	City c1, c2;
	c1.cityNum = cityNum1;
	c2.cityNum = cityNum2;

	// Find cityNum1 in list
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i].cityNum == c1.cityNum)
			c1 = cities[i];
	}

	// Find cityNum2 in list
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i].cityNum == c2.cityNum)
			c2 = cities[i];
	}

	// Calculate distance between cityNum1 and cityNum2
	return distance(c1.xcoord, c1.ycoord, c2.xcoord, c2.ycoord);
}

/***********************************************************************
* Name: calcTSP
* Parameters: 
* Description: This function uses the 2opt approximation algorithm for
* the Traveling Salesman Problem to calculate a near-optimal tour.
***********************************************************************/
int calcTSP(std::vector<City> cities, std::vector<City> tour){




	return 0;
}

int main(void){ //TRACI--replace later with int main(int argc, char** argv) for command line input

	//create input file and open it
	std::ifstream inputFile;
	inputFile.open("tsp_example_1.txt"); //TRACI--change the parameter to argv[1] later for command line input
	
	//create a vector of Cities
	std::vector<City> cities;

	//read in city data
	std::string line;
	while (std::getline(inputFile, line)){
		
		std::istringstream inputstream(line);

		City c;
		inputstream >> c.cityNum;
		inputstream >> c.xcoord;
		inputstream >> c.ycoord;

		cities.push_back(c);
	}

	/*Code to test distance formula calculation.
	int x1 = 0;
	int y1 = 0;
	int x2 = 1;
	int y2 = 3;
	int x3 = 6;
	int y3 = 0;
	int dist = distance(x1, y1, x2, y2);
	std::cout << "Distance btw 1 and 2 is " << dist << std::endl;
	dist = distance(x2, y2, x3, y3);
	std::cout << "Distance btw 2 and 3 is " << dist << std::endl;
	dist = distance(x3, y3, x1, y1);
	std::cout << "Distance btw 3 and 1 is " << dist << std::endl;
	*/

	/*Code to test calcD formaula calculation.
	std::cout << "Distance btw 0 and 1 is " << calcD(cities, 0, 1) << std::endl;
	std::cout << "Distance btw 1 and 2 is " << calcD(cities, 1, 2) << std::endl;
	std::cout << "Distance btw 2 and 3 is " << calcD(cities, 2, 3) << std::endl;	
	*/
	
	inputFile.close();

	return 0;
}
