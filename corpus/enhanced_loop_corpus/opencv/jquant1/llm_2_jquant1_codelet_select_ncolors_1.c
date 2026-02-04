#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory-like access pattern using array indexing with stride
    int *dummy_array = (int*)malloc(nc * sizeof(int));
    for (i = 1; i < nc; i += 1) {
        // Simulate strided access by accessing every element consecutively but using index to influence computation
        dummy_array[i] = iroot;
        temp *= dummy_array[i];
    }
    free(dummy_array);
}
