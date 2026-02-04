#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int channels = 32;
int ch;

double tabf1[32];
double tabf2[32];
double taba[32];
unsigned int rnd = 123456789;

void init_vars() {
    // No additional initialization needed beyond static definitions
    // All variables are already initialized at file scope
}