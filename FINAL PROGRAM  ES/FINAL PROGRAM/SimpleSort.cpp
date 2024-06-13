#include "SimpleSort.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <stdio.h>
using namespace std;
using namespace std::chrono;

void Print_File_1(const string& name) {
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

int SimpleSort::Count_Numbers(const char* name) {
	int kol = 0;
	int element1;
	FILE* f = fopen(name, "r");
	if (f == nullptr) {
		cout << "Не удалось открыть файл " << name << endl;
		return 0;
	}
	while (!feof(f)) {
		if (fscanf(f, "%d", &element1) == 1) {
			all_comparisons++;
			comparisons_elements++;
			kol++;
		}
		else
		{
			all_comparisons++;
		}
	}
	fclose(f);
	return kol;
}

void SimpleSort::Split_File(const char* name, int k) {
	FILE* f = fopen(name, "r");
	FILE* f1 = fopen("smsort_1", "w");
	FILE* f2 = fopen("smsort_2", "w");

	int element1;
	if (!feof(f)) fscanf(f, "%d", &element1);
	while (!feof(f)) {
		for (int i = 0; i < k && !feof(f); i++) {
			all_comparisons++;
			fprintf(f1, "%d ", element1);
			cout <<"1."<< element1 << " ";
			fscanf(f, "%d", &element1); 
			io_operations += 2;

		}
		cout << endl;
		for (int j = 0; j < k && !feof(f); j++) {
			all_comparisons++;
			fprintf(f2, "%d ", element1);
			cout << "2." << element1 << " ";
			fscanf(f, "%d", &element1);
			io_operations += 2;
		}
		cout << endl;
	}

	fclose(f2);
	fclose(f1);
	fclose(f);
}

void SimpleSort::Merge_Files(const char* name, int k) {
	FILE* f = fopen(name, "w");
	FILE* f1 = fopen("smsort_1", "r");
	FILE* f2 = fopen("smsort_2", "r");

	int element1, element2;
	if (!feof(f1)){ 
		fscanf(f1, "%d", &element1);
		io_operations++;
	}
	if (!feof(f2)){
		fscanf(f2, "%d", &element2);
		io_operations++;
	}

	while (!feof(f1) && !feof(f2)) {
		int i = 0, j = 0;
		while (i < k && j < k && !feof(f1) && !feof(f2)) {
			all_comparisons+=2;
			if (element1 < element2) {
				comparisons_elements++;
				all_comparisons++;
				fprintf(f, "%d ", element1);
				fscanf(f1, "%d", &element1);
				io_operations+=2;
				i++;
			}
			else {
				comparisons_elements++;
				all_comparisons++;
				fprintf(f, "%d ", element2);
				fscanf(f2, "%d", &element2);
				io_operations += 2;
				j++;
			}
		}
		while (i < k && !feof(f1)) {
			all_comparisons++;
			fprintf(f, "%d ", element1);
			fscanf(f1, "%d", &element1);
			io_operations += 2;
			i++;
		}
		while (j < k && !feof(f2)) {
			all_comparisons++;
			fprintf(f, "%d ", element2);
			fscanf(f2, "%d", &element2);
			io_operations += 2;
			j++;
		}
	}
	while (!feof(f1)) {
		fprintf(f, "%d ", element1);
		fscanf(f1, "%d", &element1);
		io_operations += 2;
	}
	while (!feof(f2)) {
		fprintf(f, "%d ", element2);
		fscanf(f2, "%d", &element2);
		io_operations += 2;
	}
	fclose(f2);
	fclose(f1);
	fclose(f);
}

void SimpleSort::Simple_Merging_Sort(const char* name) {
	int kol = Count_Numbers(name);
	int k = 1;
	while (k < kol) {
		all_comparisons++;
		Split_File(name, k);

	
		cout << "merge\n";
		Merge_Files(name, k);
		Print_File_1(name);
		cout << "\n";
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
}