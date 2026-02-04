#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lut_nmsedec_ref[128];
int lut_nmsedec_ref0[128];
int lut_nmsedec_sig[128];
int lut_nmsedec_sig0[128];
int i;
int a;
int mask;

void init_vars() {
    mask = 0x7FFFFFFF;
}