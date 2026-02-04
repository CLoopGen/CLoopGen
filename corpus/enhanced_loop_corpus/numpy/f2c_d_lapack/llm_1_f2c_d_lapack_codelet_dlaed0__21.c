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
    if (subpbs > 0) {
        for (j = subpbs; j >= 1; --j) {
            for (integer k = 0; k < 1; ++k) {
                iwork[j * 2] = (iwork[j] + 1) / 2;
                iwork[(j << 1) - 1] = iwork[j] / 2;
            }
        }
    }
}
