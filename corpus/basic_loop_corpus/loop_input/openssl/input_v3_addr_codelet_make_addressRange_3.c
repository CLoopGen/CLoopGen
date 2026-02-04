#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (512 * 1024)  // 512 KB of data for ~0.01 sec runtime

unsigned char *min;
int length = DATA_SIZE;
int i;

unsigned char data[DATA_SIZE];

void init_vars() {
    min = data;
    length = DATA_SIZE;
    i = length;

    memset(data, 0, DATA_SIZE);
    data[DATA_SIZE - 1] = 1;  // Ensure loop stops at last non-zero element
}