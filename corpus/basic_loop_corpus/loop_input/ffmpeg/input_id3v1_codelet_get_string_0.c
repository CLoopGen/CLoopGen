#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int i;
int c;
char *q;
char str[512];
char *first_free_space;

static uint8_t internal_buf[262144]; // 256KB buffer

void init_vars() {
    buf_size = sizeof(internal_buf);
    buf = internal_buf;
    
    for (int j = 0; j < buf_size - 1; j++) {
        buf[j] = (rand() % 95) + 32; // printable ASCII
        if (rand() % 200 == 0) {
            buf[j] = ' ';
        }
    }
    buf[buf_size - 1] = '\x00'; // null terminate

    q = str;
    first_free_space = NULL;
}