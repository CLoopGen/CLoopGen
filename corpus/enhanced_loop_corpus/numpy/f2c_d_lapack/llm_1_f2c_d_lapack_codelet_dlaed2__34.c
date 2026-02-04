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
    for (j = 1; j <= 2; ++j) {
        for (integer k = 0; k <= 1; ++k) {
            integer idx = 2 * k + j;
            if (idx <= 4) {
                coltyp[idx] = ctot[idx - 1];
            }
        }
    }
}
