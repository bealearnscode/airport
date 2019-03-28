/*

Write a program (airport.cpp) that uses a structure to store the following information for a particular month at the local airport. 
Total number of planes that landed
Total number of planes that departed
Greatest number of planes that landed in a given day that month
Least number of planes that landed in a given day that month
This program should have an array of twelve structures to hold travel information for the entire year. The program should prompt the user to enter data for each month. Once all data is entered, the program should calculate and output the average month number of landing planes, the average monthly number of departing planes, the total number of landing and departing planes for the year, and the greatest and least number of planes that landed on any one day (and which month it occurred in).

*/

// Beatrix House
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct month
{
    int landed, departed, greatestNumOfPlanesLanded, lowestNumOfPlanesLanded;
};

int main ()
{
    month monthsOfYear[12];
    
    string months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    
    int count = 0;
    
    cout << "Please enter the data for each month " << endl << endl;
    
    do
    {
        cout << "Please enter total number of planes landed in " << months[count] << ": ";
        
        cin >> monthsOfYear[count].landed;
        
		cout << "Please enter total number of planes departed in " << months[count] << ": ";
		
		cin >> monthsOfYear[count].departed;
		
		cout << "Please enter greatest number of planes landed in a single day in " << months[count] << ": ";
		
		cin >> monthsOfYear[count].greatestNumOfPlanesLanded;
		
		cout << "Please enter least number of planes landed in a single day in " << months[count] << ": ";
		cin >> monthsOfYear[count].lowestNumOfPlanesLanded;
		cout << endl << endl;
		count++;
	} while (count < 12);

	int averageLanding = 0;
	int averageDeparture = 0;
	int totalForYear = 0;
	int totalDeparturesForYear = 0;
	int max = monthsOfYear[0].greatestNumOfPlanesLanded;
	int min = monthsOfYear[0].lowestNumOfPlanesLanded;
	int maxMonth = 0;
	int minMonth = 0;

    for (int i = 0; i < 12; i++)
	{
		averageLanding += monthsOfYear[i].landed;
		averageDeparture += monthsOfYear[i].departed;
		totalForYear += monthsOfYear[i].landed;
		totalDeparturesForYear += monthsOfYear[i].departed;

		if (monthsOfYear[i].greatestNumOfPlanesLanded > max)
		{
			max = monthsOfYear[i].greatestNumOfPlanesLanded;
			maxMonth = i;
		}
		
		if (monthsOfYear[i].lowestNumOfPlanesLanded < min)
		{
			min = monthsOfYear[i].lowestNumOfPlanesLanded;
			minMonth = i;
		}
	}
	cout << "Average monthly landings for the year: " << (averageLanding / 12);
	cout << "\nAverage monthly departures for the year: " << averageDeparture / 12;
	cout << "\nTotal monthly landings for the year: " << totalForYear;
	cout << "\nTotal monthly deparures for the year: " << totalDeparturesForYear << endl << endl;

	cout << "The greatest number of planes to land in a single day is: " << max << endl
		<< "which occured in " << months[maxMonth] << endl;
	cout << "The least number of planes to land in a single day is: " << min << endl
		<< "which occured in " << months[minMonth] << endl << endl;

	system("pause");
	return 0;
}

    