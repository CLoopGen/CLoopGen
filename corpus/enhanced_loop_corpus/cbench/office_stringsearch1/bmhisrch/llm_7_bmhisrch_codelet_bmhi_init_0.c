#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_skip[258]; // Local buffer to introduce WAW and WAR dependencies intentionally
    for (i = 0; i <= (127 * 2 + 1); ++i) {
        temp_skip[i] = patlen; // Write to temporary array first (WAW dependency on temp_skip)
        skip[i] = temp_skip[i]; // Read what was just written (RAW: read after write from same iteration)
    }
    // Introduces intra-loop data dependencies and isolates global writes until after computation
}
