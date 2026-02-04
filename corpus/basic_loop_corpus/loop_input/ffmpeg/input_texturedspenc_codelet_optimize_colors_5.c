#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int iter_power;
float covf[6];
float vfr;
float vfg;
float vfb;
int iter;

void init_vars() {
    iter_power = 20000000;  

    covf[0] = 1.1f;
    covf[1] = 0.3f;
    covf[2] = 0.2f;
    covf[3] = 1.2f;
    covf[4] = 0.4f;
    covf[5] = 0.9f;

    vfr = 0.5f;
    vfg = 0.6f;
    vfb = 0.7f;

    iter = 0;
}