// week 6 porgramming assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<iomanip>
#include<fstream>

//using namespace 
using namespace std;

//declare the constants and functions 
const int cols = 5, rows = 10;
bool GetBowlingData(string filename, string names[rows], int scores[rows][cols]);
double* GetAverageScore(int scores[rows][cols]);
void PrettyPrintResults(string names[rows], int scores [rows][cols], double avg[]);

int main()
{
	//filename, rows, and columns
	string filename = "BowlingScores.txt";
	string names[rows];
	int scores[rows][cols];
	double* avg;

	//the precision 
	cout << setprecision(2) << fixed << showpoint;
	if (GetBowlingData(filename, names, scores))
	{
		avg = GetAverageScore(scores);
		PrettyPrintResults(names, scores, avg);
	}
	else
	{
		cout << "** File Not Found **" << endl;
	}
	return 0;
}
bool GetBowlingData(string filename, string names[rows], int scores[rows][cols])
{
	//input stream for the file 
	ifstream dataIn;
	//open the input file 
	dataIn.open(filename.c_str());
	//check the file name 
	if (dataIn.fail())
	{
		cout << "**File Not Found **";
		return false;

	}
	else
	{
		//count the records in file 
		for (int i = 0; i < rows; i++)
		{
			dataIn >> names[i];
			for (int j = 0; j < cols; j++)
			{
				dataIn >> scores[i][j];
			}
		}
		//cose the file 
		dataIn.close();
	}
	return true;
}
double* GetAverageScore(int scores[rows][cols])
{
	double total = 0;
	static double avg[rows];
	for (int i = 0; i < rows; i++)
	{
		total = 0;
		for (int j = 0; j < cols; j++)
		{
			total += scores[i][j];
		}
		avg[i] = total / cols;
	}
	return avg;
}
void PrettyPrintResults(string names[rows], int scores[rows][cols], double avg[])
{
	cout << left << setw(13) <<"Name"<<"Score1\tScore2\tScore3\tScore4\tScore5\tAverage" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << setw(14) << left << names[i];
		for (int j = 0; j < cols; j++) {
			cout << scores[i][j] << "\t";
		}
		cout << setw(5) << *(avg + i) << endl;
	}
}


