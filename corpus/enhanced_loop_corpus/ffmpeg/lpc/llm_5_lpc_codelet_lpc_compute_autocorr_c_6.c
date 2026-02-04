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
    for (i = j - 1; i < len && (i + 1) < len; i += 2) {
        double temp1 = data[i] * data[i - j];
        double temp2 = data[i + 1] * data[i - j + 1];
        if (temp1 > 0 || temp2 > 0) {
            sum += temp1 + temp2;
        }
    }
}
