#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct s_mt19937_state {
    uint32_t key[624];
    int pos;
} mt19937_state;

extern mt19937_state *target_state;
extern mt19937_state *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 624; i++) {
        uint32_t temp = state->key[i];
        temp ^= (temp >> 11);
        temp ^= (temp << 7) & 0x9D2C5680U;
        temp ^= (temp << 15) & 0xEFC60000U;
        temp ^= (temp >> 18);
        target_state->key[i] = temp;
    }
}
