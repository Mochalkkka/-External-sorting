#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class NaturalSort
{
private:
	bool End_Range(FILE* f);
	void Split_File(const char* name, int& count_elements_file_1, int& count_elements_file_2);
	void Merge_Files(const char* name);
public:
	void Natural_Merging_Sort(const char* name);
	int io_operations = 0;
	int all_comparisons = 0;
	int comparisons_elements = 0;
	

};

