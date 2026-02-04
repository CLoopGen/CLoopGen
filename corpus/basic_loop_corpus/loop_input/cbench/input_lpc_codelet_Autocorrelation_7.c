#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef long longword;

longword *L_ACF;
int k;

#define DATA_SIZE (1 << 20)  // 1MB of data: 2^20 bytes

static longword acf_buffer[DATA_SIZE / sizeof(longword)];

void init_vars() {
    L_ACF = acf_buffer;
    k = DATA_SIZE / sizeof(longword);
    
    for (int i = 0; i < k; ++i) {
        L_ACF[i] = (longword)(i * 31 + 7);
    }
}