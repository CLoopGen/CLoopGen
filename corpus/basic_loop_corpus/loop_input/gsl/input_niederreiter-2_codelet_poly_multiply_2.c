#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int pt_degree = 49; 
int pc[51];

void init_vars() {
    for (int i = 0; i < 51; i++) {
        pc[i] = i;
    }
    k = 0;
    pt_degree = 49;
}