#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Changes the memory access direction from ascending to descending
    // Alters spatial locality and may affect cache behavior depending on usage context
    for (i__ = i__1; i__ >= 1; --i__) {
        coltyp[i__] = 1;
    }
}
