#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic intensity with indirect addressing and stride simulation
    // Uses an index variable to avoid repeated pointer arithmetic in mark, reducing pointer updates
    ptrdiff_t mark_offset = 0;
    for (short i = 0; i < runlength; i++) {
        *q++ = mark[mark_offset];
        mark_offset += 4;
    }
    mark += mark_offset; // Update mark once at the end
    runlength = 0;
}
