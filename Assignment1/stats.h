#ifndef stats_h
#define stats_h
#endif

#ifndef uint8
#define uint8 unsigned char
#endif

#ifndef uint
#define uint unsigned char
#endif


///declarations

//a function that prints the statistics of a data set, including minimum, maximum, mean, and median. 
void print_statistics( uint8 * data, uint length); 

// given an array of a data and a length, print the array nicely. 
void print_array(uint8 * data, uint length);


// given an array of a data and a length, find the median of the array. 
uint8 find_median(uint8 * data, uint length);

//given an array of a data and a length, find the mean of the array. 
uint8 find_mean(uint8 * data, uint length);

// given an array of a data and a length, find the maximum of the array. 
uint8 find_maximum(uint8 * data, uint length);

// given an array of a data and a length, find the minimum of the array. 
uint8 find_minimum(uint8 * data, uint length);

//sorts a given array of given length from largest to smallest. 
void sort_array(uint8 * data, uint length);


