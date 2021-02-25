//Mihir Madhusudan Kestur     PES1UG19CS272    4E_1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "header.h"

int main(){
    //seeding for random number generation
    srand(time(0));
    /*
    1:bubble sort
    2:selection sort
    3:merge sort
    4:quick sort
    */
    int size = 0;
    //start clock, ALGORITHM, stop clock, update csv, resetshow comparisons
    //sizes : 100k, 150k, 200k up to 1000k
    for(size = 100000; size <= 1000000; size = size + 50000){
        printf("\nsize = %d\n",size);
        //generate a random array of current size
        int *random_array = malloc(size*sizeof(long int));
        instantiate_randomlist(random_array, size);
        //make 4 copies of the above random array for each algorithm so that sorting is benchmarked against same random array
        int *bubble = malloc(size*sizeof(long int));
        memcpy(bubble, random_array, sizeof(random_array)*size);
        int *selection = malloc(size*sizeof(long int));
        memcpy(selection, random_array, sizeof(random_array)*size);
        int *merge = malloc(size*sizeof(long int));
        memcpy(merge, random_array, sizeof(random_array)*size);
        int *quick = malloc(size*sizeof(long int));
        memcpy(quick, random_array, sizeof(random_array)*size);

        //bubble sort
        start_clock();
        bubble_sort_implementation(bubble,size);
        stop_clock();
        write_file(size,"bubble_time.csv","bubble_comp.csv");
        resetshow_comparisons();

        //selection sort
        start_clock();
        selection_sort_implementation(selection,size);
        stop_clock();
        write_file(size,"selection_time.csv","selection_comp.csv");
        resetshow_comparisons();

        //merge sort
        start_clock();
        merge_sort_implementation(merge,0,size);
        stop_clock();
        write_file(size,"merge_time.csv","merge_comp.csv");
        resetshow_comparisons();

        //quick sort
        start_clock();
        quick_sort_implementation(quick,0,size);
        stop_clock();
        write_file(size,"quick_time.csv","quick_comp.csv");
        resetshow_comparisons();

        free(random_array); free(bubble); free(selection); free(merge); free(quick);
    }
    return 0;
}