#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *t;

static char data[131072]; // 128KB of input data

void init_vars() {
    size_t len = sizeof(data) - 1;
    memset(data, ' ', len); // Fill with spaces
    data[len] = 'x'; // Sentinel character to break the loop
    s = data;
    t = s; // Will be updated in the loop
}