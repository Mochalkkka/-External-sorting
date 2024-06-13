#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class ExperimentFunctions
{
public:
	void graphic_division()
	{
		cout << endl;
		string line(120, '-');
		cout << line << endl;
	}

	bool file_sorted_1(const string& filename);

	void generate_random(const string& filename, int n);
	void almost_sorted_dataset(const string& filename, int n);
	void duplicate_dataset(const string& filename, int n);
	void worst_case_data(const string& filename, int n);
	void best_case_data(const string& filename, int n);
	void element_repeated_10_times_dataset(const string& filename, int n);
	void dataset_alternating_values(const string& filename, int n);

	void experiment_1_random_data();
	void experiment_2_almost_sorted_dataset();
	void experiment_3_duplicate_dataset();
	void experiment_4_worst_case_data();
	void experiment_5_best_case_data();
	void experiment_6_element_repeated_10_times_dataset();
	void experiment_7_element_dataset_alternating_values();

};

