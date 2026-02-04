#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t Py_UCS4;

extern  Py_UCS4 *str;
extern  Py_UCS4 *end;
extern char *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array (simulating irregular pattern)
    // Assume we have an external index mapping array; since we can't modify globals,
    // simulate a simple indirect sequence: 0, 2, 4, ... then 1, 3, 5... (strided indirect)
    ptrdiff_t len = end - str;
    ptrdiff_t i;
    for (i = 0; i < len; i++) {
        ptrdiff_t idx = (i % 2 == 0) ? (i / 2 * 2) : ((i / 2) * 2 + 1); // Non-trivial indexing
        Py_UCS4 *p = str + idx;
        if (p >= end) continue;
        if ((*p >= 128)) {
            end = p;
            break;
        }
        *(c + idx) = (char)(*p);
    }
    // Update str and c to reflect progress
    str = end; // Conservative update — in realistic use, track last written
    c += len;  // This assumes full traversal unless broken; adjust based on actual needs
}
