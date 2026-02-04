#include <stdlib.h>
#include <stdint.h>

int *input;
int *output;
int len;
int i;

void init_vars() {
    len = 64 * 1024 * 1024; // 64M elements to target ~0.01 sec on modern CPU

    input = (int*)aligned_alloc(32, (2 * len + 2) * sizeof(int));
    output = (int*)aligned_alloc(32, len * sizeof(int));

    for (int j = 0; j < 2 * len + 2; j++) {
        input[j] = rand() % 1000;
    }
    for (int j = 0; j < len; j++) {
        output[j] = 0;
    }

    i = 0;
}