#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use strided memory access with reverse traversal to alter access pattern
int stride = 4;
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    // Traverse j in reverse and with a fixed stride for irregular access
    for (int j = width - 1; j >= 0; j -= stride) {
        // Process each stride position, ensuring bounds
        for (int s = 0; s < stride && j - s >= 0; s++) {
            int js = j - s;
            int shift = (10 + 1) / 2;
            int mask = (1 << shift) - 1;
            int factor = (1 << shift);

            int fine_idx = factor * (width * ((srcp[js]) >> shift) + js) + ((srcp[js]) & mask);
            int coarse_idx = factor * js + ((srcp[js]) >> shift);

            cfine[fine_idx]++;
            ccoarse[coarse_idx]++;
        }
    }
    srcp += src_linesize;
}
}
