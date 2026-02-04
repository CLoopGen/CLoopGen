#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int count[27];
int i;

void init_vars() {
    for (int j = 0; j < 27; j++) {
        count[j] = 0;
    }
    i = 0;
}