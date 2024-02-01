#include <iostream>
#include <random>
#include <chrono>
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"
using namespace std;
using namespace std::chrono;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-100000, 100000);
    int max_times = 100;
    int max_size = 500;

    //INSERTIONSORT
    cout << "Insertionsort data" << endl;
    for (int size = 100; size <= max_size; size += 100)
    {
        nanoseconds total(0);
        int* array = new int[size];
        for (int times = 0; times < max_times; times++)
        {
            for (int j = 0; j < size; j++)
            {
                array[j] = dist(gen);
            }
            auto start = steady_clock::now();
            InsertionSort(array, size);
            auto end = steady_clock::now();
            nanoseconds time_taken = duration_cast<nanoseconds>(end - start);
            total += time_taken;
        }
        total /= max_times;

        cout << size << " " << total.count() << endl;
        delete[] array;
    }

    //MERGESORT
    cout << "Mergingsort data: " << endl;
    for (int size = 100; size <= max_size; size += 100)
    {
        nanoseconds total(0);
        int* array = new int[size];
        for (int times = 0; times < max_times; times++)
        {
            for (int j = 0; j < size; j++)
            {
                array[j] = dist(gen);
            }
            auto start = steady_clock::now();
            mergesort(array, 0, size - 1);
            auto end = steady_clock::now();
            nanoseconds time_taken = duration_cast<nanoseconds>(end - start);
            total += time_taken;
        }
        total /= max_times;

        cout << size << " " << total.count() << endl;
        delete[] array;
    }

    //QUICKSORT
    cout << "Quicksort data: " << endl;
    for (int size = 100; size <= max_size; size += 100)
    {
        nanoseconds total(0);
        int* array = new int[size];
        for (int times = 0; times < max_times; times++)
        {
            for (int j = 0; j < size; j++)
            {
                array[j] = dist(gen);
            }
            auto start = steady_clock::now();
            quickSort2(array, 0, size - 1);
            auto end = steady_clock::now();
            nanoseconds time_taken = duration_cast<nanoseconds>(end - start);
            total += time_taken;
        }
        total /= max_times;

        cout << size << " " << total.count() << endl;
        delete[] array;
    }

    //HEAPSORT
    cout << "Heapsort data: " << endl;
    for (int size = 100; size <= max_size; size += 100)
    {
        nanoseconds total(0);
        int* array = new int[size];
        for (int times = 0; times < max_times; times++)
        {
            for (int j = 0; j < size; j++)
            {
                array[j] = dist(gen);
            }
            auto start = steady_clock::now();
            heapSort(array, size);
            auto end = steady_clock::now();
            nanoseconds time_taken = duration_cast<nanoseconds>(end - start);
            total += time_taken;
        }
        total /= max_times;

        cout << size << " " << total.count() << endl;
        delete[] array;
    }


    return 0;
}

