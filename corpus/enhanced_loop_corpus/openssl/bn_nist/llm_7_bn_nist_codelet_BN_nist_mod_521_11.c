#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_cache[8];
    for (int j = 0; j < 8; j++)
        local_cache[j] = 0;

    int idx = 0;
    for (; ii < (521 + (8 * 8) - 1) / (8 * 8); ii++) {
        t_d[ii] = local_cache[idx];
        local_cache[idx] = t_d[ii] + 1;
        idx = (idx + 1) % 8;
    }
}
