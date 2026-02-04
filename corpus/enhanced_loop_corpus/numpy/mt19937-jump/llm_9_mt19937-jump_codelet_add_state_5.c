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
    for (; i < (624 - pt2) && i < 300; i++) {
        uint32_t val = state2->key[i + pt2];
        state1->key[i + (pt1 - 624)] ^= val ^ (val << 5) ^ (val >> 7);
        i++; // Double increment effect — higher trip frequency but reduced effective iterations
        if (i < (624 - pt2)) {
            state1->key[i + (pt1 - 624)] ^= state2->key[i + pt2] ^ 0xCAFEBABE;
        }
    }
}
