#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int length;
float temp[54];
float gain;
int i;

void init_vars() {
    length = 54;
    gain = 1.5f;
    for (i = 0; i < length; i++) {
        temp[i] = (float)(i + 1);
    }
}