#include <inttypes.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 a;
OPJ_INT32 l;

void init_vars() {
    a = 1 << 24;  // Large enough to make loop run for ~24 iterations, taking noticeable time when repeated if needed
    l = 0;
}