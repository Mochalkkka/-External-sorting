#include "TestFunctions.h"
#include "SimpleSort.h"
#include "NaturalSort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
using namespace std;

bool TestFunctions::file_sorted(const string& filename) {

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

void TestFunctions::generate_random_data_500_elements(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    srand(time(nullptr));

    for (int i = 0; i < 500; ++i) {
        file << rand() << " ";
    }

    file.close();
}

void TestFunctions::generate_almost_sorted_data_500_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    for (int i = 0; i <= 500; ++i) {
        file << i << " ";
    }

    srand(time(nullptr));

    for (int i = 0; i < 5; ++i) {
        int random_index = rand() % 500;
        int random_number = rand() % 9 + 1;
        file.seekp(random_index * sizeof(int)); // перемещаем указатель записи
        file << random_number << " ";
    }

    file.close();
}

void TestFunctions::generate_data_with_duplicates_200_elements(const string& filename) {
    
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    srand(time(nullptr));

    for (int i = 0; i < 200; ++i) {
        int random_number = rand() % 100;
        file << random_number << " ";
    }

    file.close();
}

void TestFunctions::generate_data_with_negatives_100_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    srand(std::time(nullptr));

    vector<int> data(100);
    for (int& num : data) {
        num = -rand() % 100; 
    }

    for (const int& num : data) {
        file << num << " ";
    }
    file.close();
}

void TestFunctions::generate_reverse_order_data_100_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    for (size_t i = 100; i > 0; --i) {
        file << i << " ";
    }
    file.close();
}

void TestFunctions::generate_large_range_data_100_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }
    srand(std::time(nullptr));

    vector<int> data(100);
    for (int& num : data) {
        num = (rand() % 999991) + 10; 
    }

    for (const int& num : data) {
        file << num << " ";
    }

    file.close();
}

void TestFunctions::generate_identical_elements_data_50_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }
    int value = (rand() % 101);

    for (size_t i = 0; i < 50; ++i) {
        file << value << " ";
    }
    file.close();
}

void TestFunctions::generate_zeros_and_positives_data_100_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);

    
    vector<int> data(100);
    for (int i = 0; i < 50; ++i) {
        data[i] = 0; 
    }
    for (int i = 50; i < 100; ++i) {
        data[i] = dis(gen); 
    }

    shuffle(data.begin(), data.end(), gen);

    for (const int& num : data) {
        file << num << " ";
    }

    file.close();

}

void TestFunctions::generate_zeros_and_negatives_data_100_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);


    vector<int> data(100);
    for (int i = 0; i < 50; ++i) {
        data[i] = 0;
    }
    for (int i = 50; i < 100; ++i) {
        data[i] = -dis(gen);
    }

    shuffle(data.begin(), data.end(), gen);

    for (const int& num : data) {
        file << num << " ";
    }

    file.close();
}

void TestFunctions::generate_alternating_values_data_50_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    int value1 = (rand() % 101);
    int value2 = 101 + (rand() % 100);
    int value3 = 201 + (rand() % 100);

    for (size_t i = 0; i < 50; ++i) {
        file << value3 << " "<< value2<< " " << value1 << " ";
    }
    file.close();
}

void TestFunctions::generate_alternating_positive_negative_data_100_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);


    vector<int> data(100);
    for (int i = 0; i < 50; ++i) {
        data[i] = dis(gen);
    }
    for (int i = 50; i < 100; ++i) {
        data[i] = -dis(gen);
    }

    shuffle(data.begin(), data.end(), gen);

    for (const int& num : data) {
        file << num << " ";
    }

    file.close();
}

void TestFunctions::generate_large_numbers_data_50_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    srand(std::time(nullptr));

    for (int i = 0; i < 100; ++i) {
        int num = rand() % 1000000 + 900001; 
        file << num << " ";
    }

    file.close();
}

void TestFunctions::generate_large_data_set_10000_elements(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    srand(time(nullptr));

    for (int i = 0; i < 10000; ++i) {
        file << rand() << " ";
    }

    file.close();
}

