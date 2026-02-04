#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t fcode_tab[8193];
int f_code;
int mv;

void init_vars() {
    // Initialize fcode_tab to zero or any safe initial value
    for (int i = 0; i < 8193; i++) {
        fcode_tab[i] = 0;
    }
    // No further initialization needed for f_code and mv as they are loop variables
}