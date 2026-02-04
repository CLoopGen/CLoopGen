#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_doit[256];
    int temp_max = 0;
    size_t copy_len = algs_len < 256 ? algs_len : 256;
    for (i = 0; i < copy_len; i++) {
        local_doit[i] = doit[i];
    }
    for (i = 0; i < copy_len; i++) {
        if (temp_max < local_doit[i])
            temp_max = local_doit[i];
    }
    maxcnt = temp_max;
}
