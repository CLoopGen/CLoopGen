#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 100; i += 2) {
        count[i] = 0;
        edge[i] = 0;
        if (i + 1 < 100) {
            count[i + 1] = 0;
            edge[i + 1] = 0;
        }
    }
}
