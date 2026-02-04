#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int sfb;
extern int max_slen1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled loop characteristics
    for (sfb = 0; sfb < 11; sfb += 2) {
        if (scalefac->l[sfb] > max_slen1)
            max_slen1 = scalefac->l[sfb];
    }
    // Handle remaining element if any due to stride
    if (sfb == 11 - 1) {
        if (scalefac->l[10] > max_slen1)
            max_slen1 = scalefac->l[10];
    }
}
