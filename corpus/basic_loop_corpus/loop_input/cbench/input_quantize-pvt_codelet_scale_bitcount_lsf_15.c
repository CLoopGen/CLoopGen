#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

III_scalefac_t *scalefac;
int partition;
int nr_sfb;
int window;
int i;
int sfb;
int max_sfac[4];
unsigned int *partition_table;

void init_vars() {
    scalefac = (III_scalefac_t*)calloc(1, sizeof(III_scalefac_t));
    partition_table = (unsigned int*)calloc(4, sizeof(unsigned int));
    
    partition_table[0] = 39; 
    partition_table[1] = 78; 
    partition_table[2] = 117; 
    partition_table[3] = 156; 
    
    for (int p = 0; p < 4; p++) {
        max_sfac[p] = 0;
    }
    
    for (int s = 0; s < 13; s++) {
        for (int w = 0; w < 3; w++) {
            scalefac->s[s][w] = rand() % 100;
        }
    }
    
    partition = 0;
    nr_sfb = 0;
    window = 0;
    i = 0;
    sfb = 0;
}