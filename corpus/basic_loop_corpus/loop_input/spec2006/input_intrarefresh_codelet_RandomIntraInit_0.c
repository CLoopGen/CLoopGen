#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *RefreshPattern;
int NumberOfMBs;
int i;

void init_vars() {
    NumberOfMBs = 64 * 1024 * 1024 / sizeof(int); // ~256 MB of data to ensure ~0.01 sec runtime
    RefreshPattern = (int*)calloc(NumberOfMBs, sizeof(int));
    if (!RefreshPattern) {
        exit(1);
    }
    i = 0;
}