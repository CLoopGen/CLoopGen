#include <stdint.h>
#include <stdlib.h>

uint8_t ungroup_3_in_7_bits_tab[128][3];
int i;

void init_vars() {
    // No dynamic initialization needed; static storage is zeroed by default
    // The loop function will populate the table correctly for i in [0, 127]
}