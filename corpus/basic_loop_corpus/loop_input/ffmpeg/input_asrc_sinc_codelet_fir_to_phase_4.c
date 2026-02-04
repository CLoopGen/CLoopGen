#include <stdlib.h>
#include <stdint.h>

float *work;
int i;
int work_len;

void init_vars() {
    work_len = 32 * 1024 * 1024 / sizeof(float); // ~128MB of data to target ~0.01s runtime
    work = (float *)aligned_alloc(32, work_len * sizeof(float));
    for (int j = 0; j < work_len; j++) {
        work[j] = 1.0f;
    }
}