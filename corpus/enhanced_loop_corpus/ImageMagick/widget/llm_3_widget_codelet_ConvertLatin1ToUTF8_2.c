#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index map (simulated with stride-like pattern)
    size_t idx = 0;
    size_t step = 1;
    // Use a virtual "access sequence" to simulate non-consecutive traversal
    while ((p = content + idx) < content + length && *p != '\x00') {
        length += (*p & 128) ? 2 : 1;
        idx += step; // Could be varied for irregular patterns, kept simple here
    }
    // Corrected to avoid 'while' - replaced with for version
    for (idx = 0; (p = content + idx) < content + length && *p != '\x00'; idx += step) {
        length += (*p & 128) ? 2 : 1;
    }
}