void TestFunctions::generate_single_element_data(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }
    int value = (rand() % 101);
    file << value<<" ";
    file.close();
}

void TestFunctions::test_1_simple_sort_generate_random_data_500_elements()
{
    cout << "1.Описание тестовых данных:\n";
    cout << "Случайный набор данных	1000 элементов ";
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    TestFunctions test1;
    const string t1 = "test_1.txt";
    test1.generate_random_data_500_elements(t1);
    Print_File(t1);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t1);
    graphic_division();
    SimpleSort Stest1;
    Stest1.Simple_Merging_Sort("test_1.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t1);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t1);
    graphic_division();
}

void TestFunctions::test_2_simple_sort_generate_almost_sorted_data_500_elements()
{
    cout << "2.Описание тестовых данных:\n";
    cout << "Почти отсортированный набор данных	500 элементов ";
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    TestFunctions test2;
    const string t2 = "test_2.txt";
    test2.generate_almost_sorted_data_500_elements(t2);
    Print_File(t2);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t2);
    graphic_division();
    SimpleSort Stest2;
    Stest2.Simple_Merging_Sort("test_2.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t2);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t2);
    graphic_division();
}

void TestFunctions::test_3_simple_sort_generate_data_with_duplicates_200_elements()
{
    cout << "3.Описание тестовых данных:\n";
    cout << "Набор данных с дубликатами	200 элементов ";
    TestFunctions test3;
    const string t3 = "test_3.txt";
    test3.generate_data_with_duplicates_200_elements(t3);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t3);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t3);
    graphic_division();
    SimpleSort Stest3;
    Stest3.Simple_Merging_Sort("test_3.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t3);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t3);
    graphic_division();
}

void TestFunctions::test_4_simple_sort_generate_data_with_negatives_100_elements()
{
    cout << "4.Описание тестовых данных:\n";
    cout << "Набор данных с отрицательными числами	100 элементов ";
    TestFunctions test4;
    const string t4 = "test_4.txt";
    test4.generate_data_with_negatives_100_elements(t4);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t4);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t4);
    graphic_division();
    SimpleSort Stest4;
    Stest4.Simple_Merging_Sort("test_4.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t4);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t4);
    graphic_division();
}

void TestFunctions::test_5_simple_sort_generate_reverse_order_data_100_elements()
{
    cout << "5.Описание тестовых данных:\n";
    cout << "Набор данных, где числа расположены в обратном порядке	100 элементов ";
    TestFunctions test5;
    const string t5 = "test_5.txt";
    test5.generate_reverse_order_data_100_elements(t5);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t5);
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t5);
    graphic_division();
    SimpleSort Stest5;
    Stest5.Simple_Merging_Sort("test_5.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t5);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t5);
    graphic_division();
}

void TestFunctions::test_6_simple_sort_generate_large_range_data_100_elements()
{
    cout << "6.Описание тестовых данных:\n";
    cout << "Набор данных с большим диапазоном чисел	100 элементов ";
    TestFunctions test6;
    const string t6 = "test_6.txt";
    test6.generate_large_range_data_100_elements(t6);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t6);
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t6);
    graphic_division();
    SimpleSort Stest6;
    Stest6.Simple_Merging_Sort("test_6.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t6);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t6);
    graphic_division();
}

void TestFunctions::test_7_simple_sort_generate_identical_elements_data_50_elements()
{
    cout << "7.Описание тестовых данных:\n";
    cout << "Набор данных с одинаковыми элементами	50 элементов ";
    TestFunctions test7;
    const string t7 = "test_7.txt";
    test7.generate_identical_elements_data_50_elements(t7);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t7);
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t7);
    graphic_division();
    SimpleSort Stest7;
    Stest7.Simple_Merging_Sort("test_7.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t7);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t7);
    graphic_division();
}

