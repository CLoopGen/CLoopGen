#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int n = 0;
int sixel_palet[1024];

void init_vars() {
    // Initialize variables if needed; all are globals with implicit zero-initialization
    // Ensure n is within bounds for the loop: loop runs 24 times, writing to sixel_palet[n++] => max index is n + 23
    // We require: n + 23 < 1024 -> n <= 999. Current n = 0 is safe.
}