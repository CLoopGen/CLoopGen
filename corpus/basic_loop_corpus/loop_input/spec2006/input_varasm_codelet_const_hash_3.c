#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *p;
int len;
int hi;
int i;

void init_vars() {
    len = 16777216; // 16MB data size for ~0.01 sec runtime on modern CPU
    p = (char *)malloc(len);
    if (!p) {
        len = 0;
        return;
    }
    memset(p, 0x41, len); // Initialize with 'A'
    hi = 0;
    i = 0;
}