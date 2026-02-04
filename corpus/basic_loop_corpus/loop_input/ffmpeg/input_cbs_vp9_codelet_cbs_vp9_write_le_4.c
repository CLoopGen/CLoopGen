#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 256 * 1024 * 1024; // 256MB of data
uint32_t value = 0xDEADBEEF;
int b;
char bits[256 * 1024 * 1024 + 8]; // Ensure array is large enough for max index (width + 7)
int i;

void init_vars() {
    // Initialize variables if needed; all externs are already defined at file scope
    // No additional setup required for basic execution safety
}