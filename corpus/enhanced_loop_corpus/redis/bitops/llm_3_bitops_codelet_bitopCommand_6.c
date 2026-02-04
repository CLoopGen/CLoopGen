#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long numkeys;
extern unsigned long i;
extern unsigned long **lp;
extern unsigned long *lres;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order and alternating indices
    // Access the same logical data but in a strided, non-consecutive manner across lres components
    for (i = 1; i < numkeys; i++) {
        size_t base = k;
        lres[0] ^= lp[i][base + 0];
        lres[2] ^= lp[i][base + 2];
        lres[1] ^= lp[i][base + 1];
        lres[3] ^= lp[i][base + 3];
    }
}
