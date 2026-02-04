#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;

I32 items;
I32 len;
int aint;
char *aptr;
char *str;

static char *str_buffer;
static char *aptr_buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 64 << 20; // 64 MB to target ~0.01 sec runtime
    str_buffer = (char *)calloc(buffer_size, sizeof(char));
    aptr_buffer = (char *)calloc(buffer_size, sizeof(char));
    
    if (!str_buffer || !aptr_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        str_buffer[i] = (char)(i & 0xFF);
    }

    aint = (I32)(buffer_size * 0.9); // ensure loop stays within bounds
    items = 0x55AA;
    len = 0;
    str = str_buffer;
    aptr = aptr_buffer;
}