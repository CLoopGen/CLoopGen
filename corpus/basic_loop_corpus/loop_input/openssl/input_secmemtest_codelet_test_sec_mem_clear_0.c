#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int size;
unsigned char *p;
int i;

void init_vars() {
    size = 512 * 1024; // 512 KB data size for ~0.01 sec runtime on modern CPU
    p = (unsigned char *)malloc(size);
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}