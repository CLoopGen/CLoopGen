#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *kassign;
char *tassign;
int s1;
int s2;

static int *kassign_internal;
static char *tassign_internal;
static const int data_size = 1 << 20; // 1MB of data

void init_vars() {
    kassign_internal = (int *)calloc(data_size, sizeof(int));
    tassign_internal = (char *)calloc(data_size, sizeof(char));
    
    if (!kassign_internal || !tassign_internal) {
        exit(1);
    }

    kassign = kassign_internal;
    tassign = tassign_internal;
    s1 = 0;
    s2 = data_size - 1;
}