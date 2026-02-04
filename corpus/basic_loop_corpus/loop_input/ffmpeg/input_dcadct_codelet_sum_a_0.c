#include <stdlib.h>
#include <stdint.h>

int *input;
int *output;
int len;
int i;

void init_vars() {
    len = 64 * 1024 * 1024; // 64M elements to ensure ~0.01s runtime on modern CPU
    input = (int*)aligned_alloc(32, sizeof(int) * (2 * len));
    output = (int*)aligned_alloc(32, sizeof(int) * len);

    for (int j = 0; j < 2 * len; j++) {
        input[j] = rand() % 1000;
    }
    for (int j = 0; j < len; j++) {
        output[j] = 0;
    }
    i = 0;
}