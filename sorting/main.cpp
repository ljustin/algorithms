#include <iostream>

using namespace std;

// given an array of integers,
// split the array into halves and recursively 
// call merge_sort on each sub-arrays.
// after which we merge the two sub-arrays into one array.

void merge(int leftArray[], int leftArrayLength, int rightArray[], int rightArrayLength, int dest[])
{
    int destIndex = 0;
    int leftArrayIndex = 0;
    int rightArrayIndex = 0;
    
    while (leftArrayIndex < leftArrayLength  && rightArrayIndex < rightArrayLength)
    {
        if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex])
        {
            dest[destIndex] = leftArray[leftArrayIndex++];
        }
        else
        {
            dest[destIndex] = rightArray[rightArrayIndex++];
        }
        destIndex++;
    }
    
    while (leftArrayIndex < leftArrayLength) dest[destIndex++] = leftArray[leftArrayIndex++];
    while (rightArrayIndex < rightArrayLength) dest[destIndex++] = rightArray[rightArrayIndex++];
}

void merge_sort(int a[], int length)
{
    if (length < 2)
        return;
    
    int mid = length / 2;
    
    int *leftArray = new int[mid];
    for (int i=0; i<mid; i++)
        leftArray[i] = a[i];

    int *rightArray = new int[length - mid];
    for (int i=mid; i<length; i++)
        rightArray[i-mid] = a[i];
    
    merge_sort(leftArray, mid);
    merge_sort(rightArray, length-mid);
    
    merge(leftArray, mid, rightArray, length-mid, a);
    
    delete[] leftArray;
    delete[] rightArray;

}

void printArray(int array[], int length)
{
    for (int i=0; i<length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int array1[] = {5, 4, 6, 2, 1, 9, 11};
    
    printArray(array1, sizeof(array1)/sizeof(int));
    merge_sort(array1, sizeof(array1)/sizeof(int));
    printArray(array1, sizeof(array1)/sizeof(int));
    
    int array2[] = {7, 2, 5, 3, 4, 15, 2, 1};
    
    printArray(array2, sizeof(array2)/sizeof(int));
    merge_sort(array2, sizeof(array2)/sizeof(int));
    printArray(array2, sizeof(array2)/sizeof(int));
    
    string stop;
    cin >> stop;
    return 0;
}
