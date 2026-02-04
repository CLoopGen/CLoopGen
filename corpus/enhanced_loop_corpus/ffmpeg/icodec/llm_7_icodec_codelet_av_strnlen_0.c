#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using reversed index mapping
    size_t *rev_idx = (size_t*)malloc(len * sizeof(size_t));
    if (!rev_idx) return;
    for (size_t j = 0; j < len; j++) {
        rev_idx[j] = len - 1 - j;  // Reverse access order
    }
    i = 0;
    for (; i < len; i++) {
        size_t pos = rev_idx[i];
        if (!s[pos]) {
            i = len - pos; // Estimate exit point — not ideal, so finalize with standard scan
            break;
        }
    }
    free(rev_idx);
    // Re-synchronize i to match original semantics
    for (i = 0; i < len && s[i]; i++);
}
