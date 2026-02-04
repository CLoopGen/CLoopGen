#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = alpha;
    for (i = 0; i < 10; i++) {
        // Simulate strided memory-like access pattern using a dummy array
        volatile float dummy[2] = {temp, temp * temp};
        temp = dummy[i % 2];  // Strided access: alternates between indices 0 and 1
    }
    alpha = temp;
}
