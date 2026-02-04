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
    for (i = 0; i < (624 - pt1) * 2; i += 2) {
        int idx1 = i + pt1;
        int idx2 = i + pt2;
        if (idx1 < 624) state1->key[idx1] ^= state2->key[idx2];
        if (idx1 + 1 < 624 && idx2 + 1 < 624) {
            state1->key[idx1 + 1] ^= state2->key[idx2 + 1];
        }
    }
}
