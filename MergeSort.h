#ifndef MERGESORT_H
#define MERGESORT_H

void merge(int arr[], int left, int middle, int right) // middle = left + (right-left) / 2
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int* L = new int[n1], * R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];   // FIRST SUBARRAY [L....M]
    for (j = 0; j < n2; j++) // SECOND SUBARRAY [M+1.....R]
        R[j] = arr[middle + 1 + j];

    i = j = 0;
    k = left;

    while (i < n1 && j < n2) // COMPARING EACH ELEMENT OF THE TWO SUBARRAYS AND STORING THE SMALLEST IN THE MERGED ARRAY
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[i];
            j++;
        }
        k++;
    }
    while (i < n1) // IF ANY ELEMENTS ARE LEFT IN THE ARRAYS THESE TWO WHILE LOOPS STORES THEM IN K
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
#endif  // MERGESORT_H