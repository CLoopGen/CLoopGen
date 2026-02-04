#include <stdio.h>
#include <inttypes.h>

#define NK_DEFAULT 1024
#define NJ_DEFAULT 1024

int nj = NJ_DEFAULT;
int nk = NK_DEFAULT;
double B[1100][900];
int i;
int j;

void init_vars() {
    nj = NJ_DEFAULT < 900 ? NJ_DEFAULT : 900;
    nk = NK_DEFAULT < 1100 ? NK_DEFAULT : 1100;
}