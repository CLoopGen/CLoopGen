#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    maxcnt = -1;
    for (i = 0; i < algs_len; i += step) {
        if (maxcnt < doit[i])
            maxcnt = doit[i];
        if (i + 1 < algs_len && maxcnt < doit[i + 1])
            maxcnt = doit[i + 1];
    }
    // Handle odd-length arrays by checking the last element if missed
    if (algs_len > 0 && algs_len % 2 == 1 && maxcnt < doit[algs_len - 1])
        maxcnt = doit[algs_len - 1];
}
