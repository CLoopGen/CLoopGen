#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *data2;
int j;
int data2_num;

void init_vars() {
    data2_num = 262144; // 262144 integers = 1MB of data (assuming 4 bytes per int)
    data2 = (int*)malloc(data2_num * sizeof(int));
    if (!data2) {
        data2_num = 0;
    }
}