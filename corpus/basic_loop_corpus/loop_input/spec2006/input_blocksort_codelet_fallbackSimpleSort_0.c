#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *fmap;
UInt32 *eclass;
Int32 lo;
Int32 hi;
Int32 i;
Int32 j;
Int32 tmp;
UInt32 ec_tmp;

static UInt32 *fmap_data = NULL;
static UInt32 *eclass_data = NULL;
static size_t data_size = 0;

void init_vars() {
    const size_t target_time_ns = 10000000; // ~10ms in nanoseconds
    const double cycles_per_iter = 100.0;
    const double freq_ghz = 3.0;
    const double ns_per_cycle = 1000.0 / freq_ghz;
    const double avg_inner_loop_factor = 0.5;

    size_t estimated_size = (size_t)(target_time_ns / (cycles_per_iter * ns_per_cycle * avg_inner_loop_factor));
    data_size = (estimated_size < 10000) ? 10000 : (estimated_size > 65536) ? 65536 : estimated_size;

    fmap_data = (UInt32*)calloc(data_size, sizeof(UInt32));
    eclass_data = (UInt32*)calloc(data_size, sizeof(UInt32));

    if (!fmap_data || !eclass_data) {
        free(fmap_data);
        free(eclass_data);
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        fmap_data[idx] = (UInt32)(data_size - idx - 1);
        eclass_data[idx] = (UInt32)(rand() % (data_size / 100 + 1));
    }

    fmap = fmap_data;
    eclass = eclass_data;
    lo = 0;
    hi = (Int32)(data_size - 1);
    i = 0;
    j = 0;
    tmp = 0;
    ec_tmp = 0;
}