#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *dig;
int length;
int j;
int bdig[6];

void init_vars() {
    length = 6;
    dig = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        dig[i] = i + 1;
    }
    j = 0;
    memset(bdig, 0, sizeof(bdig));
}