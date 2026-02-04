#include <inttypes.h>

int max_points = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

int* codes;

int num_threats;

void init_vars() {
    codes = (int*)__builtin_malloc(max_points * sizeof(int));
    for (int i = 0; i < max_points; i++) {
        codes[i] = (i == max_points - 1) ? 0 : 1;
    }
}