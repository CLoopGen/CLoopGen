#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_sf_result_struct {
    double val;
    double err;
};

typedef struct gsl_sf_result_struct gsl_sf_result;

int n = 1000;
int k;
double y = 1.5;
double ln_x_2 = 0.693147;
double k_term;
double sum2;
int KMAX = 80000;
gsl_sf_result npk_fact;
double yk;
double k_fact;
double psi_kp1;
double psi_npkp1;

void init_vars() {
    n = 1000;
    k = 1;
    y = 1.5;
    ln_x_2 = 0.693147;
    k_term = 0.0;
    sum2 = 0.0;
    KMAX = 80000;
    npk_fact.val = 1.0;
    npk_fact.err = 0.0;
    yk = 1.0;
    k_fact = 1.0;
    psi_kp1 = 0.0;
    psi_npkp1 = 0.0;
}