#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *data1;
int j;
int data1_num;

void init_vars() {
    data1_num = 65536; // Approximately 256KB of data (65536 * 4 bytes per int)
    data1 = (int*)malloc(data1_num * sizeof(int));
    if (!data1) {
        data1_num = 0;
    }
}