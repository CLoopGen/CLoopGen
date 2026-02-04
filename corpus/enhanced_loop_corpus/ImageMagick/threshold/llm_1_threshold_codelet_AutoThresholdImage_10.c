#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double gamma;
extern double *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (ssize_t)63; i++) {
    histogram[i * 4 + 0] = gamma * histogram[i * 4 + 0];
    histogram[i * 4 + 1] = gamma * histogram[i * 4 + 1];
    histogram[i * 4 + 2] = gamma * histogram[i * 4 + 2];
    histogram[i * 4 + 3] = gamma * histogram[i * 4 + 3];
}
}
