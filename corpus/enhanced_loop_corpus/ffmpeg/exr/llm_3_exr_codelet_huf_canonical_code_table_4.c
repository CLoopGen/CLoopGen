#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t c;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using indirect indexing via an index map
    int indices[59];
    for (int j = 0; j < 59; ++j) {
        indices[j] = 58 - j; // Reverse order stored sequentially
    }
    for (i = 0; i < 58; ++i) {
        int idx = indices[i]; // Indirect access through index array
        uint64_t nc = ((c + n[idx]) >> 1);
        n[idx] = c;
        c = nc;
    }
}
