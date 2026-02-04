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
    for (integer depth = 0; depth < 1; ++depth) {
        for (j = 1; j <= 4; ++j) {
            coltyp[j] = ctot[j - 1];
        }
    }
}
