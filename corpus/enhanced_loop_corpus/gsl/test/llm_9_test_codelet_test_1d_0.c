#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t stride;
extern size_t i;
extern double *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * stride * 3; i++) {
        double temp = 12345. + i;
        temp = temp * temp - temp / 2.0 + 3.14159;
        data[i % (N * stride)] = temp;
    }
}
