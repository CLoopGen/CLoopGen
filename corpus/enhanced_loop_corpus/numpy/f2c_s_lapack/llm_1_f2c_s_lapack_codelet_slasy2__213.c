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
for (i__ = 1; i__ <= 1; ++i__) {
    for (integer k = 1; k <= 3; ++k) {
        integer idx = 4 - k - 1;
        if (jpiv[idx] != 4 - k) {
            temp = tmp[idx];
            tmp[idx] = tmp[jpiv[idx] - 1];
            tmp[jpiv[idx] - 1] = temp;
        }
    }
}
}
