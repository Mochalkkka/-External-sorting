#include "Programm.h"
#include "TestFunctions.h"
#include "SimpleSort.h"
#include "NaturalSort.h"
#include "ExperimentFunctions.h"
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

void Programm::graphic_division()
{
	cout << endl;
	string line(150, '-');
	cout << line << endl;
}

bool Programm::file_sorted(const string& filename) {

	ifstream file(filename);

	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return false;
	}

	int prev = numeric_limits<int>::min();
	string line;

	while (getline(file, line)) {
		istringstream iss(line);
		int num;
		while (iss >> num) {
			if (num < prev) {
				cout << "Файл не отсортирован";
				return false;
			}
			prev = num;
		}
	}

	cout << "Файл отсортирован";
	file.close();
	return true;
}

void Programm::full_testing_simple_sort()
{
	TestFunctions test;
	cout << "\tТестирование алгоритма простого слияния\t";
	graphic_division();

	test.test_1_simple_sort_generate_random_data_500_elements();
	test.test_2_simple_sort_generate_almost_sorted_data_500_elements();
	test.test_3_simple_sort_generate_data_with_duplicates_200_elements();
	test.test_4_simple_sort_generate_data_with_negatives_100_elements();
	test.test_5_simple_sort_generate_reverse_order_data_100_elements();
	test.test_6_simple_sort_generate_large_range_data_100_elements();
	test.test_7_simple_sort_generate_identical_elements_data_50_elements();
	test.test_8_simple_sort_generate_zeros_and_positives_data_100_elements();
	test.test_9_simple_sort_generate_zeros_and_negatives_data_100_elements();
	test.test_10_simple_sort_generate_alternating_values_data_50_elements();
	test.test_11_simple_sort_generate_alternating_positive_negative_data_100_elements();
	test.test_12_simple_sort_generate_large_numbers_data_50_elements();
	test.test_13_simple_sort_generate_large_data_set_10000_elements();
	test.test_14_simple_sort_generate_single_element_data();
}

void Programm::full_testing_natural_sort()
{
	TestFunctions test;
	cout << "\tТестирование алгоритма естественного слияния\t";
	graphic_division();

	test.test_1_natural_sort_generate_random_data_500_elements();
	test.test_2_natural_sort_generate_almost_sorted_data_500_elements();
	test.test_3_natural_sort_generate_data_with_duplicates_200_elements();
	test.test_4_natural_sort_generate_data_with_negatives_100_elements();
	test.test_5_natural_sort_generate_reverse_order_data_100_elements();
	test.test_6_natural_sort_generate_large_range_data_100_elements();
	test.test_7_natural_sort_generate_identical_elements_data_50_elements();
	test.test_8_natural_sort_generate_zeros_and_positives_data_100_elements();
	test.test_9_natural_sort_generate_zeros_and_negatives_data_100_elements();
	test.test_10_natural_sort_generate_alternating_values_data_50_elements();
	test.test_11_natural_sort_generate_alternating_positive_negative_data_100_elements();
	test.test_12_natural_sort_generate_large_numbers_data_50_elements();
	test.test_13_natural_sort_generate_large_data_set_10000_elements();
	test.test_14_natural_sort_generate_single_element_data();
}

void Programm::experiment()
{

	graphic_division();

	ExperimentFunctions f;
	f.experiment_1_random_data();
	graphic_division();
	f.experiment_2_almost_sorted_dataset();
	graphic_division();
	f.experiment_3_duplicate_dataset();
	graphic_division();
	f.experiment_4_worst_case_data();
	graphic_division();
	f.experiment_5_best_case_data();
	graphic_division();
	f.experiment_6_element_repeated_10_times_dataset();
	graphic_division();
	f.experiment_7_element_dataset_alternating_values();
}

