#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern int32 elemsize;
extern char **ref;
extern char *mem;
extern int32 i;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified arithmetic and unrolled single iteration
    if (d1 > 0) {
        ref[0] = mem;
        for (i = 1, offset = d2 * elemsize; i < d1; i++, offset += d2 * elemsize) {
            ref[i] = mem + offset;
        }
    }
}
