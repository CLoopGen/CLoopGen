#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *sched;
int which_pe;
int npes;
int pe;
int n;
int s;
int i;

void init_vars() {
    n = 10000;
    npes = 8;
    which_pe = 4;
    s = 0;
    pe = 0;
    i = 0;

    sched = (int*)calloc(n * 2, sizeof(int));
}