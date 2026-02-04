#include <stdio.h>

#include <inttypes.h>

extern int primes;
extern int bitsr[5];
extern int i;
extern int quo;
extern int rmd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < primes && i < 5; i++) {
        bitsr[i] = quo;
        if (i < rmd && rmd > 0)
            bitsr[i] = quo + 1;
    }
}
