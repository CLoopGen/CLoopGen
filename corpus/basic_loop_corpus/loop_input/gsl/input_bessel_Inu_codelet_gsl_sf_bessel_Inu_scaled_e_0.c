#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x;
int N;
double mu;
double K_nu;
double K_nup1;
double K_num1;
int n;

void init_vars() {
    x = 1.5;
    N = 10000000;  
    mu = 0.5;
    K_nu = 1.0;
    K_nup1 = 2.0;
    K_num1 = 0.5;
    n = 0;
}