void TestFunctions::test_8_simple_sort_generate_zeros_and_positives_data_100_elements()
{
    cout << "8.Описание тестовых данных:\n";
    cout << "Набор элементов с нулями и положительными числами	100 элементов ";
    TestFunctions test8;
    const string t8 = "test_8.txt";
    test8.generate_zeros_and_positives_data_100_elements(t8);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t8);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t8);
    graphic_division();
    SimpleSort Stest8;
    Stest8.Simple_Merging_Sort("test_8.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t8);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t8);
    graphic_division();
}

void TestFunctions::test_9_simple_sort_generate_zeros_and_negatives_data_100_elements()
{
    cout << "9.Описание тестовых данных:\n";
    cout << "Набор элементов с нулями и отрицательными числами	100 элементов ";
    TestFunctions test9;
    const string t9 = "test_9.txt";
    test9.generate_zeros_and_negatives_data_100_elements(t9);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t9);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t9);
    graphic_division();
    SimpleSort Stest9;
    Stest9.Simple_Merging_Sort("test_9.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t9);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t9);
    graphic_division();
}

void TestFunctions::test_10_simple_sort_generate_alternating_values_data_50_elements()
{
    cout << "10.Описание тестовых данных:\n";
    cout << "Набор данных с чередующимися значениями	50 элементов ";
    TestFunctions test10;
    const string t10 = "test_10.txt";
    test10.generate_alternating_values_data_50_elements(t10);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t10);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t10);
    graphic_division();
    SimpleSort Stest10;
    Stest10.Simple_Merging_Sort("test_10.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t10);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t10);
    graphic_division();
}

void TestFunctions::test_11_simple_sort_generate_alternating_positive_negative_data_100_elements()
{
    cout << "11.Описание тестовых данных:\n";
    cout << "Набор данных с чередованием положительных и отрицательных чисел	100 элементов ";
    TestFunctions test11;
    const string t11 = "test_11.txt";
    test11.generate_alternating_positive_negative_data_100_elements(t11);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t11);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t11);
    graphic_division();
    SimpleSort Stest11;
    Stest11.Simple_Merging_Sort("test_11.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t11);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t11);
    graphic_division();
}

void TestFunctions::test_12_simple_sort_generate_large_numbers_data_50_elements()
{
    cout << "12.Описание тестовых данных:\n";
    cout << "Набор данных с большими числами (больше 900000)	50 элементов ";
    TestFunctions test12;
    const string t12 = "test_12.txt";
    test12.generate_large_numbers_data_50_elements(t12);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t12);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t12);
    graphic_division();
    SimpleSort Stest12;
    Stest12.Simple_Merging_Sort("test_12.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t12);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t12);
    graphic_division();
}

void TestFunctions::test_13_simple_sort_generate_large_data_set_10000_elements()
{
    cout << "13.Описание тестовых данных:\n";
    cout << "Большой набор данных	10000 элементов";
    TestFunctions test13;
    const string t13 = "test_13.txt";
    test13.generate_large_data_set_10000_elements(t13);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t13);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t13);
    graphic_division();
    SimpleSort Stest13;
    Stest13.Simple_Merging_Sort("test_13.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t13);
    graphic_division();
    cout << "\nПроверка, что файл отсортирован: ";
    file_sorted(t13);
    graphic_division();

}

