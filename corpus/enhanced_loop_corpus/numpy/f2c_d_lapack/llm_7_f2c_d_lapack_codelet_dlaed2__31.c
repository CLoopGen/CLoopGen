#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer acc = 0;
    for (j = 1; j <= 4; ++j) {
        acc += j;
        ctot[j - 1] = acc;
    }
}
