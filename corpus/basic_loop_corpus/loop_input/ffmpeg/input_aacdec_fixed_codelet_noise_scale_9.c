#include <stdlib.h>
#include <stdio.h>

int *coefs;
int len;
int i;

void init_vars() {
    len = 65536; // Size chosen to make loop take ~0.01 seconds
    coefs = (int *)calloc(len, sizeof(int));
    i = 0;
}