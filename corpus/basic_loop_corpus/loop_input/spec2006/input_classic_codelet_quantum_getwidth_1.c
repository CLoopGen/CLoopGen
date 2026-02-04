#include <inttypes.h>

int n;
int i;

void init_vars() {
    n = 1 << 25;  // Approximately 33 million iterations: 2^25
    i = 0;
}