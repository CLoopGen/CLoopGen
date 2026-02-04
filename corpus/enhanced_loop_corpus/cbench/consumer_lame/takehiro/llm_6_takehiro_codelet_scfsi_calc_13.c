#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int ch;
extern III_scalefac_t scalefac[2][2];
extern int s2;
extern int c2;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_s2 = s2; // Local accumulator to remove loop-carried dependency on 's2'
    int temp_c2 = c2; // Local accumulator to remove dependency on 'c2'

    for (; sfb < 21; sfb++) {
        int val = scalefac[1][ch].l[sfb];
        if (val < 0)
            continue;
        temp_c2++;                // Update local counter
        if (temp_s2 < val)
            temp_s2 = val;        // Update local max
    }

    // Write back accumulated results to maintain correctness
    s2 = temp_s2;
    c2 = temp_c2;
}
