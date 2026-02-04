#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned char *to;
int num;
int i;

void init_vars() {
    num = 131072; // 128 KB of data to target ~0.01 sec runtime
    to = (unsigned char *)calloc(num, sizeof(unsigned char));
}