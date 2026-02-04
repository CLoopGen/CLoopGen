#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t j;
extern size_t stl_size;
extern unsigned long hist[1000];
extern size_t _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    size_t local_hist[1000];
    for (j = 0; j < 1000; ++j) {
        local_hist[j] = hist[j];
    }
    for (j = index; j < 1000; ++j) {
        if (j > 0) {
            stl_size += local_hist[j] + local_hist[j-1];
        } else {
            stl_size += local_hist[j];
        }
    }
}
