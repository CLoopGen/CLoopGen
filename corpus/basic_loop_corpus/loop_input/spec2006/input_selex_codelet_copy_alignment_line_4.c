#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int lcol;
char *s2;
int i;

static char s2_buffer[131072]; // 128KB buffer to ensure ~0.01 sec runtime

void init_vars() {
    lcol = 100000; // Adjusted for approximately 0.01 seconds of execution
    memset(s2_buffer, 1, sizeof(s2_buffer));
    s2_buffer[sizeof(s2_buffer) - 1] = 0; // Ensure null terminator at end
    s2 = s2_buffer;
    i = 0;
}