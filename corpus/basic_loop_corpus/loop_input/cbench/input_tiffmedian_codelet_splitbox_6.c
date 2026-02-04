#include <stdio.h>
#include <inttypes.h>

int first;
int *histp;
int i;
int j;
int sum1;

static int *histp_storage;
static int array_size;

void init_vars() {
    array_size = 64 * 1024 * 1024 / sizeof(int);  // ~256MB of data
    histp_storage = (int*)__builtin_malloc(array_size * sizeof(int));
    
    for (int idx = 0; idx < array_size; idx++) {
        histp_storage[idx] = idx % 256;
    }

    first = 0;
    i = array_size;
    histp = histp_storage;
    sum1 = 0;
    j = 0;
}