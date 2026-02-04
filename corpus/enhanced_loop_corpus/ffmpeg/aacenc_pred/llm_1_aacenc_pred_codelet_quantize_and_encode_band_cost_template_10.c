#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern int i;
extern float cost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = size / 1000 + 1;
    int chunk = size / outer + 1;
    for (i = 0; i < size; i += chunk) {
        int end = i + chunk;
        if (end > size) end = size;
        for (int k = i; k < end; k++) {
            cost += in[k] * in[k];
        }
    }
}
