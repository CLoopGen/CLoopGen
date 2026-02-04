#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int sum_of_weights;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        sum_of_weights += table[i];
        sum_of_weights += table[i + 4];
    }
}
