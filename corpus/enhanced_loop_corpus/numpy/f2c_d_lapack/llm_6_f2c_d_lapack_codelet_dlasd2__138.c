#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp[4];
    for (j = 1; j <= 4; ++j) {
        temp[j - 1] = ctot[j - 1];
    }
    for (j = 1; j <= 4; ++j) {
        coltyp[j] = temp[j - 1];
    }
}
