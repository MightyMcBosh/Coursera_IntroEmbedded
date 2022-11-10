/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief This is the code file for assignment 1. 
 *
 * in this assignment, we are to do several statistical analyses on the data set
 * included in the file. 
 *
 * @author Benjamin Stewart
 * @date 11/9/2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  uint _size = (uint)SIZE; 
  printf("Initial Array:\r\n");
  print_array(test, _size); //print inital array
  sort_array(test,_size);
  printf("Sorted Array:\r\n");
  print_array(test, _size); //Sort it, print it again. Allow for visual verification of the data. 

  //calculate statistical values
  find_mean(test,_size);
  find_median(test,_size);
  find_maximum(test,_size);
  find_minimum(test,_size);


  print_statistics(test,_size); 

  printf("complete\r\n"); 

}

void print_statistics()
{
  printf("Mean: %i\r\n",stats_mean);
  printf("Median: %i\r\n",stats_mean);
  printf("Minimum: %i\r\n",stats_minimum);
  printf("Maximum: %i\r\n",stats_maximum);
}

void print_array (uint8 data[], uint length)
{
  for(int i = 0; i < length; i++)
  {
    printf("%i,",data[i]);
  }     
  printf("\r\n");
}

void sort_array(uint8 data[], uint length)
{
  
    //just use a basic insertion sort, it's not the most efficient but it's easy to implement in c, and it runs fast when it's already sorted
  uint8 current = data[0]; 
  for(int i = length - 1; i >= 0; i--)
  {
    for(int j = i-1; j >= 0; j--)
    { 
      if(data[j] > data[j + 1])
      {
        current = data[j]; 
        data[j] = data[j+1];
        data[j+1] = current; 
      }
      else
        break; 
    }
  }

}

uint8 find_mean(uint8 data[], uint length)
{
  uint total; 
  for(int i = 0; i < length; i++)
  {
    total += (uint)data[i];
  }  
  stats_mean = total / length;   
  return stats_mean; 
}

//Contract doesn't state if we can assume that the array is presorted, so sort first then find the values.
uint8 find_median(uint8 data[], uint length)
{
  sort_array(data,length); 
  stats_median = data[length/2]; 
  return stats_median; 
}

uint8 find_maximum(uint8 data[], uint length)
{
  sort_array(data,length); 
  stats_maximum = data[0];
  return stats_maximum; 
}

 
uint8 find_minimum(uint8 data[], uint length)
{
  sort_array(data,length); 
  stats_minimum = data[length -1];
  return stats_minimum;
}

