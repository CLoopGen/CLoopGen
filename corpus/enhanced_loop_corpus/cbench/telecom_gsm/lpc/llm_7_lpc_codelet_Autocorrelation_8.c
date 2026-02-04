#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word scalauto;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word *local_s = s;
    int local_k = k;
    for (local_k = 160; local_k--; local_s++) {
        *local_s <<= scalauto;
    }
    s = local_s;
}
