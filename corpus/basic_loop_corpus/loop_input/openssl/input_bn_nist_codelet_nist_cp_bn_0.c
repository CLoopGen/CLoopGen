#include <stdint.h>
#include <stdlib.h>

unsigned long *dst;
unsigned long *src;
int top;
int i;

void init_vars() {
    top = 131072 / sizeof(unsigned long);  // ~128KB of data
    src = (unsigned long *)malloc(top * sizeof(unsigned long));
    dst = (unsigned long *)malloc(top * sizeof(unsigned long));

    for (i = 0; i < top; i++) {
        src[i] = (unsigned long)(i * 2);
        dst[i] = 0;
    }
}