void TestFunctions::test_14_simple_sort_generate_single_element_data()
{
    cout << "14.Описание тестовых данных:\n";
    cout << "Большой набор данных	100000 элементов";
    TestFunctions test14;
    const string t14 = "test_14.txt";
    test14.generate_single_element_data(t14);
    graphic_division();
    cout << "Вывод исходного файла: ";
    graphic_division();
    Print_File(t14);

    graphic_division();
    SimpleSort Stest14;
    Stest14.Simple_Merging_Sort("test_14.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма простого слияния: ";
    graphic_division();
    Print_File(t14);
    graphic_division();
    cout << "\nПроверка, что файл отсортирован: ";
    file_sorted(t14);
    graphic_division();
}


void TestFunctions::test_1_natural_sort_generate_random_data_500_elements()
{
    cout << "1.Описание тестовых данных:\n";
    cout << "Случайный набор данных	1000 элементов ";
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    TestFunctions test1;
    const string t1 = "test_1.txt";
    test1.generate_random_data_500_elements(t1);
    Print_File(t1);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t1);
    graphic_division();
    NaturalSort Stest1;
    Stest1.Natural_Merging_Sort("test_1.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t1);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t1);
    graphic_division();
}

void TestFunctions::test_2_natural_sort_generate_almost_sorted_data_500_elements()
{
    cout << "2.Описание тестовых данных:\n";
    cout << "Почти отсортированный набор данных	500 элементов ";
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    TestFunctions test2;
    const string t2 = "test_2.txt";
    test2.generate_almost_sorted_data_500_elements(t2);
    Print_File(t2);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t2);
    graphic_division();
    NaturalSort Stest2;
    Stest2.Natural_Merging_Sort("test_2.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t2);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t2);
    graphic_division();
}

void TestFunctions::test_3_natural_sort_generate_data_with_duplicates_200_elements()
{
    cout << "3.Описание тестовых данных:\n";
    cout << "Набор данных с дубликатами	200 элементов ";
    TestFunctions test3;
    const string t3 = "test_3.txt";
    test3.generate_data_with_duplicates_200_elements(t3);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t3);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t3);
    graphic_division();
    NaturalSort Stest3;
    Stest3.Natural_Merging_Sort("test_3.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t3);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t3);
    graphic_division();
}

void TestFunctions::test_4_natural_sort_generate_data_with_negatives_100_elements()
{
    cout << "4.Описание тестовых данных:\n";
    cout << "Набор данных с отрицательными числами	100 элементов ";
    TestFunctions test4;
    const string t4 = "test_4.txt";
    test4.generate_data_with_negatives_100_elements(t4);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t4);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t4);
    graphic_division();
    NaturalSort Stest4;
    Stest4.Natural_Merging_Sort("test_4.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t4);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t4);
    graphic_division();
}

void TestFunctions::test_5_natural_sort_generate_reverse_order_data_100_elements()
{
    cout << "5.Описание тестовых данных:\n";
    cout << "Набор данных, где числа расположены в обратном порядке	100 элементов ";
    TestFunctions test5;
    const string t5 = "test_5.txt";
    test5.generate_reverse_order_data_100_elements(t5);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t5);
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t5);
    graphic_division();
    NaturalSort Stest5;
    Stest5.Natural_Merging_Sort("test_5.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t5);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t5);
    graphic_division();
}

void TestFunctions::test_6_natural_sort_generate_large_range_data_100_elements()
{
    cout << "6.Описание тестовых данных:\n";
    cout << "Набор данных с большим диапазоном чисел	100 элементов ";
    TestFunctions test6;
    const string t6 = "test_6.txt";
    test6.generate_large_range_data_100_elements(t6);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t6);
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t6);
    graphic_division();
    NaturalSort Stest6;
    Stest6.Natural_Merging_Sort("test_6.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t6);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t6);
    graphic_division();
}

void TestFunctions::test_7_natural_sort_generate_identical_elements_data_50_elements()
{
    cout << "7.Описание тестовых данных:\n";
    cout << "Набор данных с одинаковыми элементами	50 элементов ";
    TestFunctions test7;
    const string t7 = "test_7.txt";
    test7.generate_identical_elements_data_50_elements(t7);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t7);
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t7);
    graphic_division();
    NaturalSort Stest7;
    Stest7.Natural_Merging_Sort("test_7.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t7);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t7);
    graphic_division();
}

void TestFunctions::test_8_natural_sort_generate_zeros_and_positives_data_100_elements()
{
    cout << "8.Описание тестовых данных:\n";
    cout << "Набор элементов с нулями и положительными числами	100 элементов ";
    TestFunctions test8;
    const string t8 = "test_8.txt";
    test8.generate_zeros_and_positives_data_100_elements(t8);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t8);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t8);
    graphic_division();
    NaturalSort Stest8;
    Stest8.Natural_Merging_Sort("test_8.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t8);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t8);
    graphic_division();
}

