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
    for (; i < 624; i += step) {
        if (i + (pt1 - 624) >= 0 && i + (pt2 - 624) >= 0) {
            state1->key[i + (pt1 - 624)] ^= state2->key[i + (pt2 - 624)];
            // Add extra arithmetic to increase computational intensity
            state1->key[i + (pt1 - 624)] += (state1->key[i + (pt1 - 624)] << 1) ^ 0xdeadbeef;
        }
    }
}
