#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) exit(1);

    size_t mid = len / 2;
    for (size_t idx = 0; idx < mid; ++idx) {
        s[idx] = 'x';
    }
    s[mid] = '\0'; 
    for (size_t idx = mid + 1; idx < len; ++idx) {
        s[idx] = 'y';
    }
}