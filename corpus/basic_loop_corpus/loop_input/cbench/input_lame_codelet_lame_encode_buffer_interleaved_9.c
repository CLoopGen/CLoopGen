#include <stdint.h>

short mfbuf[2][3056];
int mf_size;
short *buffer;
int i;
int n_out;

void init_vars() {
    n_out = 1024;
    mf_size = 3056 - n_out;
    if (mf_size < 0) {
        mf_size = 0;
        n_out = 3056;
    }
    buffer = (short*)__builtin_malloc(2 * n_out * sizeof(short));
    for (int idx = 0; idx < 2 * n_out; ++idx) {
        buffer[idx] = (short)(idx & 0xFFFF);
    }
}