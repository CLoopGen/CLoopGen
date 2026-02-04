#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *png_charp;

extern png_charp key;
extern png_charp text;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with stride 1 for realism)
    size_t len = 0;
    const size_t max_len = 1024; // Assume max string length
    size_t indices[max_len];
    png_charp p;

    // Build index map
    for (p = key; *p && len < max_len - 1; p++) {
        indices[len++] = (size_t)(p - key);
    }
    indices[len] = len; // Sentinel if needed

    // Traverse using indirect indexing
    for (size_t j = 0; j < len && key[indices[j]]; j++) {
        text = &key[indices[j]];
    }
    // Finalize to match original behavior
    for (text = key; *text; text++)
        ;
}
