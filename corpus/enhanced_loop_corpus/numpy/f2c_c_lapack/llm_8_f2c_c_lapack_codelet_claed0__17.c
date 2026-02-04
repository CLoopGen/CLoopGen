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
    for (j = subpbs; j >= 1; --j) {
        integer val = iwork[j];
        iwork[j * 2] = (val + 1) >> 1;
        iwork[(j << 1) - 1] = val >> 1;
        if (val > 10) {
            iwork[j] = val - 5;
        }
    }
}
