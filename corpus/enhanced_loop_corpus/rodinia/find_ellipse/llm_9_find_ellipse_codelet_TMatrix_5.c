#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < N; i++) {
        bindex[i] = i * i - 2 * i + 1; // Equivalent to (i-1)^2, increasing arithmetic intensity
        for (j = 0; j < 3; j++) {
            bindex[i] += j; // Add small computational overhead with inner loop
        }
    }
}
