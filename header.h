//extern int global_array[];
//extern int global_size;
time_t start_time,end_time;
extern int comparisons;
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
double duration(); //calculates difference
void reset_comparisons(); //resets comparisons variable to 0