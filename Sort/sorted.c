#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))


void printArray(int arr[], int n){
    
    printf("%s", "arr = ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
}

// bubble sort
void bubbleSort(int arr[], int n){
    int temp;

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// selection sort
void selectionSort(int arr[], int n){
    int temp;

    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        
        // compare and search the minimum element
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // swap the minimum and current element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// insertion sort
void insertionSort(int arr[], int n){
    int i;   // i point the bound of sorted array.
    int j;   // j used to compare with key and swap them.
    int key; // an element which is going to be compared and inserted correct position.
    
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while ((j >= 0) && (arr[j] > key)){
            arr[j+1] = arr[j];
            /** if you want to track the change of input array in each iteration, try these two lines.
             * arr[j] = key;
             * printArray(arr, n);
             */
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

//shell sort
void shellSort(int arr[], int n){
    int h;    // control subarray size
    int i, j; // used to perform insertion sort

    for (h = n / 2; h > 0; h /= 2){
        for (i = h; i < n; i++){
            int temp = arr[i];

            for (j = i; j >= h && arr[j-h] > temp; j -= h){
                arr[j] = arr[j-h];
            }
            arr[j] = temp;
        }
    }
}

// quick sort
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right){
    /** Hoare's Partition Algorithm
     * use two pointers to divide the input array
     * this method also called Hoare's Partition Algorithm
     * Parameter:
     *    left: index of the beginning element of arr
     *    right: index of the last element of arr
    */

    int leftPointer = left - 1;
    int rightPointer = right + 1;
    int pivot = arr[left];

    while (1){
        do { // left pointer
            leftPointer++;
        } while (arr[leftPointer] < pivot);

        do { // right pointer
            rightPointer--;
        } while (arr[rightPointer] > pivot);

    if (leftPointer >= rightPointer) return rightPointer;
    swap(&arr[leftPointer], &arr[rightPointer]);
   }
}

void quickSort(int arr[], int left, int right){
    /** use Hoare's partition to implement quick sort
     * Parameter:
     *     left: index of beginning element.
     *     right: index of last element.
     */
    
    if (left < right){
        int partiionIndex = partition(arr, left, right);
        quickSort(arr, left, partiionIndex);    // sort left array
        quickSort(arr, partiionIndex+1, right); // sort right array
    }
}

// merge sort
void merge(int arr[], int left, int middle, int right, int *mergedArray){
    /** merge left and right sub-array and assign to mergedArray
     * Parameter:
     *     left: index of left point which is beginning of left sub-array
     *     middle: index of middle point which is the partition point also
     *     right: index of right point which is the end of right sub-array
    */
    int i = left;       // control left sub-array
    int j = middle + 1; // control right sub-array
    int k = left;       // control merged list

    while ((i <= middle) && (j <= right)){
        if (arr[i] <= arr [j]){
            mergedArray[k++] = arr[i++]; // assign i/k then plus 1
        }
        else{
            mergedArray[k++] = arr[j++];
        }
    }

    // assign remaining sub-array if another done
    while (i <= middle){
        mergedArray[k++] = arr[i++];
    }
    while (j <= right){
        mergedArray[k++] = arr[j++];
    }

    // copy to original array
    for (i=left; i<=right; i++){
        arr[i] = mergedArray[i];
    }
}

void topDownMergeSort(int arr[], int left, int right, int *mergedArray){
    int middle = left + (right - left) / 2;

    if (left < right){
        topDownMergeSort(arr, left, middle, mergedArray);    // divide left sub-array
        topDownMergeSort(arr, middle+1, right, mergedArray); // divide right sub-array
        merge(arr, left, middle, right, mergedArray);
        /**
         * if you want to show the sorting procedure
         * add a parameter 'n' which is the lenght of input array 'arr'
         * then uncomment the following code
         * printArray(arr, n); // show sorting pdocedure 
         */
    }
}

void bottomUpMergeSort(int arr[], int n, int *mergedArray){
    int currSize;// current size of each sub-array
    int left; // leftmost index of left sub-array

    // merge sub-arry of size n to create sorted array of size 2*n
    for (currSize = 1; currSize <= n-1; currSize *= 2){

        // pick beginning point of each sub-array of size currSize
        for (left = 0; left < n-1 ; left += 2 * currSize){
            int middle = MIN(left + currSize - 1, n - 1);    // end index of left sub-array
            int right = MIN(left + 2 * currSize - 1, n - 1); // end index of right sub-array
            merge(arr, left, middle, right, mergedArray);
            //printArray(arr, n); // if you want to show the sorting process, uncomment this line
        }
    }
}

// heap sort
void heapify(int arr[], int root, int n){
    /** rearrange the array(0-index) to form a max heap
     * Parameter:
     *     arr: input array
     *     root: index of root
     *     n: array length
     */

    int child = 2 * root + 1; // left node by default
    int rootValue = arr[root];

    while (child < n){
        if ( (child + 1 < n) && (arr[child]  < arr[child + 1])){
            child++;
        }
        if (arr[child] <= rootValue){
            break;
        }
        else {
            arr[root] = arr[child];
            root = child;         // sink down and check next level
            child = 2 * root + 1;
        }
    }
    arr[root] = rootValue;
}

void heapSort(int arr[], int n){
    
    // heapify arr to form max heap
    for (int i = (n-1)/2; i >= 0; i--){
        heapify(arr, i, n);
    }

    for (int j = n-1; j > 0; j--){
        swap(&arr[0], &arr[j]);
        // printArray(arr, n); // if you want to show the procedure, uncomment this line
        heapify(arr, 0, j);
    }
}

// bucket sort
int getMax(int arr[], int n){
    int max = arr[0];

    for (int i=0; i<n; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int getMin(int arr[], int n){
    int min = arr[0];

    for (int i=0; i<n; i++){
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
void bucketSort(int arr[], int n){
    /** bucket sort
     * Variable:
     *     bucketCount: setup the bucket number ,if the tange between max and
     *                  min is small, then bucketCount can't too large.
     *     buckets: an 2-D array which save all buckets
     *     bucketSize: an 1-D array which save bucket size corresponding to buckets[i]
     */
    int bucketCount = 2;
    int min = getMin(arr, n);
    int max = getMax(arr, n);
    int range = (max - min) / bucketCount;

    int **buckets = (int **) malloc(bucketCount * sizeof(int *));  // each bucket
    int *bucketSize = (int *) calloc(bucketCount, sizeof(int *)); // record each bucket size

    // allocate each bucket size
    for (int i=0; i<bucketCount; i++){
        buckets[i] = (int *) malloc(n * sizeof(int*)); // maximum capacity of each bucket
    }

    // scatter the element to each bucket
    for (int i=0; i<n; i++){
        int index = (arr[i] - min) / range;

        if (index == bucketCount)
            index -= 1;
        buckets[index][bucketSize[index]++] = arr[i];
    }

    // sort each bucket
    for (int i=0; i<bucketCount; i++){
        if (bucketSize[i] > 0)
            insertionSort(buckets[i], bucketSize[i]);
    }

    // merge all bucket
    int index = 0;
    for (int i=0; i<bucketCount; i++){
        for (int j=0; j<bucketSize[i]; j++){
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSize);
}

// counting sort
void countSort(int arr[], int n){
    int max = getMax(arr, n);

    // compute frequency of each element
    int *countArr = calloc(max + 1, sizeof(arr[0]));
    for (int i = 0; i < n; i++)
        countArr[arr[i]]++;
    
    // compute presum of countArr
    for (int i = 1; i < max + 1; i++)
        countArr[i] += countArr[i-1];
    
    // sort from last to beginning
    int *sortedArr = malloc(sizeof(arr[0])*n);
    for (int i = n - 1; i >= 0; i--)
        sortedArr[--countArr[arr[i]]] = arr[i];
    
    // copy to original array
    for (int i = 0; i < n; i++)
        arr[i] = sortedArr[i];
    
    free(countArr);
    free(sortedArr);
}   

// radix sort
void sortedDigit(int arr[], int n, int digit){
    
    // compute frequency
    int *countArr = calloc(10, sizeof(arr[0])); // digit from 0 to 9
    for (int i = 0; i < n; i++)
        countArr[(arr[i] / digit) % 10]++;
    
    // conpute presum
    for (int i = 1; i < 10; i++)
        countArr[i] += countArr[i-1];
    
    // sort
    int *sortedArr = malloc(n * sizeof(arr[0]));
    for (int i = n - 1; i >= 0; i--)
        sortedArr[--countArr[(arr[i] / digit) % 10]] = arr[i];
    
    // copy to original array
    for (int i = 0; i < n; i++)
        arr[i] = sortedArr[i];
    
    free(countArr);
    free(sortedArr);
}

void radixSort(int arr[], int n){
    int max = getMax(arr, n);

    for (int digit = 1; max / digit > 0; digit *= 10){
        sortedDigit(arr, n, digit);
        /** printArray(arr, n);
         * if want to show sorting process
         * uncomment this line 
         */
    }
}

// function test
// int main (void){
//     int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     radixSort(arr, n);
//     printArray(arr, n);
//     return 0;
// }