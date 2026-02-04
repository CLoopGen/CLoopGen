#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using precomputed index array, accessed sequentially
    size_t *idx_arr = (size_t*)malloc(len * sizeof(size_t));
    if (!idx_arr) return;
    for (i = 0; i < len; i++) {
        idx_arr[i] = i; // Identity mapping for indirect access
    }
    for (i = 0; i < len; i++) {
        size_t pos = idx_arr[i];
        if (pos >= len || !s[pos]) {
            i = pos;
            break;
        }
    }
    if (i == len) i = len; // Ensure i reflects correct exit
    free(idx_arr);
}
