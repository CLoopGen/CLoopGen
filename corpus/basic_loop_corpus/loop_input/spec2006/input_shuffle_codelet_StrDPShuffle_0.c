#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int x;
int *iE;

void init_vars() {
    iE = (int*)calloc(26, sizeof(int));
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}