#include <stdio.h>
#include <inttypes.h>

typedef int I32;

const char *PL_hexdigit = "0123456789abcdef";
char *s;
I32 len;
I32 bits;
char *str;
int aint;

#define DATA_SIZE (16 << 20)  // 16 MB

static char s_buffer[DATA_SIZE];
static char str_buffer[DATA_SIZE];

void init_vars() {
    // Initialize input data
    for (int i = 0; i < DATA_SIZE; i++) {
        s_buffer[i] = (char)(0xFF & i);
    }
    
    // Initialize hex digit lookup table via PL_hexdigit (already initialized as const)
    // Setup pointers and variables
    s = s_buffer;
    str = str_buffer;
    bits = 0xABCDEF00;
    aint = DATA_SIZE;
}