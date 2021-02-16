#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"
int main(){
    //sizes : 100k, 150k, 200k up to 1000k
    //seeding
    srand(time(0));
    /*
    0:no algorithm
    1:bubble sort
    2:selection sort
    3:merge sort
    4:quick sort
    */
    int algo = 0,size = 0;
    //start clock, ALGORITHM, stop clock, resetshow comparisons, update csv
    for(size = 10; size <= 100; size = size + 5){
        printf("\nsize = %d\n",size);
        int *random_array = malloc(size*sizeof(long int));
        
        instantiate_randomlist(random_array, size);
        algo = 1;
        start_clock();
        bubble_sort_implementation(random_array,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();
        //display(random_array, size);

        instantiate_randomlist(random_array, size);
        algo = 2;
        start_clock();
        selection_sort_implementation(random_array,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();
        //display(random_array, size);

        instantiate_randomlist(random_array, size);
        algo = 3;
        start_clock();
        merge_sort_implementation(random_array,0,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();
        //display(random_array, size);

        instantiate_randomlist(random_array, size);
        algo = 4;
        start_clock();
        quick_sort_implementation(random_array,0,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();
        //display(random_array, size);

        free(random_array);
    }
    return 0;
}