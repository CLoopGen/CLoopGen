#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double b0;
extern double b1;
extern double b2;
extern double a1;
extern double a2;
extern int *clippings;
extern int disabled;
extern  int32_t *ibuf;
extern int32_t *obuf;
extern double i1;
extern double i2;
extern double o1;
extern double o2;
extern double wet;
extern double dry;
extern double out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) memory access using an index map
    // Simulates non-contiguous or reordered processing via an index array
    // In practice, idx_map could represent permutation, filtering, or scatter/gather patterns
    int *idx_map = (int*)malloc(len * sizeof(int));
    if (!idx_map) return; // Handle allocation failure

    // Create a simple indirect mapping: reverse order access
    for (int j = 0; j < len; j++) {
        idx_map[j] = len - 1 - j;
    }

    // Traverse the buffer indirectly in reversed index order
    for (i = 0; i + 1 < len; i++) {
        int idx_curr = idx_map[i];
        int idx_next = idx_map[i+1];

        // First sample via indirect access
        o2 = i2 * b2 + i1 * b1 + ibuf[idx_curr] * b0 + o2 * a2 + o1 * a1;
        i2 = ibuf[idx_curr];
        out = o2 * wet + i2 * dry;
        if (disabled) {
            obuf[idx_curr] = i2;
        } else if (out < (-2147483647 - 1)) {
            (*clippings)++;
            obuf[idx_curr] = (-2147483647 - 1);
        } else if (out > 2147483647) {
            (*clippings)++;
            obuf[idx_curr] = 2147483647;
        } else {
            obuf[idx_curr] = out;
        }

        // Second sample via next indirect index
        i++;
        if (i + 1 >= len) break; // Prevent overflow after increment
        idx_next = idx_map[i];

        o1 = i1 * b2 + i2 * b1 + ibuf[idx_next] * b0 + o1 * a2 + o2 * a1;
        i1 = ibuf[idx_next];
        out = o1 * wet + i1 * dry;
        if (disabled) {
            obuf[idx_next] = i1;
        } else if (out < (-2147483647 - 1)) {
            (*clippings)++;
            obuf[idx_next] = (-2147483647 - 1);
        } else if (out > 2147483647) {
            (*clippings)++;
            obuf[idx_next] = 2147483647;
        } else {
            obuf[idx_next] = out;
        }
    }

    free(idx_map); // Clean up allocated memory
}
