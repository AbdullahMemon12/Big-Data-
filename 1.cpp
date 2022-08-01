#include<iostream>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream input("Sampled_Data.csv");
	ofstream output("Filtered_Data.csv");
	string FlightDate, Reporting_Airline, OriginCityName, DestCityName, DepDelay, ArrDelay, nop;
	char c;
	int i, j;
	for (i = 0; i < 30; i++)
	{
		fflush(stdin);
		getline(input, nop, ',');
	}
	getline(input, nop, '\n');
	while(!input.eof())
	{
		fflush(stdin);
		
		getline(input, FlightDate, ',');
		output<<FlightDate<<',';
		
		getline(input, Reporting_Airline, ',');
		output<<Reporting_Airline<<',';
		
		getline(input, nop, ',');
		
		getline(input, nop, ',');
		
		input >> c;
		getline(input, OriginCityName, ',');
		output<<OriginCityName<<',';
		
		getline(input, nop, ',');
		
		getline(input, nop, ',');
		
		getline(input, nop, ',');
		input >> c;
		
		getline(input, DestCityName, ',');
		output<<DestCityName<<',';
		
		getline(input, nop, ',');
		
		getline(input, nop, ',');
		
		
		getline(input, nop, ',');
		
		
		getline(input, nop, ',');
		
		
		getline(input, DepDelay, ',');
		output<<DepDelay<<',';
		
		getline(input, nop, ',');
		
		getline(input, nop, ',');
		
		getline(input, nop, ',');
		
		getline(input, nop, ',');
		
		getline(input, ArrDelay, ',');
		output<<ArrDelay<<',';
		for (i = 0; i < 13; i++)
		{
			getline(input, nop, ',');
		}
		getline(input, nop, '\n');
		output<<'\n';
	}
	
	return 0;
}
