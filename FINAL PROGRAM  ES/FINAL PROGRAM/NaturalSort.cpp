#define _CRT_SECURE_NO_WARNINGS
#include "NaturalSort.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <stdio.h>
using namespace std;
using namespace std::chrono;

bool NaturalSort::End_Range(FILE* f) {
    int tmp = fgetc(f);
    tmp = fgetc(f);
    if (tmp != '\'') {
        comparisons_elements++;
        all_comparisons++;
        fseek(f, -2, SEEK_CUR);
    }
    else {
        comparisons_elements++;
        all_comparisons++;
        fseek(f, 1, SEEK_CUR);

    }
    return tmp == '\'';
}

void NaturalSort::Split_File(const char* name, int& count_elements_file_1, int& count_elements_file_2) {
    FILE* f = fopen(name, "r");
    FILE* f1 = fopen("nmsort_1", "w");
    FILE* f2 = fopen("nmsort_2", "w");
    io_operations += 3;

    int element1, element2, mark = 1;
    count_elements_file_1 = count_elements_file_2 = 0;

    fscanf(f, "%d", &element1);
    io_operations ++;
    if (!feof(f)) {
        fprintf(f1, "%d ", element1);
        io_operations++;
        count_elements_file_1++;
    }
    if (!feof(f)) {
        fscanf(f, "%d", &element2);
        io_operations++;
    }

    while (!feof(f)) {
        if (element2 < element1) {
            comparisons_elements++;
            all_comparisons++;
            if (mark == 1) {
                all_comparisons++;
                fprintf(f1, "' ");
                io_operations++;
                mark = 2;
                count_elements_file_1++;
            }
            else {
                all_comparisons++;
                fprintf(f2, "' ");
                io_operations++;
                mark = 1;
                count_elements_file_2++;
            }
        }
        if (mark == 1) {
            all_comparisons++;
            fprintf(f1, "%d ", element2);
            io_operations++;
            count_elements_file_1++;
        }
        else {
            all_comparisons++;
            fprintf(f2, "%d ", element2);
            io_operations++;
            count_elements_file_2++;
        }
        element1 = element2;
        fscanf(f, "%d", &element2);
        io_operations++;
    }

    if (count_elements_file_2 > 0 && mark == 2) {
        fprintf(f2, "'");
        all_comparisons+=2;
        io_operations++;
    }
    if (count_elements_file_1 > 0 && mark == 1) {
        fprintf(f1, "'");
        all_comparisons += 2;
        io_operations++;
    }

    fclose(f);
    fclose(f1);
    fclose(f2);
}

void NaturalSort::Merge_Files(const char* name) {
    FILE* f = fopen(name, "w");
    FILE* f1 = fopen("nmsort_1", "r");
    FILE* f2 = fopen("nmsort_2", "r");
    io_operations+=3;

    int element1, element2;
    fscanf(f1, "%d", &element1);
    io_operations++;
    fscanf(f2, "%d", &element2);
    io_operations++;

    bool file1 = false, file2 = false;

    while (!feof(f1) && !feof(f2)) {
        file1 = file2 = false;
        while (!file1 && !file2) {
            if (element1 <= element2) {
                comparisons_elements++;
                all_comparisons ++;
                fprintf(f, "%d ", element1);
                io_operations++;
                file1 = End_Range(f1);
                fscanf(f1, "%d", &element1);
                io_operations++;
            }
            else {
                comparisons_elements++;
                all_comparisons++;
                fprintf(f, "%d ", element2);
                io_operations++;
                file2 = End_Range(f2);
                fscanf(f2, "%d", &element2);
                io_operations++;
            }
        }
        while (!file1) {
            fprintf(f, "%d ", element1);
            io_operations++;
            file1 = End_Range(f1);
            fscanf(f1, "%d", &element1);
            io_operations++;
        }
        while (!file2) {
            fprintf(f, "%d ", element2);
            file2 = End_Range(f2);
            fscanf(f2, "%d", &element2);
            io_operations += 2;
        }
    }
    while (!file1 && !feof(f1)) {
        fprintf(f, "%d ", element1);
        file1 = End_Range(f1);
        fscanf(f1, "%d", &element1);
        io_operations += 2;
    }
    while (!file2 && !feof(f2)) {
        fprintf(f, "%d ", element2);
        file2 = End_Range(f2);
        fscanf(f2, "%d", &element2);
        io_operations += 2;
    }

    fclose(f);
    fclose(f1);
    fclose(f2);
}

void NaturalSort::Natural_Merging_Sort(const char* name) {
    int count_elements_file_1, count_elements_file_2;
    count_elements_file_1 = count_elements_file_2 = 1;

    while (count_elements_file_1 > 0 && count_elements_file_2 > 0) {
        all_comparisons++;
        Split_File(name, count_elements_file_1, count_elements_file_2);
        Merge_Files(name);
    }

    remove("nmsort_1");
    remove("nmsort_2");
}

