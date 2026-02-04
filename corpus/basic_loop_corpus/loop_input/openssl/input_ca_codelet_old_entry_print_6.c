#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

char *pbuf;
int j;

char buffer[1024 * 512]; // 512 KB buffer to ensure loop runtime ~0.01 seconds

void init_vars() {
    pbuf = buffer;
    j = 22; // Ensures that "22 - j" becomes 0, so loop condition fails initially
}