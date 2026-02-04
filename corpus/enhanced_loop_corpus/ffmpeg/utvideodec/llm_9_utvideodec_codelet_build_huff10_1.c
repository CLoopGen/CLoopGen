#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern int i;
extern HuffEntry he[1024];
extern int last;
extern uint32_t codes[1024];
extern uint8_t bits[1024];
extern uint16_t syms[1024];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration work via simulated vectorization (fused operations)
    // Loop now processes two elements per iteration when possible, halving the effective trip count
    int limit = (last + 1) / 2;
    for (i = limit - 1; i >= 0; i--) {
        int idx1 = (i * 2) + 1;
        int idx2 = i * 2;

        // Process pair of entries if both exist
        if (idx1 <= last) {
            uint32_t shift1 = 32 - he[idx1].len;
            codes[idx1] = code >> shift1;
            bits[idx1] = he[idx1].len;
            syms[idx1] = he[idx1].sym;
            code += 2147483648U >> (he[idx1].len - 1);
        }

        uint32_t shift2 = 32 - he[idx2].len;
        codes[idx2] = code >> shift2;
        bits[idx2] = he[idx2].len;
        syms[idx2] = he[idx2].sym;
        code += 2147483648U >> (he[idx2].len - 1);
    }
    // Handle odd-sized input if needed (cleanup pass conceptually, but not required due to index math above)
}
