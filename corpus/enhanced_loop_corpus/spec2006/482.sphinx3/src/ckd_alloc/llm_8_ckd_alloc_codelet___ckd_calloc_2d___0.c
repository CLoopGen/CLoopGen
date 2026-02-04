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
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    for (i = 0, offset = 0; i < d1 / 2; i++, offset += d2 * elemsize * 2) {
        ref[i] = mem + offset;
        ref[d1 - i - 1] = mem + offset + d2 * elemsize;
    }
}
