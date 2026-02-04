#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int buffer[2][65536];
short obuffer[65536];
int i;

void init_vars() {
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 65536; k++) {
            buffer[j][k] = rand() % 1000;
        }
    }
    for (int k = 0; k < 65536; k++) {
        obuffer[k] = 0;
    }
    i = 0;
}