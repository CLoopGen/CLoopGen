#include <stdint.h>

uint64_t a = 0x1234567890ABCDEF;
uint64_t b = 0x1000000000000000;
uint64_t r = 0xCAFEBABEDEADBEEF;
int i;

void init_vars() {
    // No additional initialization needed beyond static initializers
    // The loop uses scalar variables with no array or pointer dereferencing
    // Values are initialized to ensure defined behavior in shifts and division
}