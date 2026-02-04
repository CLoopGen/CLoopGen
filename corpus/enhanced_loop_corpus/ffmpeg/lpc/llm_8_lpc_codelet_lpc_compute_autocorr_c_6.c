#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *data;
extern int len;
extern int i;
extern int j;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    for (i = j - 1; i < len - 1; i += 4) {
        sum += data[i] * data[i - j] + data[i + 1] * data[i - j + 1];
        if (i + 2 < len) {
            sum += data[i + 2] * data[i - j + 2] + data[i + 3] * data[i - j + 3];
        }
    }
    // Handle potential leftover element when step is 4
    if (i == len - 1) {
        sum += data[i] * data[i - j];
    }
}
