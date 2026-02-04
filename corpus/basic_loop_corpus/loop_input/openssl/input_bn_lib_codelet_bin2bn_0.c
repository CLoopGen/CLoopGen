#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int len;
unsigned char *s2;
int inc2;
int xor;

static unsigned char s2_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    len = sizeof(s2_buffer);
    s2 = s2_buffer;
    inc2 = 1;
    xor = 0xFF; // Set XOR value to match all bytes

    // Initialize all but the last byte to xor value
    memset(s2_buffer, xor, len - 1);
    // Set last byte to a different value to break the loop condition
    s2_buffer[len - 1] = xor ^ 0x01;

    // Ensure that the loop will run through nearly all elements
    // and terminate safely without out-of-bounds access
}