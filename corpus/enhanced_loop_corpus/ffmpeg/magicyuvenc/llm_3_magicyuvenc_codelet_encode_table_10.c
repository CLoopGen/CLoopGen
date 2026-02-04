#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

extern PTable counts[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (reverse order access)
    int indices[256];
    for (i = 0; i < 256; i++) {
        indices[i] = 255 - i; // reverse indexing
    }
    for (i = 0; i < 256; i++) {
        int idx = indices[i];
        counts[idx].prob++;
        counts[idx].value = 255 - idx;
    }
}
