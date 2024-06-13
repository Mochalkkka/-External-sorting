#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class TestFunctions
{
public:
	bool file_sorted(const string& filename);

	//Функции, генерирующие наборы данных в файл
	void generate_random_data_500_elements(const string& filename);//1
	void generate_almost_sorted_data_500_elements(const string& filename);//2
	void generate_data_with_duplicates_200_elements(const string& filename);//3
	void generate_data_with_negatives_100_elements(const string& filename);//4
	void generate_reverse_order_data_100_elements(const string& filename);//5
	void generate_large_range_data_100_elements(const string& filename);//6
	void generate_identical_elements_data_50_elements(const string& filename);//7
	void generate_zeros_and_positives_data_100_elements(const string& filename);//8
	void generate_zeros_and_negatives_data_100_elements(const string& filename);//9
	void generate_alternating_values_data_50_elements(const string& filename);//10
	void generate_alternating_positive_negative_data_100_elements(const string& filename);//11
	void generate_large_numbers_data_50_elements(const string& filename);//12
	void generate_large_data_set_10000_elements(const string& filename);//13
	void generate_single_element_data(const string& filename);//14

	void graphic_division()
	{
		cout << endl;
		string line(150, '-');
		cout << line << endl;
	}

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

	//Тестирование простой сортировки
	void test_1_simple_sort_generate_random_data_500_elements();
	void test_2_simple_sort_generate_almost_sorted_data_500_elements();
	void test_3_simple_sort_generate_data_with_duplicates_200_elements();
	void test_4_simple_sort_generate_data_with_negatives_100_elements();
	void test_5_simple_sort_generate_reverse_order_data_100_elements();
	void test_6_simple_sort_generate_large_range_data_100_elements();
	void test_7_simple_sort_generate_identical_elements_data_50_elements();
	void test_8_simple_sort_generate_zeros_and_positives_data_100_elements();
	void test_9_simple_sort_generate_zeros_and_negatives_data_100_elements();
	void test_10_simple_sort_generate_alternating_values_data_50_elements();
	void test_11_simple_sort_generate_alternating_positive_negative_data_100_elements();
	void test_12_simple_sort_generate_large_numbers_data_50_elements();
	void test_13_simple_sort_generate_large_data_set_10000_elements();
	void test_14_simple_sort_generate_single_element_data();

	//Тестирование естественной сортировки
	void test_1_natural_sort_generate_random_data_500_elements();
	void test_2_natural_sort_generate_almost_sorted_data_500_elements();
	void test_3_natural_sort_generate_data_with_duplicates_200_elements();
	void test_4_natural_sort_generate_data_with_negatives_100_elements();
	void test_5_natural_sort_generate_reverse_order_data_100_elements();
	void test_6_natural_sort_generate_large_range_data_100_elements();
	void test_7_natural_sort_generate_identical_elements_data_50_elements();
	void test_8_natural_sort_generate_zeros_and_positives_data_100_elements();
	void test_9_natural_sort_generate_zeros_and_negatives_data_100_elements();
	void test_10_natural_sort_generate_alternating_values_data_50_elements();
	void test_11_natural_sort_generate_alternating_positive_negative_data_100_elements();
	void test_12_natural_sort_generate_large_numbers_data_50_elements();
	void test_13_natural_sort_generate_large_data_set_10000_elements();
	void test_14_natural_sort_generate_single_element_data();

};

