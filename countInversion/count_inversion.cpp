/**
 * 
 * @file
 * @brief Counting Inversions using Merge Sort
 *
 * @details
 * Program to count the number of inversions in an array
 * using merge-sort.
 * 
 * The count of inversions help to determine how close the array
 * is to being sorted in ASCENDING order.
 * 
 * two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
 * 
 * Time Complexity --> O(n.log n)
 * Space Complexity --> O(n) ; additional arrat temp[1..n]
 * Algorithm:
 *   1. The idea is similar to merge sort, divide the array into two equal or almost 
 *      equal halves in each step until the base case is reached.
 *   2. Create a function merge that counts the number of inversions when two halves of
 *      the array are merged, create two indices i and j, i is the index for first half 
 *      and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i)  
 *      inversions, Because left and right subarrays are sorted, so all the remaining elements 
 *      in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
 *   3. Create a recursive function to divide the array into halves and find the answer by summing 
 *      the number of inversions is the first half, number of inversion in the second half and 
 *      the number of inversions by merging the two.
 *   4. The base case of recursion is when there is only one element in the given half.
 *   5. Print the answer
 *
 * @author [Rakshit Raj](https://github.com/rakshitraj)
 * 
 */
#include <iostream>
#include <vector>

namespace sorting   {
namespace inversion {

int mergeSort(std::vector<int> &arr, std::vector<int> &temp, int left, int right);
int merge(std::vector<int> &arr, std::vector<int> &temp, int left, int mid, int right);
int countInversion(std::vector<int> &arr);
void show(const std::vector<int> &arr);

/**
 * Funtion countInversion() returns the number of inversion 
 * present in the input array. Inversions are an estimate of
 * how close or far off the array is to being sorted.
 * 
 * Number of inversions in a sorted array is 0.
 * Number of inversion in an array[1...n] sorted in 
 * non-ascending order is n(n-1)/2, since each pair of elements
 * contitute an inversion.
 * 
 * @param arr   - array, input for counting inversions in
 * @param array_size    - number of elementa in the array
 * @returns total number of inversions, int
 * 
 */
int countInversion(std::vector<int> &arr)
{
    std::vector<int> temp;
    return mergeSort(arr, temp, 0, arr.size()-1);
}

/**
 * @brief Implements Merge Sort Algorithm
 * @details
 * The mergeSort() function implements Merge Sort, a
 * Divide and conquer algorithm, it divides the input
 * array into two halves and calls itself for each 
 * sub-array and then calls the merge() function to 
 * merge the two halves.
 * 
 * @param arr   - array to be sorted
 * @param temp  - merged resultant array
 * @param left  - lower bound of array
 * @param right - upper bound of array
 * @returns  total number of inversions to calling function, int
 * 
 */
int mergeSort(std::vector<int> &arr, std::vector<int> &temp, int left, int right)
{   
    int mid = 0, inv_count=0;
    if(right>left)
    {
        // modpoint to split the array
        mid = (left + right)/2;
        // Add inversions in left and right sub-arrays
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid+1, right);

        // Inversions in the merge step
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

/**
 * @brief   Function to merge two sub-arrays
 * @details
 * merge() function is called 
 * from mergeSort() to merge the array after it split for sorting 
 * by the mergeSort() funtion.
 * 
 * In this case the merge fuction will also count and return 
 * inversions detected when merging the sub arrays.
 * 
 * @param arr    input array
 * @param temp   stores the resultant merged array
 * @param left   lower bound of arr[] and left-sub-array
 * @param mid    midpoint, upper bound of left sub-array,
 *               (mid+1) gives the lower bound of right-sub-array
 * @param right  upper bound of arr[] and right-sub-array
 * @returns number of inversions per merge step, int
 * 
 */
int merge(std::vector<int> &arr, std::vector<int> &temp, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;
    int inv_count = 0;

    while((i<=mid) && (j<=right))
    {
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count += (mid -i +1);
        }
    }

    while(i<=mid) { temp[k++] = arr[i++]; }
    while(j<=right) { temp[k++] = arr[j++]; }

    for( k=left; k<=right; k++)
    {
        arr[k] = temp[k];
    }

    // Keeping the capacity of temp contained to size
    temp.shrink_to_fit();

    return inv_count;
}

/**
 * @brief   UTILITY function to print array.
 * @param arr   array to print
 * @param array_size    size of input array arr[]
 * @returns void
 */
void show(const std::vector<int> &arr)
{   
    std::cout<< "Printing array: \n";
    for(int element: arr){
        std::cout<<" "<< element;
    }
    std::cout << "\n";
}

}   // namespace inversion
}   // namespace sorting

/**
 * @breif Main Function
 * @returns 0 on exit
 */
int main()
{
    std::vector<int> arr = {99, 98, 71, 40, 39, 38, 70, 69, 97, 26, 25, 24, 23, 81, 80, 79, 78, 22, 21};

    arr.shrink_to_fit(); // required if user inputs array
    std::cout << "\n";
    sorting::inversion::show(arr);
    std::cout << "\n";

    std::cout << "\nThe number of inversions: "<< sorting::inversion::countInversion(arr) << "\n";

    // Output sorted array
    std::cout << "\nSorted array -->  \n";
    sorting::inversion::show(arr);

    return 0;
}
