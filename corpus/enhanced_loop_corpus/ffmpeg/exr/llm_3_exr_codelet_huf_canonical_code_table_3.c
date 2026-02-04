#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t *hcode;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive write access with indirect read remapping
    // Reorder the updates to n[] in a consecutive manner by first collecting indices,
    // then updating n[] in increasing order to improve spatial locality on writes.
    // We assume a buffer can be used temporarily (on-stack, small sample due to size limit)
    // Since full buffering may be expensive, we do blocking with local sorting over chunks.

    #define BLOCK 32
    uint64_t temp[BLOCK];
    int limit = (1 << 16) + 1;

    for (i = 0; i < limit; i += BLOCK) {
        int count = 0;
        // Collect block of indices
        for (int j = i; j < i + BLOCK && j < limit; ++j) {
            temp[count++] = hcode[j];
        }
        // Sort indices locally (simple insertion sort for small block)
        for (int j = 0; j < count; ++j) {
            for (int k = j + 1; k < count; ++k) {
                if (temp[j] > temp[k]) {
                    uint64_t swap = temp[j];
                    temp[j] = temp[k];
                    temp[k] = swap;
                }
            }
        }
        // Now update n[] in increasing index order (consecutive-like access)
        for (int j = 0; j < count; ++j) {
            if (temp[j] < 59) {
                n[temp[j]] += 1;
            }
        }
    }
}
