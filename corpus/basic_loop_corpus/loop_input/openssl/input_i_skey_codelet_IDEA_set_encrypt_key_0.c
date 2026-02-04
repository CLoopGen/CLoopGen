#include <stdio.h>
#include <inttypes.h>

typedef unsigned int IDEA_INT;

int i;
IDEA_INT *kt;
IDEA_INT *kf;
IDEA_INT r0;
IDEA_INT r1;
IDEA_INT r2;

static IDEA_INT kf_data[64000];
static IDEA_INT kt_data[128000];

void init_vars() {
    for (int idx = 0; idx < 64000; ++idx) {
        kf_data[idx] = (IDEA_INT)(idx * 17 + 31);
    }
    for (int idx = 0; idx < 128000; ++idx) {
        kt_data[idx] = 0;
    }
    kf = kf_data;
    kt = kt_data;
    r0 = 0;
    r1 = 0;
    r2 = 0;
    i = 0;
}