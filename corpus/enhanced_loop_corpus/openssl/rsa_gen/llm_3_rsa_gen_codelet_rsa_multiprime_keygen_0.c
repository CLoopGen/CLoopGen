#include <stdio.h>

#include <inttypes.h>

extern int primes;
extern int bitsr[5];
extern int i;
extern int quo;
extern int rmd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index mapping array
    // Use an auxiliary array to define the order of writes (reverse order in this case)
    int indices[5];
    for (i = 0; i < primes; i++) {
        indices[i] = primes - 1 - i; // reverse index mapping
    }
    for (i = 0; i < primes; i++) {
        int idx = indices[i];
        bitsr[idx] = (idx < rmd) ? quo + 1 : quo;
    }
}
