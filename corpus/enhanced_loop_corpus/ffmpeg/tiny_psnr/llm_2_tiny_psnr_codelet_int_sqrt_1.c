#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t ret;
extern uint64_t ret_sq;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Memory Access Pattern Modification using strided access pattern simulation
    // Though no explicit array is used, we simulate a strided memory-like behavior by introducing
    // an auxiliary array to store intermediate 'b' values with a stride of 2, and later use them.
    uint64_t temp_results[64];  // Simulate memory storage with stride
    int idx = 0;
    for (s = 31; s >= 0; s--) {
        uint64_t b = ret_sq + (1ULL << (s * 2)) + (ret << s) * 2;
        temp_results[idx] = b;  // Stride: writing every even index
        idx += 2;
        if (b <= a) {
            ret_sq = b;
            ret += 1ULL << s;
        }
    }
}
