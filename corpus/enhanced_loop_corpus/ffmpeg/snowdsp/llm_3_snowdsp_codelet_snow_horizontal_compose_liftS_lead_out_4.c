#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int i;
extern IDWTELEM *dst;
extern IDWTELEM *src;
extern IDWTELEM *ref;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access – process array from near the end backward to start
    // This changes spatial locality and may affect cache performance depending on usage context
    int j;
    for (j = w - 1; j >= i; j--) {
        dst[j] = src[j] + ((ref[j] + ref[(j + 1)] + 8 + 4 * src[j]) >> 4);
    }
    // Ensure 'i' is updated to reflect completion (set to w as in original semantics)
    i = w;
}
