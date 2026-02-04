#include <inttypes.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 a;
OPJ_INT32 l;

void init_vars() {
    a = 0x40000000;  // Initialize 'a' to a large power of two to ensure the loop runs many times
    l = 0;           // Initialize 'l' to 0; it will be incremented in the loop
}