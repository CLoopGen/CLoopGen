#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word scalauto;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 160; k--; ) {
        for (int inner = 0; inner < 1; inner++) {
            *s++ <<= scalauto;
        }
    }
}
