#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned long LONG;

typedef struct {
    LONG digest[5];
    LONG count_lo;
    LONG count_hi;
    LONG data[16];
} SHA_INFO;

SHA_INFO *sha_info;
int i;
LONG W[80];

void init_vars() {
    sha_info = (SHA_INFO *)calloc(1, sizeof(SHA_INFO));
    if (!sha_info) {
        exit(1);
    }
    for (int j = 0; j < 16; ++j) {
        sha_info->data[j] = (LONG)(j * 2 + 1);
    }
}