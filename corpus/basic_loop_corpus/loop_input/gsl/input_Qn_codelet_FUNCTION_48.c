#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *right;
int h;
int i;

void init_vars() {
    ni = 65536; 
    h = ni / 2;
    left = (int*)calloc(ni, sizeof(int));
    right = (int*)calloc(ni, sizeof(int));
    if (!left || !right) {
        exit(1);
    }
}