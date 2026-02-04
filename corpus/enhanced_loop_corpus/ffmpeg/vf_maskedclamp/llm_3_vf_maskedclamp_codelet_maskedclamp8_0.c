#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int undershoot;
extern int overshoot;
extern  uint8_t *bsrc;
extern  uint8_t *darksrc;
extern  uint8_t *brightsrc;
extern uint8_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    // Simulate indirect addressing via precomputed index mapping (e.g., bit-reversed or scrambled order)
    // Here we use a simple alternating front-back traversal as indirect pattern

    int *indices = (int*)malloc(w * sizeof(int));
    if (!indices) return; // Fail gracefully if allocation fails

    // Construct indirect access pattern: alternate from start and end
    int left = 0, right = w - 1;
    for (int i = 0; i < w; i++) {
        if (i % 2 == 0) {
            indices[i] = left++;
        } else {
            indices[i] = right--;
        }
    }

    // Traverse using the indirect indices
    for (int i = 0; i < w; i++) {
        int x = indices[i];
        dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
        dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
    }

    free(indices);
}
