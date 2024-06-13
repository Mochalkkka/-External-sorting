#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class SimpleSort
{
private:
	int Count_Numbers(const char* name);
	void Split_File(const char* name, int k);
	void Merge_Files(const char* name, int k);
	
public:
	void Simple_Merging_Sort(const char* name);
	int io_operations = 0;
	int all_comparisons = 0;
	int comparisons_elements = 0;
};

