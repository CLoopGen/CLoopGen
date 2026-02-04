#include <stdio.h>
#include <inttypes.h>

typedef int I32;

const char *PL_hexdigit = "0123456789abcdef";
char *s;
I32 len;
I32 bits;
char *str;
int aint;

char s_buffer[131072];
char str_buffer[262144];

void init_vars() {
    aint = 131072;
    bits = 0;
    len = 0;
    
    s = s_buffer;
    str = str_buffer;
    
    for (int i = 0; i < aint; i++) {
        s_buffer[i] = (char)(0x5a + (i & 0x0f));
    }
}