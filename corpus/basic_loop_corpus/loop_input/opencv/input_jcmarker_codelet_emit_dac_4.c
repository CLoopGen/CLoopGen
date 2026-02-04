#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char dc_in_use[16] = {0};
char ac_in_use[16] = {0};
int length = 0;
int i = 0;

void init_vars() {
    for (int j = 0; j < 16; j++) {
        dc_in_use[j] = (char)(j % 7);
        ac_in_use[j] = (char)(j % 5);
    }
    length = 0;
    i = 0;
}