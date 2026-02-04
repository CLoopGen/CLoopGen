#include <stdio.h>

#include <inttypes.h>

extern int primes;
extern int bitsr[5];
extern int i;
extern int quo;
extern int rmd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < primes; i++)
            bitsr[i] = (i < rmd) ? quo + 1 : quo;
}
