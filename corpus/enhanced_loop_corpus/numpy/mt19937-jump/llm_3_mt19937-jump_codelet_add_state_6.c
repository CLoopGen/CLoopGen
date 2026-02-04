#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct s_mt19937_state {
    uint32_t key[624];
    int pos;
} mt19937_state;

extern mt19937_state *state1;
extern mt19937_state *state2;
extern int i;
extern int pt1;
extern int pt2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Traverse the array from high to low index to reverse access order
    for (i = 623; i >= 0; i--) {
        state1->key[i + (pt1 - 624)] ^= state2->key[i + (pt2 - 624)];
    }
    // Reset i to 624 to maintain original semantics (as original loop leaves i == 624 on exit)
    i = 624;
}
