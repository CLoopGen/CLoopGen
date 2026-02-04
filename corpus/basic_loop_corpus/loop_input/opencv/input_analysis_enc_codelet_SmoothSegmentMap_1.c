#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int y;
int w = 1024;
int h = 1024;

void init_vars() {
    // Initialize loop bounds to ensure valid iteration space
    // The loop runs from 1 to w-2 and 1 to h-2, so w and h must be at least 3 to have valid iterations
    // Using 1024x1024 gives sufficient work to run ~0.01 seconds with empty loop overhead
    w = 1024;
    h = 1024;
    x = 0;
    y = 0;
}