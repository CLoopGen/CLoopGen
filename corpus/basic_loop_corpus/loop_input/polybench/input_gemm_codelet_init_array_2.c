#include <stdio.h>
#include <inttypes.h>

#define NK_DEFAULT 1000
#define NJ_DEFAULT 1000

int nj = NJ_DEFAULT;
int nk = NK_DEFAULT;
double B[1200][1100];
int i;
int j;

void init_vars() {
    nj = NJ_DEFAULT;
    nk = NK_DEFAULT;
}