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
if (j - 1 < len) {
    for (i = j - 1; i < len; i += 2) {
        for (int extra = 0; extra < 1; extra++) {
            sum += data[i] * data[i - j] + data[i + 1] * data[i - j + 1];
        }
    }
}
}
