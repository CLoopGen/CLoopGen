#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char primitive[4096];
char *p;

void init_vars() {
    // Initialize the primitive array with spaces and tabs
    size_t i;
    for (i = 0; i < sizeof(primitive) - 1; i++) {
        primitive[i] = (i % 2 == 0) ? ' ' : '\t';
    }
    // Null-terminate to ensure safety, though not used in loop condition directly
    primitive[sizeof(primitive) - 1] = '\0';

    // Initialize p to point to the start of primitive
    p = primitive;

    // Ensure the loop will eventually terminate by setting a non-space character at the end
    // But note: the loop condition checks (*p == ' ') || (*p == '\t'), so we place a non-whitespace
    // at the last position to prevent reading beyond array
    primitive[sizeof(primitive) - 1] = 'A';
}