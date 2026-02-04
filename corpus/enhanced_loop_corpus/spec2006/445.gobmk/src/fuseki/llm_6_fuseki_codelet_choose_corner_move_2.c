#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int sum_of_weights;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (i = 0; i < 8; i++)
        temp_sum += table[i];
    sum_of_weights += temp_sum;
}
