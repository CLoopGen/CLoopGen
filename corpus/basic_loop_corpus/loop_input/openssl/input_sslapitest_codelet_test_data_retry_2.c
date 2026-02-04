#include <stddef.h>
#include <stdint.h>

unsigned char inbuf[131072];
size_t i;

void init_vars() {
    // No additional initialization needed beyond defining inbuf with sufficient size
    // The loop function will initialize inbuf contents
    // i is initialized within the loop itself
}