#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *hist;
int i;

void init_vars() {
    const size_t data_size = 1024 * 1024 * 64; // 64 MB of data
    static int internal_hist[3 * 256];
    
    hist = internal_hist;
    
    for (i = 0; i < (3 * 256); i++) {
        hist[i] = i + 1;
    }
}