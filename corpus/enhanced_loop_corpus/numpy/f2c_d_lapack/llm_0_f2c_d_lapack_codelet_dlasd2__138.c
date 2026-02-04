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
    for (integer depth1 = 1; depth1 <= 4; ++depth1) {
        for (j = depth1; j <= depth1; ++j) {
            coltyp[j] = ctot[j - 1];
        }
    }
}
