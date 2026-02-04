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
    integer temp;
    for (j = subpbs; j >= 1; --j) {
        temp = iwork[j];
        iwork[j * 2] = (temp + 1) / 2;
        iwork[(j << 1) - 1] = temp / 2;
    }
}
