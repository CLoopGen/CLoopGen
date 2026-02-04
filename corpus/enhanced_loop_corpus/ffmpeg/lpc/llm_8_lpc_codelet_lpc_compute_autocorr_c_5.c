#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *data;
extern int len;
extern int lag;
extern double *autoc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < lag; j++) {
        double sum = 1.;
        for (i = j; i < len; i++) {
            sum += data[i] * data[i - j];
        }
        autoc[j] = sum;
    }
}
