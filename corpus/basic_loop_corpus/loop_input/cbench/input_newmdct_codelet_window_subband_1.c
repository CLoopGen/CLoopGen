#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 d[32];
FLOAT8 in_data[1024 * 1024 / sizeof(FLOAT8)]; // 1MB of data
FLOAT8 workspace[1024 * 256 / sizeof(FLOAT8)]; // 256KB workspace

FLOAT8 *in = in_data;
int i;
FLOAT8 s = 1.0;
FLOAT8 t = 2.0;
FLOAT8 *wp = workspace;

void init_vars() {
    for (int idx = 0; idx < 1024 * 1024 / sizeof(FLOAT8); ++idx) {
        in_data[idx] = (FLOAT8)(idx % 100) / 100.0;
    }
    for (int idx = 0; idx < 1024 * 256 / sizeof(FLOAT8); ++idx) {
        workspace[idx] = (FLOAT8)((idx * 7) % 150) / 100.0;
    }
    for (int idx = 0; idx < 32; ++idx) {
        d[idx] = 0.0;
    }
    i = 0;
}