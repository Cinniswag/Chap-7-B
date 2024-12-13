// Chap 7 B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int const students = 5;
int const tests = 4;
string classlist[students];
double scores[students][tests];
double averages[students];
char grades[students];

int main()
{
	// inputting name
	for (int index1 = 0; index1 < students; index1++) {
		cout << "Please enter student name no. " << index1 + 1 << endl;
		cin >> classlist[index1];

		//inputting score
		double stotal = 0;
		double low = 101;

		for (int index2 = 0; index2 < tests; index2++) {
			double score;
			do {
				cout << "Please enter score no. " << index2 + 1 << endl;
				cin >> score;
				if (score < 0 || score > 100) {
					cout << "INVALID. Nothing lower than 0 or above 100." << endl;
				}
			} while (score < 0 || score > 100);
			scores[index1][index2] = score;
			stotal += score;
			//find lowest score
			if (score < low) {
				low = score;
			}
		}
		//calculations
		double fixscore = stotal - low;
		averages[index1] = fixscore / (tests - 1);

		//grade determining
		if (averages[index1] >= 90) {
			grades[index1] = 'A';
		}
		else if (averages[index1] >= 80) {
			grades[index1] = 'B';
		}
		else if (averages[index1] >= 70) {
			grades[index1] = 'C';
		}
		else if (averages[index1] >= 60) {
			grades[index1] = 'D';
		}
		else {
			grades[index1] = 'F';
		}
	}
	//outputting
	cout << fixed << setprecision(1);
	cout << endl << "Result:" << endl;
	for (int index1 = 0; index1 < students; index1++) {
		cout << classlist[index1] << "'s average: " << averages[index1] << " (" << grades[index1] << ")" << endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
