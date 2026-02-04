#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__;
extern real tmp[4];
extern real temp;
extern integer jpiv[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp1, temp2;
    for (i__ = 1; i__ <= 3; ++i__) {
        integer idx1 = 4 - i__ - 1;
        integer idx2 = jpiv[4 - i__ - 1] - 1;
        if (jpiv[idx1] != 4 - i__) {
            temp1 = tmp[idx1];
            temp2 = tmp[idx2];
            tmp[idx1] = temp2;
            tmp[idx2] = temp1;
        }
    }
}
