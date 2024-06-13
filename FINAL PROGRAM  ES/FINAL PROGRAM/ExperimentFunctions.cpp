#include "ExperimentFunctions.h"
#include "SimpleSort.h"
#include "NaturalSort.h"
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

void CopyFileContents(const string& filename1, const string& filename2) {
	ifstream sourceFile(filename1);
	ofstream destinationFile(filename2);

	if (sourceFile && destinationFile) {
		destinationFile << sourceFile.rdbuf();
	}
	
}

void ClearFile(const string& filename) {

	ofstream file(filename, ios::trunc);
	if (file.is_open()) {
		file.close();
	}
	else {
		cout << "Не удалось открыть файл " << filename << endl;
	}
}

bool ExperimentFunctions::file_sorted_1(const string& filename)
{
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

void ExperimentFunctions::experiment_1_random_data()
{
	int n = 100;
	int k = 1;

	while (n <= 10000)
	{
		cout << "\n**Измерение критериев качетсва для сортировки простым слиянием**\n";

		graphic_division();
		ExperimentFunctions ex1;
		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";
		ex1.generate_random("experiment_1.txt", n);

		CopyFileContents("experiment_1.txt", "experiment_2.txt");
		CopyFileContents("experiment_2.txt", "experiment_3.txt");
		CopyFileContents("experiment_3.txt", "experiment_4.txt");
		CopyFileContents("experiment_4.txt", "experiment_5.txt");
		CopyFileContents("experiment_5.txt", "experiment_6.txt");

		graphic_division();

		SimpleSort ex_1;
		cout << "\nЗапуск 1\n";
		auto start1 = chrono::high_resolution_clock::now();
		ex_1.Simple_Merging_Sort("experiment_1.txt");
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration1 = end1 - start1;
		file_sorted_1("experiment_1.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration1.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
		ex_1.io_operations = 0;
		ex_1.all_comparisons = 0;
		ex_1.comparisons_elements=0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		SimpleSort ex_2;
		auto start2 = chrono::high_resolution_clock::now();
		ex_2.Simple_Merging_Sort("experiment_2.txt");
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration2 = end2 - start2;
		file_sorted_1("experiment_2.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_2.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_2.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_2.comparisons_elements;
		ex_2.io_operations = 0;
		ex_2.all_comparisons = 0;
		ex_2.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		SimpleSort ex_3;
		auto start3 = chrono::high_resolution_clock::now();
		ex_3.Simple_Merging_Sort("experiment_3.txt");
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration3 = end3 - start3;
		file_sorted_1("experiment_3.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_3.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_3.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_3.comparisons_elements;
		ex_3.io_operations = 0;
		ex_3.all_comparisons = 0;
		ex_3.comparisons_elements = 0;
		graphic_division();
		cout << "\n**Измерение критериев качетсва для сортировки естественныс слиянием**\n";
		graphic_division();

		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";

		cout << "Измерение критериев качетсва для сортировки естественныс слиянием\n";

		cout << "Запуск 1\n";
		NaturalSort ex_4;
		auto start4 = chrono::high_resolution_clock::now();
		ex_4.Natural_Merging_Sort("experiment_4.txt");
		auto end4 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration4 = end4 - start4;
		file_sorted_1("experiment_4.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration4.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_4.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_4.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_4.comparisons_elements;
		ex_4.io_operations = 0;
		ex_4.all_comparisons = 0;
		ex_4.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		NaturalSort ex_5;
		auto start5 = chrono::high_resolution_clock::now();
		ex_5.Natural_Merging_Sort("experiment_5.txt");
		auto end5 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration5 = end5 - start5;
		file_sorted_1("experiment_5.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration5.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_5.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_5.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_5.comparisons_elements;
		ex_5.io_operations = 0;
		ex_5.all_comparisons = 0;
		ex_5.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		NaturalSort ex_6;
		auto start6 = chrono::high_resolution_clock::now();
		ex_6.Natural_Merging_Sort("experiment_6.txt");
		auto end6 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration6 = end6 - start6;
		file_sorted_1("experiment_6.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration6.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_6.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_6.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_6.comparisons_elements;
		ex_6.io_operations = 0;
		ex_6.all_comparisons = 0;
		ex_6.comparisons_elements = 0;
		graphic_division();

		n = n * 10;
		k++;

		ClearFile("experiment_1.txt");
		ClearFile("experiment_2.txt");
		ClearFile("experiment_3.txt");
		ClearFile("experiment_4.txt");
		ClearFile("experiment_5.txt");
		ClearFile("experiment_6.txt");
	}


}

void ExperimentFunctions::experiment_2_almost_sorted_dataset()
{
	int n = 100;
	int k = 1;

	while (n <= 10000)
	{
		graphic_division();
		ExperimentFunctions ex1;
		cout << k << ".Описание данных: \n";
		cout << "Почти отсортированный набор данных " << n << " элементов\n";
		ex1.almost_sorted_dataset("experiment_1.txt", n);
		CopyFileContents("experiment_1.txt", "experiment_2.txt");
		CopyFileContents("experiment_2.txt", "experiment_3.txt");
		CopyFileContents("experiment_3.txt", "experiment_4.txt");
		CopyFileContents("experiment_4.txt", "experiment_5.txt");
		CopyFileContents("experiment_5.txt", "experiment_6.txt");

		graphic_division();

		SimpleSort ex_1;
		cout << "\nЗапуск 1\n";
		auto start1 = chrono::high_resolution_clock::now();
		ex_1.Simple_Merging_Sort("experiment_1.txt");
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration1 = end1 - start1;
		file_sorted_1("experiment_1.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration1.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
		ex_1.io_operations = 0;
		ex_1.all_comparisons = 0;
		ex_1.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		SimpleSort ex_2;
		auto start2 = chrono::high_resolution_clock::now();
		ex_2.Simple_Merging_Sort("experiment_2.txt");
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration2 = end2 - start2;
		file_sorted_1("experiment_2.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_2.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_2.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_2.comparisons_elements;
		ex_2.io_operations = 0;
		ex_2.all_comparisons = 0;
		ex_2.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		SimpleSort ex_3;
		auto start3 = chrono::high_resolution_clock::now();
		ex_3.Simple_Merging_Sort("experiment_3.txt");
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration3 = end3 - start3;
		file_sorted_1("experiment_3.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_3.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_3.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_3.comparisons_elements;
		ex_3.io_operations = 0;
		ex_3.all_comparisons = 0;
		ex_3.comparisons_elements = 0;
		graphic_division();
		cout << "\n**Измерение критериев качетсва для сортировки естественныс слиянием**\n";
		graphic_division();

		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";

		cout << "Измерение критериев качетсва для сортировки естественныс слиянием\n";

		cout << "Запуск 1\n";
		NaturalSort ex_4;
		auto start4 = chrono::high_resolution_clock::now();
		ex_4.Natural_Merging_Sort("experiment_4.txt");
		auto end4 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration4 = end4 - start4;
		file_sorted_1("experiment_4.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration4.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_4.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_4.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_4.comparisons_elements;
		ex_4.io_operations = 0;
		ex_4.all_comparisons = 0;
		ex_4.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		NaturalSort ex_5;
		auto start5 = chrono::high_resolution_clock::now();
		ex_5.Natural_Merging_Sort("experiment_5.txt");
		auto end5 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration5 = end5 - start5;
		file_sorted_1("experiment_5.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration5.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_5.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_5.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_5.comparisons_elements;
		ex_5.io_operations = 0;
		ex_5.all_comparisons = 0;
		ex_5.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		NaturalSort ex_6;
		auto start6 = chrono::high_resolution_clock::now();
		ex_6.Natural_Merging_Sort("experiment_6.txt");
		auto end6 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration6 = end6 - start6;
		file_sorted_1("experiment_6.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration6.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_6.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_6.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_6.comparisons_elements;
		ex_6.io_operations = 0;
		ex_6.all_comparisons = 0;
		ex_6.comparisons_elements = 0;
		graphic_division();

		n = n * 10;
		k++;

		ClearFile("experiment_1.txt");
		ClearFile("experiment_2.txt");
		ClearFile("experiment_3.txt");
		ClearFile("experiment_4.txt");
		ClearFile("experiment_5.txt");
		ClearFile("experiment_6.txt");
	}

}

void ExperimentFunctions::experiment_3_duplicate_dataset()
{
	int n = 100;
	int k = 1;

	while (n <= 10000)
	{
		graphic_division();
		ExperimentFunctions ex1;
		cout << k << ".Описание данных: \n";
		cout << "Набор данных с повторяющимися элементами " << n << " элементов\n";
		ex1.duplicate_dataset("experiment_1.txt", n);
		CopyFileContents("experiment_1.txt", "experiment_2.txt");
		CopyFileContents("experiment_2.txt", "experiment_3.txt");
		CopyFileContents("experiment_3.txt", "experiment_4.txt");
		CopyFileContents("experiment_4.txt", "experiment_5.txt");
		CopyFileContents("experiment_5.txt", "experiment_6.txt");

		graphic_division();

		SimpleSort ex_1;
		cout << "\nЗапуск 1\n";
		auto start1 = chrono::high_resolution_clock::now();
		ex_1.Simple_Merging_Sort("experiment_1.txt");
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration1 = end1 - start1;
		file_sorted_1("experiment_1.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration1.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
		ex_1.io_operations = 0;
		ex_1.all_comparisons = 0;
		ex_1.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		SimpleSort ex_2;
		auto start2 = chrono::high_resolution_clock::now();
		ex_2.Simple_Merging_Sort("experiment_2.txt");
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration2 = end2 - start2;
		file_sorted_1("experiment_2.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_2.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_2.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_2.comparisons_elements;
		ex_2.io_operations = 0;
		ex_2.all_comparisons = 0;
		ex_2.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		SimpleSort ex_3;
		auto start3 = chrono::high_resolution_clock::now();
		ex_3.Simple_Merging_Sort("experiment_3.txt");
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration3 = end3 - start3;
		file_sorted_1("experiment_3.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_3.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_3.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_3.comparisons_elements;
		ex_3.io_operations = 0;
		ex_3.all_comparisons = 0;
		ex_3.comparisons_elements = 0;
		graphic_division();
		cout << "\n**Измерение критериев качетсва для сортировки естественныс слиянием**\n";
		graphic_division();

		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";

		cout << "Измерение критериев качетсва для сортировки естественныс слиянием\n";

		cout << "Запуск 1\n";
		NaturalSort ex_4;
		auto start4 = chrono::high_resolution_clock::now();
		ex_4.Natural_Merging_Sort("experiment_4.txt");
		auto end4 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration4 = end4 - start4;
		file_sorted_1("experiment_4.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration4.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_4.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_4.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_4.comparisons_elements;
		ex_4.io_operations = 0;
		ex_4.all_comparisons = 0;
		ex_4.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		NaturalSort ex_5;
		auto start5 = chrono::high_resolution_clock::now();
		ex_5.Natural_Merging_Sort("experiment_5.txt");
		auto end5 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration5 = end5 - start5;
		file_sorted_1("experiment_5.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration5.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_5.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_5.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_5.comparisons_elements;
		ex_5.io_operations = 0;
		ex_5.all_comparisons = 0;
		ex_5.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		NaturalSort ex_6;
		auto start6 = chrono::high_resolution_clock::now();
		ex_6.Natural_Merging_Sort("experiment_6.txt");
		auto end6 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration6 = end6 - start6;
		file_sorted_1("experiment_6.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration6.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_6.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_6.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_6.comparisons_elements;
		ex_6.io_operations = 0;
		ex_6.all_comparisons = 0;
		ex_6.comparisons_elements = 0;
		graphic_division();

		n = n * 10;
		k++;

		ClearFile("experiment_1.txt");
		ClearFile("experiment_2.txt");
		ClearFile("experiment_3.txt");
		ClearFile("experiment_4.txt");
		ClearFile("experiment_5.txt");
		ClearFile("experiment_6.txt");
	}

}

void ExperimentFunctions::experiment_4_worst_case_data()
{
	int n = 100;
	int k = 1;

	while (n <= 1000000)
	{
		graphic_division();
		ExperimentFunctions ex1;
		cout << k << ".Описание данных: \n";
		cout << "Набор данных в худшем случае(вся последовательность убывает) " << n << " элементов\n";
		ex1.worst_case_data("experiment_1.txt", n);
		CopyFileContents("experiment_1.txt", "experiment_2.txt");
		CopyFileContents("experiment_2.txt", "experiment_3.txt");
		CopyFileContents("experiment_3.txt", "experiment_4.txt");
		CopyFileContents("experiment_4.txt", "experiment_5.txt");
		CopyFileContents("experiment_5.txt", "experiment_6.txt");

		graphic_division();

		SimpleSort ex_1;
		cout << "\nЗапуск 1\n";
		auto start1 = chrono::high_resolution_clock::now();
		ex_1.Simple_Merging_Sort("experiment_1.txt");
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration1 = end1 - start1;
		file_sorted_1("experiment_1.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration1.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
		ex_1.io_operations = 0;
		ex_1.all_comparisons = 0;
		ex_1.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		SimpleSort ex_2;
		auto start2 = chrono::high_resolution_clock::now();
		ex_2.Simple_Merging_Sort("experiment_2.txt");
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration2 = end2 - start2;
		file_sorted_1("experiment_2.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_2.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_2.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_2.comparisons_elements;
		ex_2.io_operations = 0;
		ex_2.all_comparisons = 0;
		ex_2.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		SimpleSort ex_3;
		auto start3 = chrono::high_resolution_clock::now();
		ex_3.Simple_Merging_Sort("experiment_3.txt");
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration3 = end3 - start3;
		file_sorted_1("experiment_3.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_3.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_3.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_3.comparisons_elements;
		ex_3.io_operations = 0;
		ex_3.all_comparisons = 0;
		ex_3.comparisons_elements = 0;
		graphic_division();
		cout << "\n**Измерение критериев качетсва для сортировки естественныс слиянием**\n";
		graphic_division();

		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";

		cout << "Измерение критериев качетсва для сортировки естественныс слиянием\n";

		cout << "Запуск 1\n";
		NaturalSort ex_4;
		auto start4 = chrono::high_resolution_clock::now();
		ex_4.Natural_Merging_Sort("experiment_4.txt");
		auto end4 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration4 = end4 - start4;
		file_sorted_1("experiment_4.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration4.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_4.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_4.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_4.comparisons_elements;
		ex_4.io_operations = 0;
		ex_4.all_comparisons = 0;
		ex_4.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		NaturalSort ex_5;
		auto start5 = chrono::high_resolution_clock::now();
		ex_5.Natural_Merging_Sort("experiment_5.txt");
		auto end5 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration5 = end5 - start5;
		file_sorted_1("experiment_5.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration5.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_5.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_5.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_5.comparisons_elements;
		ex_5.io_operations = 0;
		ex_5.all_comparisons = 0;
		ex_5.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		NaturalSort ex_6;
		auto start6 = chrono::high_resolution_clock::now();
		ex_6.Natural_Merging_Sort("experiment_6.txt");
		auto end6 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration6 = end6 - start6;
		file_sorted_1("experiment_6.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration6.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_6.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_6.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_6.comparisons_elements;
		ex_6.io_operations = 0;
		ex_6.all_comparisons = 0;
		ex_6.comparisons_elements = 0;
		graphic_division();

		n = n * 10;
		k++;

		ClearFile("experiment_1.txt");
		ClearFile("experiment_2.txt");
		ClearFile("experiment_3.txt");
		ClearFile("experiment_4.txt");
		ClearFile("experiment_5.txt");
		ClearFile("experiment_6.txt");
	}
}

void ExperimentFunctions::experiment_5_best_case_data()
{
	int n = 100;
	int k = 1;

	while (n <= 1000000)
	{
		graphic_division();
		ExperimentFunctions ex1;
		cout << k << ".Описание данных: \n";
		cout << "Набор данных в лучшем случае(вся последовательность возрастает) " << n << " элементов\n";
		CopyFileContents("experiment_1.txt", "experiment_2.txt");
		CopyFileContents("experiment_2.txt", "experiment_3.txt");
		CopyFileContents("experiment_3.txt", "experiment_4.txt");
		CopyFileContents("experiment_4.txt", "experiment_5.txt");
		CopyFileContents("experiment_5.txt", "experiment_6.txt");

		graphic_division();

		SimpleSort ex_1;
		cout << "\nЗапуск 1\n";
		auto start1 = chrono::high_resolution_clock::now();
		ex_1.Simple_Merging_Sort("experiment_1.txt");
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration1 = end1 - start1;
		file_sorted_1("experiment_1.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration1.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
		ex_1.io_operations = 0;
		ex_1.all_comparisons = 0;
		ex_1.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		SimpleSort ex_2;
		auto start2 = chrono::high_resolution_clock::now();
		ex_2.Simple_Merging_Sort("experiment_2.txt");
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration2 = end2 - start2;
		file_sorted_1("experiment_2.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_2.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_2.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_2.comparisons_elements;
		ex_2.io_operations = 0;
		ex_2.all_comparisons = 0;
		ex_2.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		SimpleSort ex_3;
		auto start3 = chrono::high_resolution_clock::now();
		ex_3.Simple_Merging_Sort("experiment_3.txt");
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration3 = end3 - start3;
		file_sorted_1("experiment_3.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_3.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_3.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_3.comparisons_elements;
		ex_3.io_operations = 0;
		ex_3.all_comparisons = 0;
		ex_3.comparisons_elements = 0;
		graphic_division();
		cout << "\n**Измерение критериев качетсва для сортировки естественныс слиянием**\n";
		graphic_division();

		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";

		cout << "Измерение критериев качетсва для сортировки естественныс слиянием\n";

		cout << "Запуск 1\n";
		NaturalSort ex_4;
		auto start4 = chrono::high_resolution_clock::now();
		ex_4.Natural_Merging_Sort("experiment_4.txt");
		auto end4 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration4 = end4 - start4;
		file_sorted_1("experiment_4.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration4.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_4.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_4.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_4.comparisons_elements;
		ex_4.io_operations = 0;
		ex_4.all_comparisons = 0;
		ex_4.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		NaturalSort ex_5;
		auto start5 = chrono::high_resolution_clock::now();
		ex_5.Natural_Merging_Sort("experiment_5.txt");
		auto end5 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration5 = end5 - start5;
		file_sorted_1("experiment_5.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration5.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_5.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_5.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_5.comparisons_elements;
		ex_5.io_operations = 0;
		ex_5.all_comparisons = 0;
		ex_5.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		NaturalSort ex_6;
		auto start6 = chrono::high_resolution_clock::now();
		ex_6.Natural_Merging_Sort("experiment_6.txt");
		auto end6 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration6 = end6 - start6;
		file_sorted_1("experiment_6.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration6.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_6.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_6.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_6.comparisons_elements;
		ex_6.io_operations = 0;
		ex_6.all_comparisons = 0;
		ex_6.comparisons_elements = 0;
		graphic_division();

		n = n * 10;
		k++;

		ClearFile("experiment_1.txt");
		ClearFile("experiment_2.txt");
		ClearFile("experiment_3.txt");
		ClearFile("experiment_4.txt");
		ClearFile("experiment_5.txt");
		ClearFile("experiment_6.txt");
	}
}

void ExperimentFunctions::experiment_6_element_repeated_10_times_dataset()
{
	int n = 100;
	int k = 1;

	while (n <= 1000000)
	{
		graphic_division();
		ExperimentFunctions ex1;
		cout << k << ".Описание данных: \n";
		cout << "Набор данных с несколькими одинаковыми элементами (каждый элемент повторяется 10 раз) " << n << " элементов\n";
		ex1.element_repeated_10_times_dataset("experiment_1.txt", n);
		CopyFileContents("experiment_1.txt", "experiment_2.txt");
		CopyFileContents("experiment_2.txt", "experiment_3.txt");
		CopyFileContents("experiment_3.txt", "experiment_4.txt");
		CopyFileContents("experiment_4.txt", "experiment_5.txt");
		CopyFileContents("experiment_5.txt", "experiment_6.txt");

		graphic_division();

		SimpleSort ex_1;
		cout << "\nЗапуск 1\n";
		auto start1 = chrono::high_resolution_clock::now();
		ex_1.Simple_Merging_Sort("experiment_1.txt");
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration1 = end1 - start1;
		file_sorted_1("experiment_1.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration1.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
		ex_1.io_operations = 0;
		ex_1.all_comparisons = 0;
		ex_1.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		SimpleSort ex_2;
		auto start2 = chrono::high_resolution_clock::now();
		ex_2.Simple_Merging_Sort("experiment_2.txt");
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration2 = end2 - start2;
		file_sorted_1("experiment_2.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_2.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_2.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_2.comparisons_elements;
		ex_2.io_operations = 0;
		ex_2.all_comparisons = 0;
		ex_2.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		SimpleSort ex_3;
		auto start3 = chrono::high_resolution_clock::now();
		ex_3.Simple_Merging_Sort("experiment_3.txt");
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration3 = end3 - start3;
		file_sorted_1("experiment_3.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_3.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_3.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_3.comparisons_elements;
		ex_3.io_operations = 0;
		ex_3.all_comparisons = 0;
		ex_3.comparisons_elements = 0;
		graphic_division();
		cout << "\n**Измерение критериев качетсва для сортировки естественныс слиянием**\n";
		graphic_division();

		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";

		cout << "Измерение критериев качетсва для сортировки естественныс слиянием\n";

		cout << "Запуск 1\n";
		NaturalSort ex_4;
		auto start4 = chrono::high_resolution_clock::now();
		ex_4.Natural_Merging_Sort("experiment_4.txt");
		auto end4 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration4 = end4 - start4;
		file_sorted_1("experiment_4.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration4.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_4.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_4.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_4.comparisons_elements;
		ex_4.io_operations = 0;
		ex_4.all_comparisons = 0;
		ex_4.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		NaturalSort ex_5;
		auto start5 = chrono::high_resolution_clock::now();
		ex_5.Natural_Merging_Sort("experiment_5.txt");
		auto end5 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration5 = end5 - start5;
		file_sorted_1("experiment_5.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration5.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_5.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_5.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_5.comparisons_elements;
		ex_5.io_operations = 0;
		ex_5.all_comparisons = 0;
		ex_5.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		NaturalSort ex_6;
		auto start6 = chrono::high_resolution_clock::now();
		ex_6.Natural_Merging_Sort("experiment_6.txt");
		auto end6 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration6 = end6 - start6;
		file_sorted_1("experiment_6.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration6.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_6.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_6.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_6.comparisons_elements;
		ex_6.io_operations = 0;
		ex_6.all_comparisons = 0;
		ex_6.comparisons_elements = 0;
		graphic_division();

		n = n * 10;
		k++;

		ClearFile("experiment_1.txt");
		ClearFile("experiment_2.txt");
		ClearFile("experiment_3.txt");
		ClearFile("experiment_4.txt");
		ClearFile("experiment_5.txt");
		ClearFile("experiment_6.txt");
	}
}

void ExperimentFunctions::experiment_7_element_dataset_alternating_values()
{
	int n = 100;
	int k = 1;

	while (n <= 1000000)
	{
		graphic_division();
		ExperimentFunctions ex1;
		cout << k << ".Описание данных: \n";
		cout << "Набор данных с чередующимися значениями (каждый второй элемент является дубликатом предыдущего) " << n << " элементов\n";
		ex1.dataset_alternating_values("experiment_1.txt", n);
		CopyFileContents("experiment_1.txt", "experiment_2.txt");
		CopyFileContents("experiment_2.txt", "experiment_3.txt");
		CopyFileContents("experiment_3.txt", "experiment_4.txt");
		CopyFileContents("experiment_4.txt", "experiment_5.txt");
		CopyFileContents("experiment_5.txt", "experiment_6.txt");

		graphic_division();

		SimpleSort ex_1;
		cout << "\nЗапуск 1\n";
		auto start1 = chrono::high_resolution_clock::now();
		ex_1.Simple_Merging_Sort("experiment_1.txt");
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration1 = end1 - start1;
		file_sorted_1("experiment_1.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration1.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
		ex_1.io_operations = 0;
		ex_1.all_comparisons = 0;
		ex_1.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		SimpleSort ex_2;
		auto start2 = chrono::high_resolution_clock::now();
		ex_2.Simple_Merging_Sort("experiment_2.txt");
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration2 = end2 - start2;
		file_sorted_1("experiment_2.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_2.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_2.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_2.comparisons_elements;
		ex_2.io_operations = 0;
		ex_2.all_comparisons = 0;
		ex_2.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		SimpleSort ex_3;
		auto start3 = chrono::high_resolution_clock::now();
		ex_3.Simple_Merging_Sort("experiment_3.txt");
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration3 = end3 - start3;
		file_sorted_1("experiment_3.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_3.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_3.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_3.comparisons_elements;
		ex_3.io_operations = 0;
		ex_3.all_comparisons = 0;
		ex_3.comparisons_elements = 0;
		graphic_division();
		cout << "\n**Измерение критериев качетсва для сортировки естественныс слиянием**\n";
		graphic_division();

		cout << k << ".Описание данных: \n";
		cout << "Случайный набор данных " << n << " элементов\n";

		cout << "Измерение критериев качетсва для сортировки естественныс слиянием\n";

		cout << "Запуск 1\n";
		NaturalSort ex_4;
		auto start4 = chrono::high_resolution_clock::now();
		ex_4.Natural_Merging_Sort("experiment_4.txt");
		auto end4 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration4 = end4 - start4;
		file_sorted_1("experiment_4.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration4.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_4.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_4.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_4.comparisons_elements;
		ex_4.io_operations = 0;
		ex_4.all_comparisons = 0;
		ex_4.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 2\n";
		NaturalSort ex_5;
		auto start5 = chrono::high_resolution_clock::now();
		ex_5.Natural_Merging_Sort("experiment_5.txt");
		auto end5 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration5 = end5 - start5;
		file_sorted_1("experiment_5.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration5.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_5.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_5.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_5.comparisons_elements;
		ex_5.io_operations = 0;
		ex_5.all_comparisons = 0;
		ex_5.comparisons_elements = 0;
		graphic_division();

		cout << "\nЗапуск 3\n";
		NaturalSort ex_6;
		auto start6 = chrono::high_resolution_clock::now();
		ex_6.Natural_Merging_Sort("experiment_6.txt");
		auto end6 = chrono::high_resolution_clock::now();
		chrono::duration<double> duration6 = end6 - start6;
		file_sorted_1("experiment_6.txt");
		graphic_division();
		cout << "Время полной работы сортировки: " << duration6.count() << " секунд";
		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_6.io_operations;
		cout << "\nКоличество всех сравнений: " << ex_6.all_comparisons;
		cout << "\nКоличество сравнений элементов: " << ex_6.comparisons_elements;
		ex_6.io_operations = 0;
		ex_6.all_comparisons = 0;
		ex_6.comparisons_elements = 0;
		graphic_division();

		n = n * 10;
		k++;

		ClearFile("experiment_1.txt");
		ClearFile("experiment_2.txt");
		ClearFile("experiment_3.txt");
		ClearFile("experiment_4.txt");
		ClearFile("experiment_5.txt");
		ClearFile("experiment_6.txt");
	}
}



//void ExperimentFunctions::experiment_1_natural_sorting_random_data()
//{
//	int n = 100;
//	int k = 1;
//
//	while (n <= 1000000)
//	{
//		graphic_division();
//		ExperimentFunctions ex1;
//		cout << k << ".Описание данных: \n";
//		cout << "Случайный набор данных " << n << " элементов\n";
//		ex1.generate_random("experiment_1.txt", n);
//		CopyFileContents("experiment_1.txt", "experiment_2.txt");
//		CopyFileContents("experiment_1.txt", "experiment_3.txt");
//		graphic_division();
//
//		cout << "Запуск 1\n";
//		NaturalSort ex_1;
//		auto start = chrono::high_resolution_clock::now();
//		ex_1.Natural_Merging_Sort("experiment_1.txt");
//		auto end = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration = end - start;
//		file_sorted_1("experiment_1.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//
//		cout << "Запуск 2\n";
//		NaturalSort ex_2;
//		auto start2 = chrono::high_resolution_clock::now();
//		ex_2.Natural_Merging_Sort("experiment_2.txt");
//		auto end2 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration2 = end2 - start2;
//		file_sorted_1("experiment_2.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		cout << "Запуск 3\n";
//		NaturalSort ex_3;
//		auto start3 = chrono::high_resolution_clock::now();
//		ex_3.Natural_Merging_Sort("experiment_3.txt");
//		auto end3 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration3 = end3 - start3;
//		file_sorted_1("experiment_3.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//		n = n * 10;
//		k++;
//		ClearFile("experiment_1.txt");
//		ClearFile("experiment_2.txt");
//		ClearFile("experiment_3.txt");
//	}
//}
//
//void ExperimentFunctions::experiment_2_natural_sorting_almost_sorted_dataset()
//{
//	int n = 100;
//	int k = 1;
//
//	while (n <= 1000000)
//	{
//		graphic_division();
//		ExperimentFunctions ex1;
//		cout << k << ".Описание данных: \n";
//		cout << "Почти отсортированный набор данных " << n << " элементов\n";
//		ex1.almost_sorted_dataset("experiment_1.txt", n);
//		CopyFileContents("experiment_1.txt", "experiment_2.txt");
//		CopyFileContents("experiment_1.txt", "experiment_3.txt");
//
//		graphic_division();
//		cout << "Запуск 1\n";
//		NaturalSort ex_1;
//		auto start = chrono::high_resolution_clock::now();
//		ex_1.Natural_Merging_Sort("experiment_1.txt");
//		auto end = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration = end - start;
//		file_sorted_1("experiment_1.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//
//		cout << "Запуск 2\n";
//		NaturalSort ex_2;
//		auto start2 = chrono::high_resolution_clock::now();
//		ex_2.Natural_Merging_Sort("experiment_2.txt");
//		auto end2 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration2 = end2 - start2;
//		file_sorted_1("experiment_2.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		cout << "Запуск 3\n";
//		NaturalSort ex_3;
//		auto start3 = chrono::high_resolution_clock::now();
//		ex_3.Natural_Merging_Sort("experiment_3.txt");
//		auto end3 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration3 = end3 - start3;
//		file_sorted_1("experiment_3.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//		n = n * 10;
//		k++;
//		ClearFile("experiment_1.txt");
//		ClearFile("experiment_2.txt");
//		ClearFile("experiment_3.txt");
//	}
//}
//
//void ExperimentFunctions::experiment_3_natural_sorting_duplicate_dataset()
//{
//	int n = 100;
//	int k = 1;
//
//	while (n <= 1000000)
//	{
//		graphic_division();
//		ExperimentFunctions ex1;
//		cout << k << ".Описание данных: \n";
//		cout << "Набор данных с повторяющимися элементами " << n << " элементов\n";
//		ex1.duplicate_dataset("experiment_1.txt", n);
//		CopyFileContents("experiment_1.txt", "experiment_2.txt");
//		CopyFileContents("experiment_1.txt", "experiment_3.txt");
//		graphic_division();
//
//		cout << "Запуск 1\n";
//		NaturalSort ex_1;
//		auto start = chrono::high_resolution_clock::now();
//		ex_1.Natural_Merging_Sort("experiment_1.txt");
//		auto end = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration = end - start;
//		file_sorted_1("experiment_1.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//
//		cout << "Запуск 2\n";
//		NaturalSort ex_2;
//		auto start2 = chrono::high_resolution_clock::now();
//		ex_2.Natural_Merging_Sort("experiment_2.txt");
//		auto end2 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration2 = end2 - start2;
//		file_sorted_1("experiment_2.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		cout << "Запуск 3\n";
//		NaturalSort ex_3;
//		auto start3 = chrono::high_resolution_clock::now();
//		ex_3.Natural_Merging_Sort("experiment_3.txt");
//		auto end3 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration3 = end3 - start3;
//		file_sorted_1("experiment_3.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		graphic_division();
//		n = n * 10;
//		k++;
//		ClearFile("experiment_1.txt");
//		ClearFile("experiment_2.txt");
//		ClearFile("experiment_3.txt");
//	}
//}
//
//void ExperimentFunctions::experiment_4_natural_sorting_worst_case_data()
//{
//	int n = 100;
//	int k = 1;
//
//	while (n <= 1000000)
//	{
//		graphic_division();
//		ExperimentFunctions ex1;
//		cout << k << ".Описание данных: \n";
//		cout << "Набор данных в худшем случае(вся последовательность убывает) " << n << " элементов\n";
//		ex1.worst_case_data("experiment_1.txt", n);
//		CopyFileContents("experiment_1.txt", "experiment_2.txt");
//		CopyFileContents("experiment_1.txt", "experiment_3.txt");
//		graphic_division();
//
//		cout << "Запуск 1\n";
//		NaturalSort ex_1;
//		auto start = chrono::high_resolution_clock::now();
//		ex_1.Natural_Merging_Sort("experiment_1.txt");
//		auto end = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration = end - start;
//		file_sorted_1("experiment_1.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//
//		cout << "Запуск 2\n";
//		NaturalSort ex_2;
//		auto start2 = chrono::high_resolution_clock::now();
//		ex_2.Natural_Merging_Sort("experiment_2.txt");
//		auto end2 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration2 = end2 - start2;
//		file_sorted_1("experiment_2.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		cout << "Запуск 3\n";
//		NaturalSort ex_3;
//		auto start3 = chrono::high_resolution_clock::now();
//		ex_3.Natural_Merging_Sort("experiment_3.txt");
//		auto end3 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration3 = end3 - start3;
//		file_sorted_1("experiment_3.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//		n = n * 10;
//		k++;
//		ClearFile("experiment_1.txt");
//		ClearFile("experiment_2.txt");
//		ClearFile("experiment_3.txt");
//	}
//}
//
//void ExperimentFunctions::experiment_5_natural_sorting_best_case_data()
//{
//	int n = 100;
//	int k = 1;
//
//	while (n <= 1000000)
//	{
//		graphic_division();
//		ExperimentFunctions ex1;
//		cout << k << ".Описание данных: \n";
//		cout << "Набор данных в лучшем случае(вся последовательность возрастает) " << n << " элементов\n";
//		ex1.worst_case_data("experiment_1.txt", n);
//		CopyFileContents("experiment_1.txt", "experiment_2.txt");
//		CopyFileContents("experiment_1.txt", "experiment_3.txt");
//		graphic_division();
//
//		cout << "Запуск 1\n";
//		NaturalSort ex_1;
//		auto start = chrono::high_resolution_clock::now();
//		ex_1.Natural_Merging_Sort("experiment_1.txt");
//		auto end = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration = end - start;
//		file_sorted_1("experiment_1.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//
//		cout << "Запуск 2\n";
//		NaturalSort ex_2;
//		auto start2 = chrono::high_resolution_clock::now();
//		ex_2.Natural_Merging_Sort("experiment_2.txt");
//		auto end2 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration2 = end2 - start2;
//		file_sorted_1("experiment_2.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		cout << "Запуск 3\n";
//		NaturalSort ex_3;
//		auto start3 = chrono::high_resolution_clock::now();
//		ex_3.Natural_Merging_Sort("experiment_3.txt");
//		auto end3 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration3 = end3 - start3;
//		file_sorted_1("experiment_3.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//		n = n * 10;
//		k++;
//		ClearFile("experiment_1.txt");
//		ClearFile("experiment_2.txt");
//		ClearFile("experiment_3.txt");
//	}
//}
//
//void ExperimentFunctions::experiment_6_natural_sorting_element_repeated_10_times_dataset()
//{
//	int n = 100;
//	int k = 1;
//
//	while (n <= 1000000)
//	{
//		graphic_division();
//		ExperimentFunctions ex1;
//		cout << k << ".Описание данных: \n";
//		cout << "Набор данных с несколькими одинаковыми элементами (каждый элемент повторяется 10 раз) " << n << " элементов\n";
//		ex1.element_repeated_10_times_dataset("experiment_1.txt", n);
//		CopyFileContents("experiment_1.txt", "experiment_2.txt");
//		CopyFileContents("experiment_1.txt", "experiment_3.txt");
//
//		graphic_division();
//
//		cout << "Запуск 1\n";
//		NaturalSort ex_1;
//		auto start = chrono::high_resolution_clock::now();
//		ex_1.Natural_Merging_Sort("experiment_1.txt");
//		auto end = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration = end - start;
//		file_sorted_1("experiment_1.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//
//		cout << "Запуск 2\n";
//		NaturalSort ex_2;
//		auto start2 = chrono::high_resolution_clock::now();
//		ex_2.Natural_Merging_Sort("experiment_2.txt");
//		auto end2 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration2 = end2 - start2;
//		file_sorted_1("experiment_2.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		cout << "Запуск 3\n";
//		NaturalSort ex_3;
//		auto start3 = chrono::high_resolution_clock::now();
//		ex_3.Natural_Merging_Sort("experiment_3.txt");
//		auto end3 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration3 = end3 - start3;
//		file_sorted_1("experiment_3.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//		n = n * 10;
//		k++;
//		ClearFile("experiment_1.txt");
//		ClearFile("experiment_2.txt");
//		ClearFile("experiment_3.txt");
//	}
//}
//
//void ExperimentFunctions::experiment_7_natural_sorting_element_dataset_alternating_values()
//{
//	int n = 100;
//	int k = 1;
//
//	while (n <= 1000000)
//	{
//		graphic_division();
//		ExperimentFunctions ex1;
//		cout << k << ".Описание данных: \n";
//		cout << "Набор данных с чередующимися значениями (каждый второй элемент является дубликатом предыдущего) " << n << " элементов\n";
//		ex1.dataset_alternating_values("experiment_1.txt", n);
//		CopyFileContents("experiment_1.txt", "experiment_2.txt");
//		CopyFileContents("experiment_1.txt", "experiment_3.txt");
//		graphic_division();
//
//		cout << "Запуск 1\n";
//		NaturalSort ex_1;
//		auto start = chrono::high_resolution_clock::now();
//		ex_1.Natural_Merging_Sort("experiment_1.txt");
//		auto end = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration = end - start;
//		file_sorted_1("experiment_1.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//
//		cout << "Запуск 2\n";
//		NaturalSort ex_2;
//		auto start2 = chrono::high_resolution_clock::now();
//		ex_2.Natural_Merging_Sort("experiment_2.txt");
//		auto end2 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration2 = end2 - start2;
//		file_sorted_1("experiment_2.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration2.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//
//		cout << "Запуск 3\n";
//		NaturalSort ex_3;
//		auto start3 = chrono::high_resolution_clock::now();
//		ex_3.Natural_Merging_Sort("experiment_3.txt");
//		auto end3 = chrono::high_resolution_clock::now();
//		chrono::duration<double> duration3 = end3 - start3;
//		file_sorted_1("experiment_3.txt");
//		graphic_division();
//		cout << "Время полной работы сортировки: " << duration3.count() << " секунд";
//		cout << "\nКоличество операции чтения и записи для работы с файлами: " << ex_1.io_operations;
//		cout << "\nКоличество всех сравнений: " << ex_1.all_comparisons;
//		cout << "\nКоличество сравнений элементов: " << ex_1.comparisons_elements;
//		graphic_division();
//		n = n * 10;
//		k++;
//		ClearFile("experiment_1.txt");
//		ClearFile("experiment_2.txt");
//		ClearFile("experiment_3.txt");
//	}
//}



void ExperimentFunctions::generate_random(const string& filename, int n) {

	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return;
	}

	srand(time(nullptr));

	for (int i = 0; i < n; ++i) {
		file << rand() << " ";
	}

	file.close();
}

void ExperimentFunctions::almost_sorted_dataset(const string& filename, int n) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return;
	}

	for (int i = 0; i <= n; ++i) {
		file << i << " ";
	}

	srand(time(nullptr));

	for (int i = 0; i < n / 100; ++i) {
		int random_index = rand() % n;
		int random_number = rand() % 9 + 1;
		file.seekp(random_index * sizeof(int)); 
		file << random_number << " ";
	}

	file.close();
}

void ExperimentFunctions::duplicate_dataset(const string& filename, int n) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return;
	}


	srand(time(nullptr));

	for (int i = 0; i < n; ++i) {
		int random_number = rand() % 100;
		file << random_number << " ";
	}

	file.close();
}

void ExperimentFunctions::worst_case_data(const string& filename, int n) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		file << n - i << " ";
	}

	file.close();
}

void ExperimentFunctions::best_case_data(const string& filename, int n) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		file << i << " ";
	}

	file.close();
}

void ExperimentFunctions::element_repeated_10_times_dataset(const string& filename, int n) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return;
	}

	for (int i = 0; i < n / 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			file << n - i << " ";
		}
	}

	file.close();
}

void ExperimentFunctions::dataset_alternating_values(const string& filename, int n) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл " << filename << endl;
		return;
	}

	int value = n;
	for (int i = 0; i < n; ++i) {
		file << value << " ";
		if (i % 2 == 0) {
			value--;
		}
	}

	file.close();
}




