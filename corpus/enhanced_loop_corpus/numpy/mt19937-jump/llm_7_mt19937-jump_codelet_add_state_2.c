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
    int j;
    for (j = 0; j < 624 - pt1; j++, i++)
        state1->key[i + pt1] ^= state2->key[j + (pt2 - 624)];
}
