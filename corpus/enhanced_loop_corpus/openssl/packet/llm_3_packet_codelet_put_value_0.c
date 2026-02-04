#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern uint64_t value;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (simulated via larger step logic)
    // Here we reverse the order but access every element with a stride of 1 
    // in a reversed manner using an offset array (indirect indexing).
    // This simulates indirect access pattern using precomputed offsets.
    int64_t *offsets = (int64_t*)__builtin_alloca(len * sizeof(int64_t));
    for (size_t i = 0; i < len; i++) {
        offsets[i] = (int64_t)(len - 1 - i); // Precompute reverse offsets
    }
    for (size_t i = 0; i < len; i++) {
        data[offsets[i]] = (unsigned char)(value & 255);
        value >>= 8;
    }
}
