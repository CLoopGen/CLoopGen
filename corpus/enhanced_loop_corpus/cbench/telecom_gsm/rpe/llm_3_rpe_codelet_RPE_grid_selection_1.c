#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *x;
extern word *xM;
extern int i;
extern word Mc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration order (still using for loop)
    for (i = 12; i >= 0; i--) {
        xM[i] = x[Mc + 3 * i];
    }
}
