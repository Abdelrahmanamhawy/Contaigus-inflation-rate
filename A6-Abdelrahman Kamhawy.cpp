// A6-Abdelrahman Kamhawy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "minPQ.cpp"
#include "maxPQ.cpp"
using namespace std;


int main()
{
	int  n = 102;
	string test = "Hello";
	double number= 10.0;
	double number2 = 0.0;
	

	minPQ<double, string>  m(n,test,number);
	maxPQ<double, string> ma(n, test, number2);

	ifstream file("USD-EGP.csv");
	string t = " ";
	string date = " ";
	string p = " ";
	double price = 0.0;
	const int N = 10;
    int i = 0;
	int l = 9;
	
	
	//1-Extracting dateset from the file to the queues.
	if (!file.fail()) {
		while (getline(file, t, '\n')) {

			
			date = t.substr(0, 9);
			t.erase(0, 9);
			price = std::stod(t);
			i++;

		 m.insert(price, date);                      //Minemum Queue.
		 ma.insert(price, date);                    //Maxmium Queue

		}
	}
	
	//2-Find the N lowest and highest exchange prices.
	int num = 0;
	cout << "Enter the number of N to find the Highest and lowest exchange prices" << endl;
	cin >> num;
	cout << "#########################" << endl;
	for(int i=0;i<num;i++){
		

		cout << "The list of the " << num << "lowest elements" << endl;
		cout << m.Remove() << endl;

	}
	cout << "#########################" << endl;

	for (int j = 0;j<num;j++) {


		cout << "The list of the " << num << "highest elements" << endl;
		cout << ma.Remove() << endl;

	}
	cout << "#########################" << endl;
	cout << endl;


	//End of 2nd question.


	/*
	3-Sum of the most contaigus period .("Maximum Subarray Sum")
	Approach taken to solve the question to avoid any confusion:
	.Divide the given array in two halves
	.Return the maximum of following three
	….a) Maximum subarray sum in left half(Make a recursive call)
		….b) Maximum subarray sum in right half(Make a recursive call)
		….c) Maximum subarray sum such that the subarray crosses the midpo
		*/
	cout << "The largest sum for the contagius period is " << setw(2) << m.maxSub(0, n - 1) << endl;
	system("pause");
    return 0;
}

