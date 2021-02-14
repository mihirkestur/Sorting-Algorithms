#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"
int main(){
    //sizes : 100k, 150k, 200k up to 1000k
    //seeding
    srand(time(0));
    
    int size = 1000000, random_array[size]; 
    instantiate_randomlist(random_array, size);

    start_clock();
    //bubble_sort_implementation(random_array,size);
    stop_clock();
    duration();

    instantiate_randomlist(random_array, size);
    
    start_clock();
    //selection_sort_implementation(random_array,size);
    stop_clock();
    duration();

    instantiate_randomlist(random_array, size);
    
    start_clock();
    merge_sort_implementation(random_array,0,size);
    stop_clock();
    duration();

    instantiate_randomlist(random_array, size);
    
    start_clock();
    quick_sort_implementation(random_array,0,size);
    stop_clock();
    duration();
    //display(random_array, size);
    return 0;
}