#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int limit;
extern unsigned int re_index;
extern __attribute__((unused)) unsigned int re_cache;
extern unsigned int re_size_plus8;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access pattern simulation using array-like indexing
    // We simulate a strided read from an implied buffer by incrementing re_index in steps,
    // but unroll the bit-shifting logic into a simple consecutive progression.
    // Assume re_cache behavior is abstracted via re_index stepping.

    for (; i < limit && re_index < re_size_plus8; i++) {
        re_cache = (re_cache << 1);
        re_index++;
    }
}
