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

    system("pause");
    return 0;
}