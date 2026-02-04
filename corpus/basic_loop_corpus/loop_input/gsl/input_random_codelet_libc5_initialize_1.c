#include <stdlib.h>
#include <stdint.h>

long *x;
int n = 1048576; // 1MB of data: 1048576 elements * 8 bytes per long
int i;

void init_vars() {
    x = (long *)aligned_alloc(64, n * sizeof(long));
    if (!x) exit(1);
    for (int j = 0; j < n; j++) {
        x[j] = 0;
    }
    x[0] = 123456789; // seed value to start the recurrence
}