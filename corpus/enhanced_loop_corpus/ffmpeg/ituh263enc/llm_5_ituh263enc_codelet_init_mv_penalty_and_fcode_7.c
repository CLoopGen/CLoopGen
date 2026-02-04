#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (f_code = 7; f_code > 0; f_code--) {
        int range = 16 << f_code;
        int base = 4096;
        for (mv = -range; mv < range; mv++) {
            if (mv >= -2048 && mv <= 2048) {
                fcode_tab[mv + base] = f_code;
            } else {
                continue;
            }
        }
    }
}
