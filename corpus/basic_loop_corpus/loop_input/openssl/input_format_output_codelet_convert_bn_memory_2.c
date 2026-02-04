#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int n;
int i;
char *p;

char data_buffer[1024 * 128]; // 128 KB buffer

void init_vars() {
    n = 1024 * 128; // Set loop count to fill the buffer
    p = data_buffer; // Point p to the beginning of the buffer
}