#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha;
int i;

void init_vars() {
    alpha = 1.0000001f; // Initialize to a value close to 1 to avoid overflow during repeated squaring
}