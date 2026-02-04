#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int count;
int i;
int *recstart;
int *reclength;

void init_vars() {
    count = 13421772;  // ~53.7 MB total data (each array is ~53.7 MB, two arrays)
    
    recstart = (int*)calloc(count, sizeof(int));
    if (!recstart) {
        exit(1);
    }
    
    reclength = (int*)calloc(count, sizeof(int));
    if (!reclength) {
        free(recstart);
        exit(1);
    }
}