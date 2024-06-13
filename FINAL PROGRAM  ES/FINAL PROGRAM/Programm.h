#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <stdio.h>
using namespace std;

class Programm
{
private:

	bool file_sorted(const string&);
	void graphic_division();
public:
	void Print_File(const string& name) {
		string line;
		ifstream in(name);
		if (in.is_open()) {
			while (getline(in, line)) {
				cout << line << endl;
			}
		}
		else {
			cout << "Не удалось открыть файл " << name << endl;
		}
	}

	void full_testing_simple_sort();
	void full_testing_natural_sort();
	void experiment();
};

