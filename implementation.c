#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "header.h"
long int comparisons = 0;
double duration = 0;
void write_file(int size, int algo){
    FILE* fs = fopen("info.csv", "a");
    if(fs == NULL){
        printf("Couldn't open file\n");
        return;
    }
fprintf(fs, "%d,%d,%f,%ld\n",algo,size,duration,comparisons);
fclose(fs);
}

void resetshow_comparisons(){
    printf("comparisons = %ld\n",comparisons);
    comparisons = 0;
}
void start_clock(){
    start_time = clock();
}

void stop_clock(){
    end_time = clock();
    duration = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("duration = %f\n", duration);
}

int instantiate_randomlist(int random_array[], int size){
    for(int i = 0; i < size; i++){
        random_array[i] = rand();
    }
    return random_array[size];
}

void selection_sort_implementation(int array[],int size){
    int minimum_element_index,temp;
    for(int i = 0; i < size-1; i++){
        minimum_element_index = i;
        for(int j = i+1; j < size; j++){
            ++comparisons;
            if(array[j] < array[minimum_element_index]){
                ++comparisons;
                minimum_element_index = j;
            }
        }
        temp = array[minimum_element_index];
        array[minimum_element_index] = array[i];
        array[i] = temp;
    }
}
void bubble_sort_implementation(int array[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            ++comparisons;
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void merge_sort_assist(int array[], int low, int middle, int high){
    int n1 = middle - low + 1, n2 = high - middle, L[n1], R[n2];

    for (int i = 0; i < n1; i++){
        L[i] = array[low + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = array[middle + 1 + j];
    } 
    int i = 0, j = 0, k = low; 
    while(i < n1 && j < n2){
        ++comparisons;
        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort_implementation(int array[],int low,int high){
    ++comparisons;
    if (low < high) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = low + (high - low) / 2;
        merge_sort_implementation(array, low, m);
        merge_sort_implementation(array, m + 1, high); 
        merge_sort_assist(array, low, m, high);
    }
}

int quick_sort_assist(int arr[], int low, int high){
    int pivot = arr[high];     
    int i = (low - 1);  
    for(int j = low; j <= high- 1; j++){ 
        ++comparisons; 
        if(arr[j] < pivot){ 
            i++;    
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

void quick_sort_implementation(int array[], int low, int high){
    ++comparisons;
    if(low < high){ 
        int pi = quick_sort_assist(array, low, high); 
        quick_sort_implementation(array, low, pi - 1); 
        quick_sort_implementation(array, pi + 1, high); 
    } 
}
void display(int array[],int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d\n",array[i]);
    }
    printf("\n\n");
}