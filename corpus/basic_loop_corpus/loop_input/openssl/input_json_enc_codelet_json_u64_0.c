#include <inttypes.h>

uint64_t v;
char *p;
static char buffer[1024];

void init_vars() {
    v = 123456789012345ULL;
    p = buffer + sizeof(buffer) - 1;
    *p = '\x00';
}