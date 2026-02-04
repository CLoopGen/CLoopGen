#include <stdint.h>

uint32_t test_random_state[31];
int i;
int32_t s;
unsigned int mod;

void init_vars() {
    mod = 2147483647U; // 2^31 - 1
    test_random_state[0] = 1234567; // Initial seed
    for (int j = 1; j < 31; j++) {
        test_random_state[j] = 0;
    }
    i = 0;
    s = 0;
}