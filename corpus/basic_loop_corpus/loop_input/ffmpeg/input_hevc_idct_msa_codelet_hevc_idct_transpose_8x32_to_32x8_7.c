#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // as the loop only uses 'i' which is automatically handled in loop scope
    i = 0;
}