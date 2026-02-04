#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_mt19937_state {
    uint32_t key[624];
    int pos;
} mt19937_state;

mt19937_state *state1;
mt19937_state *state2;
int i;
int pt1;
int pt2;

void init_vars() {
    state1 = (mt19937_state*)calloc(1, sizeof(mt19937_state));
    state2 = (mt19937_state*)calloc(1, sizeof(mt19937_state));
    
    pt1 = 624;
    pt2 = 0;
    i = 0;
    
    for (int j = 0; j < 624; j++) {
        state1->key[j] = (uint32_t)(j * 31);
        state2->key[j] = (uint32_t)(j * 17);
    }
}