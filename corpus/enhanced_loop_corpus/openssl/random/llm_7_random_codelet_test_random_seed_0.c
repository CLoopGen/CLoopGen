#include <stdio.h>

#include <inttypes.h>

extern uint32_t test_random_state[31];
extern int i;
extern int32_t s;
extern  unsigned int mod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 31; i += 2) {
        s = (int32_t)test_random_state[i - 1];
        test_random_state[i] = (uint32_t)((16807 * (int64_t)s) % mod);
        if (i + 1 < 31) {
            int32_t s_next = (int32_t)test_random_state[i];
            test_random_state[i + 1] = (uint32_t)((16807 * (int64_t)s_next) % mod);
        }
    }
}
