#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double y;
double alpha[16];
double gamma_var;
double pixels[16];
ssize_t i;
ssize_t y_offset;

void init_vars() {
    y = 1.0;
    y_offset = 0;
    for (int j = 0; j < 16; j++) {
        alpha[j] = (double)(j + 1);
        pixels[j] = (double)(2 * j);
    }
    gamma_var = 0.0;
    i = 0;
}

// Alias the external symbol to avoid conflict with math.h gamma
double * const gamma = &gamma_var;