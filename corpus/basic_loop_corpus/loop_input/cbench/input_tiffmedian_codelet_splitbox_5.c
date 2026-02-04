#include <stdint.h>
#include <stdlib.h>

int first;
int last;
int *histp;
int i;
int sum;
int sum2;

static int *hist_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data for ~0.01 sec runtime
    hist_buffer = (int*)calloc(data_size, sizeof(int));
    if (!hist_buffer) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        hist_buffer[idx] = rand() % 100 + 1;
    }

    first = 0;
    last = data_size - 1;
    histp = hist_buffer;
    i = 0;
    sum = 0;
    sum2 = (data_size / 2) * 50; // Approximate midpoint to ensure loop terminates within bounds
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    free(hist_buffer);
}