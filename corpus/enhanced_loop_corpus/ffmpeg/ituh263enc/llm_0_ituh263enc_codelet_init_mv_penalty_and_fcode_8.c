#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t umv_fcode_tab[8193];
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 2; i++) {
        for (mv = i * 4096; mv < (i + 1) * 4096 + 1; mv++) {
            umv_fcode_tab[mv] = 1;
        }
    }
}
