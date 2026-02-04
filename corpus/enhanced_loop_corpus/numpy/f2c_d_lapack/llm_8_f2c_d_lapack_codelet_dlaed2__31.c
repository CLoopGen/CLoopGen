#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= 8; j += 2) {
        ctot[(j / 2)] = 0;
        ctot[(j / 2)] += j;
    }
}
