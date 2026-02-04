#include <stdint.h>

int last;
int *histp;
int i;
int j;
int sum2;

static int *histp_storage;
static int storage_size = 64 << 20; // 64 MB of data

void init_vars() {
    histp_storage = (int*)__builtin_malloc(storage_size * sizeof(int));
    for (int idx = 0; idx < storage_size; idx++) {
        histp_storage[idx] = 1;
    }
    i = 0;
    last = storage_size - 1;
    histp = histp_storage;
    sum2 = 0;
    j = 0;
}