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
    // Variant 2: Strided and reversed indirect access with transformed array indexing
    for (i__ = 4; i__ >= 2; --i__) {
        integer rev_i = 4 - i__; // Transformed index: now accessing from high to low in steps
        integer src = rev_i;
        integer dst = jpiv[src] - 1;
        if (jpiv[src] != i__ - 1) {
            temp = tmp[src];
            tmp[src] = tmp[dst];
            tmp[dst] = temp;
        }
    }
}
