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
extern int mul;
extern int add;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element unrolled access with local caching
    // Improves spatial locality by accessing adjacent elements in sequence
    IDWTELEM *local_dst = dst + i;
    IDWTELEM *local_src = src + i;
    IDWTELEM *local_ref = ref + i;
    int local_w = w - i;

    for (int j = 0; j < local_w - 1; j++) {
        // Process current and next element using consecutive reference access
        local_dst[j] = local_src[j] - ((mul * (local_ref[j] + local_ref[j + 1]) + add) >> shift);
    }
    // Handle last element if needed
    if (local_w > 0 && (i + local_w - 1) == w - 1) {
        dst[w - 1] = src[w - 1] - ((mul * (ref[w - 1] + ref[w]) + add) >> shift);
    }
}
