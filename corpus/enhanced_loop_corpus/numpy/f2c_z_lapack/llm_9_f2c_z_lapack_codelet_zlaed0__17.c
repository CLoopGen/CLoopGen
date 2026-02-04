#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer j;
extern integer subpbs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified operations and elimination of one computation
    for (j = subpbs; j >= 2; j -= 2) {
        integer temp = iwork[j];
        iwork[j * 2] = (temp + 1) >> 1;
        if (j > 1) {
            iwork[(j - 1) * 2] = (iwork[j - 1] + 1) >> 1;
        }
    }
}
