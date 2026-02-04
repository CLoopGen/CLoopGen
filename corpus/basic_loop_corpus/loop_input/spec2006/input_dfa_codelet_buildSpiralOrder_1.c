#include <stdio.h>
#include <inttypes.h>

int mark[7056];
int i;
int j;

void init_vars() {
    for (int idx = 0; idx < 7056; idx++) {
        mark[idx] = 1;
    }
    i = 0;
    j = 0;
}