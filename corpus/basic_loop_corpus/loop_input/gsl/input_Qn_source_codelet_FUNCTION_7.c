#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *right;
int i;
int j;

static int left_data[100000];
static int right_data[100000];

void init_vars() {
    ni = 100000;
    
    left = left_data;
    right = right_data;
    
    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = idx * 2;
        right[idx] = idx * 2 + 10;
    }
    
    i = 0;
    j = 0;
}