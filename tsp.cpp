#include <iostream> //input/output
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath> //sqrt, round

struct City{
	int cityNum;
	int xcoord;
	int ycoord;
	bool visited = false;
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
* Name: greedyTSP
* Parameters: a vector of cities, an integer for the number of cities in
* the vector, and a second vector of cities to keep track of the tour
* Description: This function uses the greedy algorithm for
* the Traveling Salesman Problem to calculate a tour.
***********************************************************************/
int greedyTSP(std::vector<City> cities, int numOfCities, std::vector<City> &tour){

	int tourDistance = 0;

	//select a city to begin with
	City *currentCity = &cities[0];
	tour.push_back(*currentCity);

	bool allCitiesVisited;
	City *closestCity = NULL;

	do{
		//std::cout << "currentCity:  " << currentCity->cityNum << std::endl;
		int closestDistance = INT_MAX;
		currentCity->visited = true;
		allCitiesVisited = true;

		//check each city
		for (int i = 0; i < numOfCities; i++){
			//if city has not yet been visited
			if (!cities[i].visited){
				allCitiesVisited = false;

				//calculate and find the city with the shortest distance to the current city
				int dist = distance(currentCity->xcoord, currentCity->ycoord, cities[i].xcoord, cities[i].ycoord);
				//std::cout << "distance between " << currentCity->cityNum << " and " << cities[i].cityNum << ": " << dist << std::endl;

				//check to see if this city is closer than the other cities checked so far
				if (dist < closestDistance){
					closestDistance = dist;
					closestCity = &cities[i];
				}
			}
			/*else {
				std::cout << "skipping " << cities[i].cityNum << std::endl;
			}*/
		}
		
		if (!allCitiesVisited) {
			//std::cout << "Next City on Tour " << closestCity->cityNum << std::endl;
			tour.push_back(*closestCity);
			currentCity = closestCity;
			tourDistance += closestDistance;
		}
		//std::cout << std::endl;

	} while (!allCitiesVisited);

	//go back to first city      
	tourDistance += distance(tour[0].xcoord, tour[0].ycoord, tour.back().xcoord, tour.back().ycoord);
	tour.push_back(tour[0]);

	return tourDistance;
}

int main(void){ //TRACI--replace later with int main(int argc, char** argv) for command line input

	//create input file and open it
	std::ifstream inputFile;
	//inputFile.open("tsp_example_3.txt"); //TRACI--change the parameter to argv[1] later for command line input
	inputFile.open("tsp_example_1.txt");
	//inputFile.open("tsp_example_2.txt");
	
	//create a vector of Cities
	std::vector<City> cities;
	int numOfCities = 0;

	//read in city data
	std::string line;
	while (std::getline(inputFile, line)){
		
		std::istringstream inputstream(line);

		City c;
		inputstream >> c.cityNum;
		inputstream >> c.xcoord;
		inputstream >> c.ycoord;

		cities.push_back(c);

		numOfCities++;
	}

	//create a vector to hold the completed tour
	std::vector<City> tour;

	//call TSP function
	int finalTourDist = greedyTSP(cities, numOfCities, tour);

	std::cout << "The tour distance is " << finalTourDist << std::endl;
	

	inputFile.close();

	return 0;
}