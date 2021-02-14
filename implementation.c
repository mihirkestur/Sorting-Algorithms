#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "header.h"

void start_clock(){
    start_time = clock();
}

void stop_clock(){
    end_time = clock();
}

double duration(){
    double duration = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("%f\n\n", duration);
}

int generate_random_number(){
    int i = rand();
    //printf("%d\t", i);
    return i;
}
int instantiate_randomlist(int random_array[], int size){
    for(int i = 0; i < size; i++){
        random_array[i] = generate_random_number();
    }
    return random_array[size];
}

void selection_sort_implementation(int array[],int size){
    int minimum_element_index,temp;
    for(int i = 0; i < size-1; i++){
        minimum_element_index = i;
        for(int j = i+1; j < size; j++){
            if(array[j] < array[minimum_element_index]){
                minimum_element_index = j;
            }
        }
        temp = array[minimum_element_index];
        array[minimum_element_index] = array[i];
        array[i] = temp;
    }
}
void bubble_sort_implementation(int array[], int size){
    int comparisons;
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void merge_sort_assist(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort_implementation(int array[],int low,int high){
    if (low < high) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = low + (high - low) / 2;
        // Sort first and second halves
        merge_sort_implementation(array, low, m);
        merge_sort_implementation(array, m + 1, high); 
        merge_sort_assist(array, low, m, high);
    }
}

int quick_sort_assist(int arr[], int low, int high){
    /* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot){ 
            i++;    // increment index of smaller element 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        } 
    } 
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1); 
}

void quick_sort_implementation(int arr[], int low, int high){
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
    if (low < high){ 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = quick_sort_assist(arr, low, high); 
        // Separately sort elements before 
        // partition and after partition 
        quick_sort_implementation(arr, low, pi - 1); 
        quick_sort_implementation(arr, pi + 1, high); 
    } 
}
void display(int array[],int size){
    //sizeof(array);
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d\n",array[i]);
    }
    printf("\n");
}