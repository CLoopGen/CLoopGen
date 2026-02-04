#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int seq_no;
char marker_present[256];

void init_vars() {
    seq_no = 0;
    for (int i = 0; i < 256; i++) {
        marker_present[i] = 0;
    }
}