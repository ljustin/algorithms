#include <iostream>

using namespace std;

void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void swap(int& a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/*
    Repeatedly find the minimum element in the unsorted part of the array
    and place it at the end of the sorted part of the array.
*/
void selection_sort(int arr[], int length)
{
    for (int i = 0; i < length-1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}

/* 
    Repeatedly insert the element into the correct position in the
    sorte portion of the array.
*/
void insertion_sort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

/*
    Repeatedly compare the adjacent elements of the array
    left to right moving larger element to the beginning of the sorted portion of the array.
*/
void bubble_sort(int arr[], int length)
{
    for (int i = 0; i < length-1; i++)
    {
        for (int j = 0; j < length-i-1; j++)
        {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            else break;
        }
    }
}

/*
    merge the two sub-arrays -left and right into the destination array
    until both of them are empty.
*/
void merge(int leftArr[], int leftSize, int rightArr[], int rightSize, int destination[])
{
    int left = 0, right = 0, dest = 0;

    while (left < leftSize && right < rightSize)
    {
        // merge
        if (leftArr[left] <= rightArr[right])
        {
            destination[dest++] = leftArr[left++];
        }
        else
        {
            destination[dest++] = rightArr[right++];
        }
    }

    // take care of the remaining elements
    while (left < leftSize) destination[dest++] = leftArr[left++];
    while (right < rightSize) destination[dest++] = rightArr[right++];
}

/*
    Repeatedly divide the array into two sub-arrays -left and right until the sub-arrays get to size 1 
    after which we start merging two sub-arrays until we finally merge into the original array.
*/
void merge_sort(int arr[], int length)
{
    if (length < 2) return; // base condition

    int mid = length / 2;
    int* leftHalf = new int[mid];
    int* rightHalf = new int[length - mid];

    // copy the elements
    for (int i = 0; i < length; i++)
    {
        if (i < mid) leftHalf[i] = arr[i];
        else rightHalf[i-mid] = arr[i];
    }

    merge_sort(leftHalf, mid);
    merge_sort(rightHalf, length-mid);

    merge(leftHalf, mid, rightHalf, length - mid, arr);
    
    delete[] leftHalf;
    delete[] rightHalf;
}

int main(int argc, char** argv)
{
    int arr1[5] = { 5, 4, 3, 2, 1 };
    selection_sort(arr1, 5);
    printArr(arr1, 5);

    int arr2[5] = { 5, 4, 3, 2, 1 };
    insertion_sort(arr2, 5);
    printArr(arr2, 5);

    int arr3[5] = { 5, 4, 3, 2, 1 };
    bubble_sort(arr3, 5);
    printArr(arr3, 5);

    int arr4[5] = { 5, 4, 3, 2, 1 };
    merge_sort(arr4, 5);
    printArr(arr4, 5);

    system("pause");
    return 0;
}