void TestFunctions::test_9_natural_sort_generate_zeros_and_negatives_data_100_elements()
{
    cout << "9.Описание тестовых данных:\n";
    cout << "Набор элементов с нулями и отрицательными числами	100 элементов ";
    TestFunctions test9;
    const string t9 = "test_9.txt";
    test9.generate_zeros_and_negatives_data_100_elements(t9);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t9);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t9);
    graphic_division();
    NaturalSort Stest9;
    Stest9.Natural_Merging_Sort("test_9.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t9);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t9);
    graphic_division();
}

void TestFunctions::test_10_natural_sort_generate_alternating_values_data_50_elements()
{
    cout << "10.Описание тестовых данных:\n";
    cout << "Набор данных с чередующимися значениями	50 элементов ";
    TestFunctions test10;
    const string t10 = "test_10.txt";
    test10.generate_alternating_values_data_50_elements(t10);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t10);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t10);
    graphic_division();
    NaturalSort Stest10;
    Stest10.Natural_Merging_Sort("test_10.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t10);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t10);
    graphic_division();
}

void TestFunctions::test_11_natural_sort_generate_alternating_positive_negative_data_100_elements()
{
    cout << "11.Описание тестовых данных:\n";
    cout << "Набор данных с чередованием положительных и отрицательных чисел	100 элементов ";
    TestFunctions test11;
    const string t11 = "test_11.txt";
    test11.generate_alternating_positive_negative_data_100_elements(t11);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t11);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t11);
    graphic_division();
    NaturalSort Stest11;
    Stest11.Natural_Merging_Sort("test_11.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t11);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t11);
    graphic_division();
}

void TestFunctions::test_12_natural_sort_generate_large_numbers_data_50_elements()
{
    cout << "12.Описание тестовых данных:\n";
    cout << "Набор данных с большими числами (больше 900000)	50 элементов ";
    TestFunctions test12;
    const string t12 = "test_12.txt";
    test12.generate_large_numbers_data_50_elements(t12);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t12);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t12);
    graphic_division();
    NaturalSort Stest12;
    Stest12.Natural_Merging_Sort("test_12.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t12);
    graphic_division();
    cout << "Проверка, что файл отсортирован: ";
    file_sorted(t12);
    graphic_division();
}

void TestFunctions::test_13_natural_sort_generate_large_data_set_10000_elements()
{
    cout << "13.Описание тестовых данных:\n";
    cout << "Большой набор данных	10000 элементов";
    TestFunctions test13;
    const string t13 = "test_13.txt";
    test13.generate_large_data_set_10000_elements(t13);
    graphic_division();
    cout << "Вывод неотсортированного файла: ";
    graphic_division();
    Print_File(t13);
    graphic_division();
    cout << "Проверка, что исходный файл действительно не отсортирован: ";
    file_sorted(t13);
    graphic_division();
    NaturalSort Stest13;
    Stest13.Natural_Merging_Sort("test_13.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t13);
    graphic_division();
    cout << "\nПроверка, что файл отсортирован: ";
    file_sorted(t13);
    graphic_division();

}

void TestFunctions::test_14_natural_sort_generate_single_element_data()
{
    cout << "14.Описание тестовых данных:\n";
    cout << "Большой набор данных	100000 элементов";
    TestFunctions test14;
    const string t14 = "test_14.txt";
    test14.generate_single_element_data(t14);
    graphic_division();
    cout << "Вывод исходного файла: ";
    graphic_division();
    Print_File(t14);

    graphic_division();
    NaturalSort Stest14;
    Stest14.Natural_Merging_Sort("test_14.txt");
    graphic_division();
    cout << "Вывод отсортированного файла, после алгоритма естественного слияния: ";
    graphic_division();
    Print_File(t14);
    graphic_division();
    cout << "\nПроверка, что файл отсортирован: ";
    file_sorted(t14);
    graphic_division();
}

