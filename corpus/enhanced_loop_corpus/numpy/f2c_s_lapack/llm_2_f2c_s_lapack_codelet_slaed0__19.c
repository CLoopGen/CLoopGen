#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element)
    for (j = 2; j <= i__1; j += 2) {
        if (j - 2 >= 2) {
            iwork[j] += iwork[j - 2];
        }
    }
}
