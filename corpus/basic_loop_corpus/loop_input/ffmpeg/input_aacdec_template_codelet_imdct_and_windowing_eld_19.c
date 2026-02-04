#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int n4;

void init_vars() {
    n4 = 10000000; // Adjusted for ~0.01 sec runtime on modern CPU
}