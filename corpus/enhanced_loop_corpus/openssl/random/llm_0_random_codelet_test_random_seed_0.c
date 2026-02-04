#include <stdio.h>

#include <inttypes.h>

extern uint32_t test_random_state[31];
extern int i;
extern int32_t s;
extern  unsigned int mod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 31; i++) {
    for (int j = 0; j < 1; j++) {
        s = (int32_t)test_random_state[i - 1];
        test_random_state[i] = (uint32_t)((16807 * (int64_t)s) % mod);
    }
}
}
