#include <stdio.h>
#include <inttypes.h>

typedef int I32;

I32 items;
I32 len;
int aint;
char *aptr;
char *str;

static char input_str[131072];
static char output_buf[65536];

void init_vars() {
    aint = 65536;
    
    for (int i = 0; i < aint; i++) {
        input_str[i] = 'A' + (i % 26);
    }
    input_str[aint] = '\0';
    
    str = input_str;
    aptr = output_buf;
    items = 0;
    len = 0;
}