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
    for (; i < 624; i++) {
        int idx1 = i + (pt1 - 624);
        int idx2 = i + (pt2 - 624);
        if (idx1 % 2 == 0) {
            state1->key[idx1] ^= state2->key[idx2];
        } else if (i % 4 == 0) {
            state1->key[idx1] ^= (state2->key[idx2] << 1) ^ 0x80000000U;
        }
    }
}
