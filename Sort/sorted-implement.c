#include <stdio.h>
#include <stdlib.h>
#include "sorted.h"

int main(void){
    int arr[] = {23, 1, 10, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, n);

    /** bubble sort
     * bubbleSort(arr, n);
     * printArray(arr, n);
     */
    
    /** selection sort
     * selectionSort(arr, n);
     * printArray(arr, n);
     */

    /** insertion sort
     * insertionSort(arr, n);
     * printArray(arr, n);
     */

    /** shell sort
     *  shellSort(arr, n);
     *  printArray(arr, n);
     */    
    
    /** top-down merge sort
     * int *mergedArray = malloc(n * sizeof(arr[0]));
     * topDownMergeSort(arr, 0, n-1, mergedArray);
     * printArray(arr, n);
     * free(mergedArray);
     */

    /** bottom-up merge sort
     * int *mergedArray = malloc(n * sizeof(arr[0]));
     * bottomUpMergeSort(arr, n, mergedArray);
     * printArray(arr, n);
     * free(mergedArray); 
     */

    /** quick sort 
     * quickSort(arr, 0, n-1);
     * printArray(arr, n); 
     */

    /** heap sort
     * heapSort(arr, n);
     * printArray(arr, n);
     */

    /** bucket sort
     * bucketSort(arr, n);
     * printArray(arr, n);
     */

    /** counting sort 
     * this sort can try another array: arr[] = {4, 2, 2, 8, 3, 3, 1}
     * countSort(arr, n);
     * printArray(arr, n);
     */
    
    /** radix sort
     * this sort can try another array: {170, 45, 75, 90, 802, 24, 2, 66}
     * radixSort(arr, n);
     * printArray(arr, n);
     */
    
    return 0;
}