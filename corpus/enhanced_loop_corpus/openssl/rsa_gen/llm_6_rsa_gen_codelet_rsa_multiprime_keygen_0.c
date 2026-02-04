#include <stdio.h>

#include <inttypes.h>

extern int primes;
extern int bitsr[5];
extern int i;
extern int quo;
extern int rmd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_bitsr[5];
    for (i = 0; i < primes; i++) {
        temp_bitsr[i] = quo;
        if (i < rmd) {
            temp_bitsr[i] = quo + 1;
        }
    }
    for (i = 0; i < primes; i++) {
        bitsr[i] = temp_bitsr[i];
    }
}
