#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using a single loop with stride over the combined index space
    MPA_INT *win = window;
    int idx;
    for (idx = 0; idx < 128; idx++) {
        int i_local = idx >> 4;          // i = idx / 16
        int j_local = idx & 0xF;         // j = idx % 16
        win[512 + (idx << 4) + j_local] = win[64 * i_local + 32 - j_local];
    }
}
