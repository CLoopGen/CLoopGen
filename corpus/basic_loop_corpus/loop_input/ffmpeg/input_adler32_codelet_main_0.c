#include <stdint.h>

int i;
uint8_t data[7001];

void init_vars() {
    // No additional initialization required beyond zero-initialization
    // Array size is fixed at 7001 as per the loop bounds
    // The loop uses i from 0 to 7000, which is within bounds
}