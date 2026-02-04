#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= 4; ++j) {
    ctot[j - 1] = 0;
    if (j == 2) continue;
}
}
