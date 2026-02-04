#include <stdint.h>
#include <stdlib.h>

uint8_t ungroup_3_in_7_bits_tab[128][3];
int i;

void init_vars() {
    // No additional initialization needed beyond zeroing or default static init
    // The loop() function will populate ungroup_3_in_7_bits_tab
    // Variables are already at file scope and will be zero-initialized if needed
}