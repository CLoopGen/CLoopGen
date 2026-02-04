#include <stdio.h>

#include <inttypes.h>

extern int primes;
extern int bitsr[5];
extern int i;
extern int quo;
extern int rmd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < primes * 2; i += 2) {
        temp = i >> 1;
        bitsr[temp] = (temp < rmd) ? (quo << 1) + 1 : quo << 1;
    }
}
