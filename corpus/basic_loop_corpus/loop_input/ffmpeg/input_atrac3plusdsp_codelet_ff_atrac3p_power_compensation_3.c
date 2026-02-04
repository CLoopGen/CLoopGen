#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

AtracGainInfo *g1;
int i;
int gcv;

void init_vars() {
    g1 = (AtracGainInfo*)malloc(sizeof(AtracGainInfo));
    if (!g1) exit(1);
    
    g1->num_points = 7;
    for (int j = 0; j < 7; j++) {
        g1->lev_code[j] = rand() % 7;
        g1->loc_code[j] = rand() % 10;
    }
    
    i = 0;
    gcv = 0;
}