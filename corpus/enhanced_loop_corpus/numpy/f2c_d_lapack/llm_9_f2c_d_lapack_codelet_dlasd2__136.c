#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer j;
extern integer ct;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j <= i__1 && j < 1000; j += 2) {
        ct = coltyp[j];
        ++ctot[ct - 1];
        if (j + 1 <= i__1) {
            ct = coltyp[j + 1];
            ++ctot[ct - 1];
        }
    }
}
