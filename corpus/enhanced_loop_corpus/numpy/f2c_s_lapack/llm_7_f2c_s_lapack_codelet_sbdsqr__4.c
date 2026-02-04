#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *e;
extern integer *info;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (e[i__] != 0.F) {
            (*info)++;
            e[0] = e[i__]; // Introduce WAW and RAW dependency: write to e[0] after reading e[i__]
        }
    }
}
