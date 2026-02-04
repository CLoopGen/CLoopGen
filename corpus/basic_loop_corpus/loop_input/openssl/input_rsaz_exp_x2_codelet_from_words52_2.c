#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned long *out;
int i;
int out_len;

void init_vars() {
    out_len = 262144;  // 2^18 entries, resulting in 1MB of data (assuming 4 bytes per unsigned long, though size may vary)
    out = (unsigned long *)calloc(out_len, sizeof(unsigned long));
    if (!out) {
        out_len = 0;
    }
}