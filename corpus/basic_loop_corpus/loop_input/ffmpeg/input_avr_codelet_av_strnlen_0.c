#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    buffer = (char*)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    // Fill with non-zero bytes so that s[i] eventually hits zero at the end
    memset(buffer, 'x', data_size - 1);
    buffer[data_size - 1] = 0; // null terminate
    
    s = buffer;
    len = data_size;
    i = 0;
}