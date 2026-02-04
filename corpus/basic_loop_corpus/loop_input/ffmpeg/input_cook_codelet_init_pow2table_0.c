#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float pow2tab[127];
float rootpow2tab[127];
int i;
float exp2_tab[2] = {1.0f, 2.0f};
float exp2_val;
float root_val;

void init_vars() {
    exp2_val = 1.0f;
    root_val = 0.5f;
}