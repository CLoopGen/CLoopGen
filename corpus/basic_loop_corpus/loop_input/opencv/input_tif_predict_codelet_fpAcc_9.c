#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t count;

void init_vars() {
    count = 8000000; // Ensures loop runs approximately 1e6 iterations (count decremented by 8 each time)
}