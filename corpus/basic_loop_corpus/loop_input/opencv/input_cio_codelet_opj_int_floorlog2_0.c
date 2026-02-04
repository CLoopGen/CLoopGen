#include <inttypes.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 a;
OPJ_INT32 l;

void init_vars() {
    a = 1 << 20;  // Initialize 'a' to a large value so the loop runs many times
    l = 0;
}