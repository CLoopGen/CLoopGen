#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int32_t *left_ch;
int32_t *right_ch;
int n;
int i;
int32_t lt;
int32_t rt;
uint64_t sum[4];

void init_vars() {
    n = 65536 * 4;  // Approximately 1MB per array (4 bytes * 65536*4 = ~1MB per channel)
    
    left_ch = (int32_t*)aligned_alloc(32, sizeof(int32_t) * n);
    right_ch = (int32_t*)aligned_alloc(32, sizeof(int32_t) * n);
    
    for (int j = 0; j < n; j++) {
        left_ch[j] = (rand() % 2000) - 1000;
        right_ch[j] = (rand() % 2000) - 1000;
    }
    
    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 0;
    sum[3] = 0;
}