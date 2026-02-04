#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t src[1024 * 1024 * 2]; // 2MB of data to ensure ~0.01s runtime
int stride = 1024;
int y;
int avg = 128;
int s[10];

void init_vars() {
    srand(time(NULL));
    for (int i = 0; i < 1024 * 1024 * 2; i++) {
        src[i] = rand() % 256;
    }
    avg = 128;
    y = 0;
    for (int i = 0; i < 10; i++) {
        s[i] = 0;
    }
}