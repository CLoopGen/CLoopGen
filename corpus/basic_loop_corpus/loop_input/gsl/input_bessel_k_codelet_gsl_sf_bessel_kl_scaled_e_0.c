#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int l;
double x;
double bkp;
double bk;
double bkm;
int j;

void init_vars() {
    x = 2.0;
    bk = 1.0;
    bkm = 0.5;
    l = 20000000; 
}