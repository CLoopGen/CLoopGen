#include <stdio.h>
#include <inttypes.h>

typedef unsigned char uchar;

unsigned char lowervec[256];
int patlen;
int skip[256];
uchar *pat;
int i;
int j;

void init_vars() {
    // Initialize lowervec: map each character to its lowercase form
    for (int idx = 0; idx < 256; ++idx) {
        if (idx >= 'A' && idx <= 'Z')
            lowervec[idx] = idx + ('a' - 'A');
        else
            lowervec[idx] = idx;
    }

    // Set pattern length and allocate pattern buffer
    patlen = 16;
    static unsigned char pattern_storage[16] = "hello world test";
    pat = pattern_storage;

    // Initialize skip array to safe default
    for (int idx = 0; idx < 256; ++idx) {
        skip[idx] = patlen;
    }

    // Initialize loop indices
    i = 0;
    j = 0;
}