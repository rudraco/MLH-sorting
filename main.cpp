#include <iostream>

using namespace std;

void merge_arr(int arr[],int start, int mid, int last)
{
    int size1= mid-start+1; //size of sub array 1
    int size2= last-mid; //size of sub array 2
    int Left[size1], Right[size2]; //Temp sub arrays

    //filling elements in temperory sub arrays
    for(int i=0;i<size1;i++)
        Left[i]=arr[start+i];
    for(int j=0; j<size2;j++)
        Right[j]=arr[mid+j+1];

    int i=0,j=0,k=start;

    while (i < size1 && j < size2) {
        //If element in left sub-array is small, store it
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        //If element in right sub-array is small, store it
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    //If elements in Left sub-array are remaining, store them
    while (i < size1) {
        arr[k] = Left[i];
        i++;
        k++;
    }
    //If elements in Right sub-array are remaining, store them
    while (j < size2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int start, int last)
{
    if (start<last)
    {
        int mid = (start + (last-1))/2;
        mergesort(arr,start,mid); //Recursion call for first half
        mergesort(arr,mid+1,last); //Recursion call for second half
        merge_arr(arr,start,mid,last); //Function to merge sub-arrays
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter elements of the array:\n";
    for (int i = 0; i < arr_size; i++)
        cin>> arr[i];

    mergesort(arr, 0, arr_size - 1);

    cout << "\nSorted array using Merge Sort is: \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";

    return 0;
}
