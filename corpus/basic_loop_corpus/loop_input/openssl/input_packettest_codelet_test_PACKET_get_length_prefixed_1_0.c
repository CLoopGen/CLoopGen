#include <inttypes.h>

unsigned char buf1[255];
unsigned int i;

void init_vars() {
    // No additional initialization needed beyond zero-initialization
    // Loop bounds (i = 1 to 254) are within buf1[255] range
    // buf1 will be filled by the loop: buf1[i] = (i * 2) & 255
}