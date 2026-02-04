#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
size_t N;
size_t i;
size_t j;

void loop();

void init_vars() {
    M = 16384;
    N = 16384;
}

void initialize() {
    init_vars();
}