#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;
extern  int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = 0;
    for (i = 0; i < 16 * 16; i += 16) {
        dst[offset] = dc0; // Remove loop-carried dependence by using local offset
        offset += 16;      // Independent update, no WAW or WAR with memory accesses
    }
}
