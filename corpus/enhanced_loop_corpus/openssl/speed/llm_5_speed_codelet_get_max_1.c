#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    maxcnt = 0;
    for (i = 0; i < algs_len; ++i) {
        uint8_t current = doit[i];
        maxcnt = (current > maxcnt) ? current : maxcnt;
    }
}
