#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int I32;

I32 anum;
long *tmpl;

static long *tmpl_storage;
static I32 array_size;

void init_vars() {
    const size_t target_time_ns = 10000000; // 0.01 seconds in nanoseconds
    const long cycles_per_iter = 5; 
    const long cpu_freq_mhz = 2500;
    const long approx_iters = target_time_ns / (cycles_per_iter * 1000 / cpu_freq_mhz);

    array_size = (approx_iters + 1) * sizeof(long);
    tmpl_storage = aligned_alloc(sizeof(long), array_size);
    if (!tmpl_storage) {
        array_size = 1024 * 1024;
        tmpl_storage = aligned_alloc(sizeof(long), array_size);
    }

    memset(tmpl_storage, 0, array_size);

    anum = array_size;
    tmpl = tmpl_storage;
}

__attribute__((destructor))
static void cleanup() {
    free(tmpl_storage);
}