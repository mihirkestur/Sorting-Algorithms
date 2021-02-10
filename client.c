#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"
int main(){
    //sizes : 100k, 150k, 200k up to 1000k
    srand(time(0));
    int size = 100000, random_array[size]; 
    instantiate_randomlist(random_array, size);

    //display(random_array, size);
    bubble_sort_implementation(random_array,size);
    selection_sort_implementation(random_array,size);
    //display(random_array, size);
    return 0;
}