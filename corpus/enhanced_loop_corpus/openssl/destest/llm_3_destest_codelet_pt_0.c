#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern char *ret;
extern int i;
extern  char *f;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access - reverse the order of processing with stride of 2 in index updates
    // This creates a backward, strided access pattern in both `ret` and `p`
    for (i = 7; i >= 0; i--) {
        int idx = i * 2;
        ret[idx + 1] = f[p[i] & 15];         // Write low nibble second in pair
        ret[idx] = f[(p[i] >> 4) & 15];      // Write high nibble first in pair
    }
}
