#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    length = 256 * 1024 * 1024; // 256 MB to ensure loop runs ~0.01s
    extent = 256;
}

void loop(); // forward declaration

// Ensure the loop can be called from elsewhere
__attribute__((constructor))
static void auto_init() {
    init_vars();
}