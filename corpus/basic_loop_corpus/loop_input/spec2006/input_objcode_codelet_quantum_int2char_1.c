#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int j;
unsigned char *buf;
int i;
int size;

void init_vars() {
    size = 1 << 20; // 1MB data size for approximately 0.01 sec runtime
    buf = (unsigned char*)calloc(size, sizeof(unsigned char));
    j = 0xABCDEF12; // arbitrary non-zero value for meaningful computation
    i = 0;
}