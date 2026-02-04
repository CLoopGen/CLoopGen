#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE 1024 * 512  // 512 KB data array

int len;
unsigned char *data;
unsigned int tmp;
int id1;
int id2;
unsigned int *d;
unsigned int i;

void init_vars() {
    len = 256;
    id1 = 0;
    id2 = 0;
    tmp = 0;
    i = 0;

    data = (unsigned char *)malloc(DATA_SIZE);
    if (!data) {
        exit(1);
    }
    memset(data, 0x5A, DATA_SIZE);  // Initialize with non-zero pattern

    d = (unsigned int *)malloc(len * sizeof(unsigned int));
    if (!d) {
        free(data);
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        d[j] = j * 0x0F0F0F0F;
    }
}