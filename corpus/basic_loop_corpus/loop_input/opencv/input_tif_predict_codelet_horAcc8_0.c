#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t cc;
tmsize_t i;

void init_vars() {
    cc = 10000000; // Ensures loop runs approximately 0.01 seconds
    i = 0;
}