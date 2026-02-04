#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_max = maxcnt;
    for (i = 0; i < algs_len; i++) {
        if (temp_max < doit[i])
            temp_max = doit[i];
    }
    maxcnt = temp_max;
}
