#include <stdio.h>

#include <inttypes.h>

extern int primes;
extern int bitsr[5];
extern int i;
extern int quo;
extern int rmd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element first, then fill gaps)
    // Simulate a strided write pattern with step size 2, then handle remaining indices
    int stride = 2;
    for (i = 0; i < primes; i += stride) {
        bitsr[i] = (i < rmd) ? quo + 1 : quo;
    }
    for (i = 1; i < primes; i += stride) {
        bitsr[i] = (i < rmd) ? quo + 1 : quo;
    }
}
