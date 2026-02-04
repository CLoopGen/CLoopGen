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
    int step = 2;
    for (; i < (624 - pt2); i += step) {
        if (i + pt2 < 624) {
            uint32_t temp1 = state1->key[i + (pt1 - 624)];
            uint32_t temp2 = state2->key[i + pt2];
            temp2 ^= temp1;
            temp2 ^= temp1 >> 1;
            temp2 ^= temp1 << 1;
            state1->key[i + (pt1 - 624)] = temp2;
        }
    }
}
