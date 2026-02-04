#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int buffer[2][65536];
int x;
int y;

void init_vars() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 65536; j++) {
            buffer[i][j] = 0;
        }
    }
    x = 0;
    y = 0;
}