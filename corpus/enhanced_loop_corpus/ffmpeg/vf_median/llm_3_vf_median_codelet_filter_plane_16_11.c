#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access by processing elements at non-unit stride
    // to simulate different memory bandwidth and cache behavior.
    int stride = 2;
    int shift = (16 + 1) / 2;
    int mask = (1 << shift) - 1;
    int coarse_scale = (1 << shift);
    int fine_scale = (1 << shift) * width;

    // Process every 'stride'-th element first, then handle remainder if needed
    for (int i = 0; i < width; i += stride) {
        // Ensure we don't go out of bounds on the last step
        if (i < width) {
            int high1 = srcp[i] >> shift;
            int low1 = srcp[i] & mask;
            cfine[fine_scale * high1 + fine_scale / width * i + low1] += radiusV + 1;
            ccoarse[coarse_scale * i + high1] += radiusV + 1;
        }
        int j = i + 1;
        if (j < width) {
            int high2 = srcp[j] >> shift;
            int low2 = srcp[j] & mask;
            cfine[fine_scale * high2 + fine_scale / width * j + low2] += radiusV + 1;
            ccoarse[coarse_scale * j + high2] += radiusV + 1;
        }
    }
}
