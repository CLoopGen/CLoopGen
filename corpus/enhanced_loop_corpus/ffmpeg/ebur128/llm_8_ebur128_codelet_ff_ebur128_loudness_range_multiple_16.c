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
    for (j = index; j < 1000; j += 2) {
        stl_size += hist[j];
        if (j + 1 < 1000) {
            stl_size += hist[j + 1];
        }
    }
}
