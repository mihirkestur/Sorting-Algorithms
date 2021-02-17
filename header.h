extern int algo;
time_t start_time,end_time;
extern long long int comparisons;
extern double duration;

//algorithms
void selection_sort_implementation(int *, int);
void bubble_sort_implementation(int *, int);
void merge_sort_implementation(int *, int, int);
void merge_sort_assist(int *, int, int, int);
void quick_sort_implementation(int *, int, int);
int quick_sort_assist(int *, int, int);

//helper functions
void display(int *, int); //display the array 
int instantiate_randomlist(int *, int); //creates the array of random numbers
void start_clock(); //assigns time to start time
void stop_clock(); //assigns time to end time
void resetshow_comparisons(); //resets comparisons variable to 0
void write_file(int, int); //write the data to csv file