#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < n; i++)
            data[i] = data[i] / (1.F + ((data[i]) >= 0 ? (data[i]) : (-(data[i]))));
}
