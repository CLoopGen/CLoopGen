#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int length;
int i;

void init_vars() {
    // Set length such that the loop runs approximately 0.01 seconds
    // Assume modern CPU can do ~1e9 iterations per second, so 1e7 iterations ~ 0.01 sec
    // We set length / 2 - 1 - 2 ≈ 1e7 => length ≈ 2 * (1e7 + 3) ≈ 20000006
    length = 20000006;
}