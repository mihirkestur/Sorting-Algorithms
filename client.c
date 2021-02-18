#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
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
    for(size = 10000; size <= 100000; size = size + 5000){
        printf("\nsize = %d\n",size);
        int *random_array = malloc(size*sizeof(long int));
        instantiate_randomlist(random_array, size);

        int *bubble = malloc(size*sizeof(long int));
        memcpy(bubble, random_array, sizeof(random_array)*size);
        int *selection = malloc(size*sizeof(long int));
        memcpy(selection, random_array, sizeof(random_array)*size);
        int *merge = malloc(size*sizeof(long int));
        memcpy(merge, random_array, sizeof(random_array)*size);
        int *quick = malloc(size*sizeof(long int));
        memcpy(quick, random_array, sizeof(random_array)*size);

        algo = 1;
        start_clock();
        bubble_sort_implementation(bubble,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();

        algo = 2;
        start_clock();
        selection_sort_implementation(selection,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();

        algo = 3;
        start_clock();
        merge_sort_implementation(merge,0,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();

        algo = 4;
        start_clock();
        quick_sort_implementation(quick,0,size);
        stop_clock();
        write_file(size,algo);
        resetshow_comparisons();

        free(random_array); free(bubble); free(selection); free(merge); free(quick);
    }
    return 0;
}