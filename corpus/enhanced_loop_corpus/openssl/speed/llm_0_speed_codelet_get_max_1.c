#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < algs_len; outer++) {
        for (size_t inner = 0; inner <= outer; inner++) {
            if (inner == outer) {
                if (maxcnt < doit[inner])
                    maxcnt = doit[inner];
            }
        }
    }
}
