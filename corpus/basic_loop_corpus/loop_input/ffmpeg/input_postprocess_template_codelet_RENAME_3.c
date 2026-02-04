#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int y;
uint8_t *p;
int s[10];
int QP2;

static uint8_t p_buffer[262144]; // 256KB buffer to ensure ~0.01s runtime

void init_vars() {
    y = 0;
    QP2 = 5;
    for (int i = 0; i < 10; i++) {
        s[i] = (i * 789) & 0xFF;
    }
    s[0] = 0;
    for (int i = 1; i < 9; i++) {
        s[i] |= (1 << i);
    }

    memset(p_buffer, 128, sizeof(p_buffer));
    p = p_buffer;
}