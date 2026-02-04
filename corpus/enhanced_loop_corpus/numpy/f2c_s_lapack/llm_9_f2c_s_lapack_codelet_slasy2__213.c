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
for (i__ = 2; i__ <= 3; ++i__) {
    integer a = 4 - i__;
    integer b = jpiv[a - 1] - 1;
    integer c = a - 1;
    if (jpiv[c] != a) {
        temp = tmp[c];
        tmp[c] = tmp[b];
        tmp[b] = temp;
        
        tmp[0] += tmp[1];
        tmp[1] *= 0.5f;
        tmp[2] -= tmp[0];
    }
}
}
