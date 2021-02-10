#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "header.h"

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
    clock_t time = clock();
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
    time = clock() - time;
    double net_time = ((double)time)/CLOCKS_PER_SEC;
    printf("%f\n\n", net_time);
}
void bubble_sort_implementation(int array[], int size){
    clock_t time = clock();
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
    time = clock() - time;
    double net_time = ((double)time)/CLOCKS_PER_SEC;
    printf("%f\n\n", net_time);
}
void merge_sort_implementation(){
    clock_t time = clock();
    time = clock() - time;
    double net_time = ((double)time)/CLOCKS_PER_SEC;
    printf("%f\n\n", net_time);
}
void quick_sort_implementation(){
    clock_t time = clock();
    time = clock() - time;
    double net_time = ((double)time)/CLOCKS_PER_SEC;
    printf("%f\n\n", net_time);
}
void display(int array[],int size){
    //sizeof(array);
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d\n",array[i]);
    }
    printf("\n");
}