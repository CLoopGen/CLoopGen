#include <stdio.h>
#include <inttypes.h>

typedef int I32;

I32 items;
I32 len;
int aint;
char *aptr;
char *str;

static char str_buffer[1 << 24]; // 16MB input data
static char aptr_buffer[1 << 20]; // 1MB output buffer

void init_vars() {
    aint = sizeof(str_buffer);
    
    str = str_buffer;
    aptr = aptr_buffer;
    items = 0;
    len = 0;
    
    // Initialize input data to prevent undefined behavior
    for (int i = 0; i < sizeof(str_buffer); i++) {
        str_buffer[i] = (char)(i & 0xFF);
    }
}