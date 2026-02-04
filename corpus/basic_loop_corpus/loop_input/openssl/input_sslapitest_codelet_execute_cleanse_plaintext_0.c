#include <inttypes.h>
#include <string.h>

size_t i;
unsigned char cbuf[131072]; // 128KB to ensure ~0.01s runtime

void init_vars() {
    // No additional initialization needed beyond zeroing globals
}