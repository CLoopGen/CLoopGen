#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint8_t pix[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - write one component at a time across multiple iterations
    // Simulate strided access by writing all R, then G, then B components with stride of p1
    int stride = p1;
    for (i = 0; i < p1; i++) {
        output[i] = pix[0];  // All reds first
    }
    for (i = 0; i < p1; i++) {
        output[stride + i] = pix[1];  // Then greens
    }
    for (i = 0; i < p1; i++) {
        output[2*stride + i] = pix[2];  // Then blues
    }
    output += 3 * p1;  // Update output pointer to reflect advancement
}
