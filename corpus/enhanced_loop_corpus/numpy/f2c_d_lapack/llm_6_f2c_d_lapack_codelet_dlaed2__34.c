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
    // Variant 1: Introduce a loop-carried WAW dependency by reordering writes with a temporary variable
    // This changes the write order but preserves final values written to coltyp
    integer temp[4];
    for (j = 1; j <= 4; ++j) {
        temp[j - 1] = ctot[j - 1];  // Store in temp first (removes direct RAW from coltyp)
    }
    for (j = 1; j <= 4; ++j) {
        coltyp[j] = temp[j - 1];    // Write from temp, creating a WAW-like pattern across iterations if unrolled
    }
}
