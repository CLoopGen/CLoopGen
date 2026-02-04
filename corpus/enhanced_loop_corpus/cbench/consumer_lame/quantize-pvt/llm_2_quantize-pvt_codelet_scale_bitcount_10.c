#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int sfb;
extern int max_slen2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // Access pattern: l[11], l[13], l[15], l[17], l[19] (odd indices in original range)
    for (sfb = 11; sfb < 21; sfb += 2) {
        if (scalefac->l[sfb] > max_slen2)
            max_slen2 = scalefac->l[sfb];
    }
    // Handle remaining index if needed (sfb=20), but since step is 2 and we start at odd,
    // and 20 is even, it's outside the sequence. So no extra handling required.
}
