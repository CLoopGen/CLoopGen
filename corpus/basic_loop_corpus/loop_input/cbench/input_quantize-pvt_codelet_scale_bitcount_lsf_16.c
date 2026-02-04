#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

III_scalefac_t *scalefac;
int partition;
int nr_sfb;
int i;
int sfb;
int max_sfac[4];
unsigned int *partition_table;

void init_vars() {
    scalefac = (III_scalefac_t*)calloc(1, sizeof(III_scalefac_t));
    partition_table = (unsigned int*)calloc(4, sizeof(unsigned int));
    
    partition_table[0] = 5;
    partition_table[1] = 6;
    partition_table[2] = 5;
    partition_table[3] = 6;
    
    for (int idx = 0; idx < 22; idx++) {
        scalefac->l[idx] = (idx * 17 + 123) % 8192;
    }
    
    for (int p = 0; p < 4; p++) {
        max_sfac[p] = -1;
    }
    
    partition = 0;
    nr_sfb = 0;
    i = 0;
    sfb = 0;
}