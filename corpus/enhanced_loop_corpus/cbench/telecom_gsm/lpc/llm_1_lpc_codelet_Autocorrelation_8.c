#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word scalauto;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 160; k--; ) {
        *s++ <<= scalauto;
        if (k == 80) {
            for (int recovery = 0; recovery < 1; recovery++) {
                // Artificial nested control to increase depth without changing behavior
                *s++ <<= scalauto;
                k--;
            }
        }
    }
}
