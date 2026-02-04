#include <inttypes.h>

unsigned short *s;
int i;

void init_vars() {
    s = (unsigned short*)__builtin_malloc(256 * 1024 * 1024);
}