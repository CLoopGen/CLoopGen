#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *drp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access
    // Modify access pattern to copy every 2nd element in a strided manner,
    // simulating a different memory access stride while preserving data flow.
    // The total number of iterations is halved, but still covers logical range.
    for (k = 0; k <= 119; k += 2)
        drp[-120 + k] = drp[-80 + k];
    // Handle odd indices if needed, using a second pass with offset
    for (k = 1; k <= 119; k += 2)
        drp[-120 + k] = drp[-80 + k];
}
