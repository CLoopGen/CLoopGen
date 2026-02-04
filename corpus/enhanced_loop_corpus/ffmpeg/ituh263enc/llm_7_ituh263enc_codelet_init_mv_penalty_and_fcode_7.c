#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_cache[128];
    int offset, idx;
    for (f_code = 7; f_code > 0; f_code--) {
        offset = 16 << f_code;
        idx = 0;
        for (mv = -offset; mv < offset; mv++) {
            if (idx < 128) {
                local_cache[idx++] = f_code;
            }
            fcode_tab[mv + 4096] = f_code;
        }
        // Introduce loop-carried dependency via cache flush
        for (int i = 0; i < idx && (-offset + i) + 4096 < 8193; i++) {
            fcode_tab[-offset + i + 4096] = local_cache[i];
        }
    }
}
