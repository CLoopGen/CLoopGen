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
    integer temp_j;
    for (temp_j = 1; temp_j <= 2; ++temp_j) {
        for (j = temp_j * 2 - 1; j <= temp_j * 2; ++j) {
            coltyp[j] = ctot[j - 1];
        }
    }
}
