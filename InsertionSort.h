#ifndef INSERTION_H
#define INSERTION_H

void InsertionSort(int array[], int size)
{
    int InsertTemp, Insert;
    for (int i = 1; i < size; i++)
    {
        InsertTemp = array[i];
        Insert = i - 1;
        while (Insert >= 0 && array[Insert] > InsertTemp)
        {
            array[Insert + 1] = array[Insert];
            Insert = Insert - 1;
        }
        array[Insert + 1] = InsertTemp;
    }
}
#endif  // INSERTION_H