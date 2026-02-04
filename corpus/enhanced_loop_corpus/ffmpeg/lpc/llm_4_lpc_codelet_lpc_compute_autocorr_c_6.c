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
    for (i = j - 1; i < len; i += 2) {
        if (i >= j) {
            sum += data[i] * data[i - j] + data[i + 1] * data[i - j + 1];
        }
    }
}
