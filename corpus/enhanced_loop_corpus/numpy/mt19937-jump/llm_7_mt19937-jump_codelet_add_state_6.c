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
    for (; i < 623; i++) {
        state1->key[i + (pt1 - 624)] ^= state2->key[i + 1 + (pt2 - 624)];
        state1->key[i + 1 + (pt1 - 624)] ^= state2->key[i + (pt2 - 624)];
    }
    if (i == 623) {
        state1->key[623 + (pt1 - 624)] ^= state2->key[623 + (pt2 - 624)];
    }
}
