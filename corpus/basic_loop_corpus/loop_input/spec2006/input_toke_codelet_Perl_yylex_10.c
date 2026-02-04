#include <stdio.h>
#include <inttypes.h>

char PL_tokenbuf[262144]; // 256KB buffer to ensure ~0.01s runtime
char *d;

void init_vars() {
    // Initialize PL_tokenbuf with lowercase letters for maximum loop traversal
    for (int i = 0; i < sizeof(PL_tokenbuf) - 1; i++) {
        PL_tokenbuf[i] = 'a' + (i % 26);
    }
    // Null-terminate at the end to ensure loop stops there
    PL_tokenbuf[sizeof(PL_tokenbuf) - 1] = '\0';

    // Initialize pointer to start of buffer
    d = PL_tokenbuf;
}