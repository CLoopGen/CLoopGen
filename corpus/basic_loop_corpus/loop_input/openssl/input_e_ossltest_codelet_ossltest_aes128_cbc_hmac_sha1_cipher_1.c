#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *out;
size_t len;
unsigned int l;
size_t plen;

void init_vars() {
    len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime
    plen = len - 16;  // Ensure plen starts close to len but allows loop to run
    out = (unsigned char *)calloc(len, sizeof(unsigned char));
    if (!out) {
        exit(1);
    }
    l = (unsigned int)(len - plen - 1); // Initial value used in loop
}