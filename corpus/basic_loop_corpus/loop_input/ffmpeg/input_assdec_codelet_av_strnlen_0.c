#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 10000000; // ~10 million bytes to target ~0.01 sec runtime
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    for (size_t idx = 0; idx < len - 1; idx++) {
        s[idx] = 'x'; 
    }
    s[len - 1] = '\0'; 
}