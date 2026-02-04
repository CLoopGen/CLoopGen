#include <inttypes.h>

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

static UInt32 fmap_buf[65536];
static UInt32 eclass_buf[65536];

void init_vars() {
    fmap = fmap_buf;
    eclass = eclass_buf;
    lo = 0;
    hi = 65535;

    for (Int32 idx = 0; idx <= hi; idx++) {
        fmap[idx] = idx;
        eclass[idx] = idx % 1000;
    }
}