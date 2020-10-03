
#include <iostream>

using namespace std;

int mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int countInversion(int arr[], int array_size)
{
    int temp[array_size];
    return mergeSort(arr, temp, 0, array_size);
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if(right>left)
    {
        // midpoint to split the array
        mid = (right + left) / 2;
        // Add inversions in left and right sub-arrays
        inv_count += mergeSort(arr, temp, left, mid);   // left sub-array
        inv_count += mergeSort(arr, temp, mid+1, right);

        // inversions in the merge step
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;   /* i --> index of left sub-array */
    int j = mid+1;  /* j --> index for right sub-array */
    int k = left;   /* k --> index for resultant array temp */
    int inv_count = 0;  // inversion count

    while((i <= mid) && (j <= right))
    {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // tricky; may vary depending on selection of sub-array
        }
    } 
    // Add remaining elements from the larger subarray to the end of temp
    while( i <= mid)
        temp[k++] = arr[i++];
    while( j <= right)
        temp[k++] = arr[j++];
    // Copy temp[] to arr[]
    for( k=left; k<=right; k++)
    {
        arr[k] = temp[k];
    }
    return inv_count;
}

void show(int arr[], int array_size)
{   
    cout<< "Printing array: \n";
    for( int i=0; i<array_size; i++){
        cout<<" "<< arr[i];
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    // Declare the array
    int *arr = new int[size];

    cout << "Enter elements --> "<< endl;
    for( int i=0; i<size; i++)
    {
        cout << "Element "<< (i+1) << ": ";
        cin >> arr[i];
    }

    cout << endl;
    show(arr, size);

    // Counting inversions
    cout << endl << "The number of inversions: "<< countInversion(arr, size) << endl;

    // Output sorted array
    cout << endl << "Sorted array -->  "<< endl;
    show(arr, size);

    delete[] arr; 
    return 0;
}
/** @author [Rakshit Raj](https://github.com/rakshitraj) */