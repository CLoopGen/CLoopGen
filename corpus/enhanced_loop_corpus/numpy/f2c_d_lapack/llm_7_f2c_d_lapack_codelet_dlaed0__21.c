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
    for (j = 1; j <= subpbs; ++j) {
        iwork[(j << 1) - 1] = iwork[j] / 2;
        iwork[j * 2] = (iwork[j] + 1) / 2;
    }
}
