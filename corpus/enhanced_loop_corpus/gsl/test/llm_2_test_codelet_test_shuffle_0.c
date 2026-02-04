#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[10][10];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every second element in a strided manner, then fill gaps)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j += 2) {
            count[i][j] = 0;
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 1; j < 10; j += 2) {
            count[i][j] = 0;
        }
    }
}
