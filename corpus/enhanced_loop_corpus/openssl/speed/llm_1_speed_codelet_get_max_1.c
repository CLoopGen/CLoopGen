#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (algs_len > 0) {
        for (i = 0; i < algs_len; i += 2) {
            if (maxcnt < doit[i])
                maxcnt = doit[i];
            if (i + 1 < algs_len && maxcnt < doit[i + 1])
                maxcnt = doit[i + 1];
        }
    }
}
