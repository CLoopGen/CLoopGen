#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int sum_of_weights;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 8; i++)
            sum_of_weights += table[i];
}
