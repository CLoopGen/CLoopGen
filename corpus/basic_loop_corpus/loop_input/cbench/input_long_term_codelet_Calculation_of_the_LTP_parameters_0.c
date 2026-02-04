#include <inttypes.h>

typedef short word;

word d_buffer[262144]; // 512KB buffer to ensure ~0.01s runtime
word *d = d_buffer;
int k;
word dmax;
word temp;

void init_vars() {
    dmax = 0;
    for (int i = 0; i < 262144; i++) {
        d[i] = (short)(i * 789) % 32768; // deterministic pattern within short range
    }
}