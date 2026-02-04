#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *s1;
char c;
int pos;
char oldc;
char *s;

#define DATA_SIZE (128 << 20)  // 128 MB

static char data[DATA_SIZE];

void init_vars() {
    s1 = data;
    pos = 0;
    c = 'X';  // Non-zero to ensure loop runs
    oldc = 0;
    s = NULL;

    // Initialize the data buffer with printable characters
    memset(data, 'A', DATA_SIZE);
    // Ensure null byte is present at end to terminate loop eventually
    data[DATA_SIZE - 1] = '\0';
}