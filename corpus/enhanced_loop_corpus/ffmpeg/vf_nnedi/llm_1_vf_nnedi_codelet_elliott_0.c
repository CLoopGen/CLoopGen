#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int chunk = 1;
    for (outer_i = 0; outer_i < n; outer_i += chunk) {
        for (i = outer_i; i < n && i < outer_i + chunk; i++)
            data[i] = data[i] / (1.F + ((data[i]) >= 0 ? (data[i]) : (-(data[i]))));
    }
}
