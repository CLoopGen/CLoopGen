#include <stdio.h>
#include <inttypes.h>

typedef int I32;

I32 i;
short *tbl;

void init_vars() {
    static short internal_tbl[256];
    tbl = internal_tbl;
}

void loop();