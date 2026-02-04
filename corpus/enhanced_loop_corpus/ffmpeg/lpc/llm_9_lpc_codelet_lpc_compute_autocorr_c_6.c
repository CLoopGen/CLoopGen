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
    // Variant 2: Reduced arithmetic density with increased loop iterations and simplified body
    for (i = j - 1; i < len; i++) {
        sum += data[i] * data[i - j];
    }
}
