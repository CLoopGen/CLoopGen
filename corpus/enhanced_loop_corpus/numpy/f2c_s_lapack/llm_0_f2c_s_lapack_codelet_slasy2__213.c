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
for (i__ = 1; i__ <= 3; ++i__) {
    for (integer j = 0; j < 1; ++j) {
        if (jpiv[4 - i__ - 1] != 4 - i__) {
            temp = tmp[4 - i__ - 1];
            tmp[4 - i__ - 1] = tmp[jpiv[4 - i__ - 1] - 1];
            tmp[jpiv[4 - i__ - 1] - 1] = temp;
        }
    }
}
}
