#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int len;
unsigned char *data;
int i;
unsigned char *k;

void init_vars() {
    len = 512 * 1024; // 512 KB data size for ~0.01 sec on modern CPU

    data = (unsigned char *)malloc(len);
    k = (unsigned char *)malloc(len);

    if (!data || !k) {
        exit(1);
    }

    for (i = 0; i < len; i++) {
        data[i] = (unsigned char)(i & 0xFF);
    }

    for (i = 0; i < len; i++) {
        k[i] = 0;
    }
}