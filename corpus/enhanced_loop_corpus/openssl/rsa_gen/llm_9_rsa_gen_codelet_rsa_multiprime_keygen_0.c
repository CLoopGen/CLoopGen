#include <stdio.h>

#include <inttypes.h>

extern int primes;
extern int bitsr[5];
extern int i;
extern int quo;
extern int rmd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (primes + 3) / 4; i++) {
        int idx0 = 4 * i + 0;
        int idx1 = 4 * i + 1;
        int idx2 = 4 * i + 2;
        int idx3 = 4 * i + 3;
        if (idx0 < primes) bitsr[idx0] = (idx0 < rmd) ? quo + 1 : quo;
        if (idx1 < primes) bitsr[idx1] = (idx1 < rmd) ? quo + 1 : quo;
        if (idx2 < primes) bitsr[idx2] = (idx2 < rmd) ? quo + 1 : quo;
        if (idx3 < primes) bitsr[idx3] = (idx3 < rmd) ? quo + 1 : quo;
    }
}
