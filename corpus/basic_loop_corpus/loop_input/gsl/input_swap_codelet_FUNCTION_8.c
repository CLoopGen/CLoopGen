#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1 = 134217728; // 128MB worth of iterations (assuming ~1 byte per index), tuned for ~0.01s runtime
size_t p;

void init_vars() {
    // No dynamic initialization needed; all variables are file-scope globals with static initialization
}