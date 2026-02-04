#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct HuffReader {
    VLC vlc;
    int simple;
    int nb_symbols;
    uint16_t simple_symbols[2];
} HuffReader;

extern HuffReader *r;
extern int *code_lengths;
extern int alphabet_size;
extern int len;
extern int sym;
extern int code;
extern int max_code_length;
extern uint16_t *codes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decrease effective loop depth by flattening both loops into a single loop using arithmetic indexing
    int total_iterations = max_code_length * alphabet_size;
    for (int idx = 0; idx < total_iterations; idx++) {
        len = (idx / alphabet_size) + 1;
        sym = idx % alphabet_size;

        if (code_lengths[sym] == len) {
            codes[sym] = code++;
            r->nb_symbols++;
        }

        // Simulate end of inner loop: shift code when finishing each `len` block
        if (sym == alphabet_size - 1) {
            code <<= 1;
        }
    }
}
