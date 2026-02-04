#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *min;
unsigned char *max;
int length;
int j;

void init_vars() {
    length = 524288; // 512 KB arrays to target ~0.01 sec runtime

    min = (unsigned char *)malloc(length * sizeof(unsigned char));
    max = (unsigned char *)malloc(length * sizeof(unsigned char));

    if (!min || !max) {
        exit(1);
    }

    memset(min, 0, length * sizeof(unsigned char));
    memset(max, 255, length * sizeof(unsigned char));
}