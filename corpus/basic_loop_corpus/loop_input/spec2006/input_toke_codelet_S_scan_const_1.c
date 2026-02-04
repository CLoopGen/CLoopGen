#include <stdio.h>
#include <inttypes.h>

typedef int I32;

char *d;
I32 i;
I32 min;
I32 max;

static char data_buffer[134217728]; // 128 MB buffer

void init_vars() {
    min = 0;
    max = 134217727; // Ensures exactly 128M iterations
    d = data_buffer;
}