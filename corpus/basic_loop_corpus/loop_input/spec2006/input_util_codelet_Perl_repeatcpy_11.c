#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;

char *to;
char *from;
I32 len;
I32 todo;

static char *from_buffer;
static char *to_buffer;

void init_vars() {
    len = 64 * 1024 * 1024;  // 64 MB for ~0.01 sec on modern CPU

    from_buffer = (char *)malloc(len);
    to_buffer = (char *)malloc(len);

    if (!from_buffer || !to_buffer) {
        exit(1);
    }

    // Initialize from_buffer with sample data
    for (I32 i = 0; i < len; i++) {
        from_buffer[i] = (char)(i & 0xFF);
    }

    from = from_buffer;
    to = to_buffer;
}