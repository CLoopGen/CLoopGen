#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_dht_struct {
    size_t size;
    double nu;
    double xmax;
    double kmax;
    double *j;
    double *Jjj;
    double *J2;
};

typedef struct gsl_dht_struct gsl_dht;

gsl_dht *t;
double *f_in;
double *f_out;
double r;
size_t m;
size_t i;

void init_vars() {
    const size_t data_size = 2048; // Choose size so that inner loop accesses ~n^2/2, total operations ~O(n^2) => 2048^2 ~ 4M elements reasonable for ~0.01 sec

    t = (gsl_dht *)malloc(sizeof(gsl_dht));
    if (!t) exit(1);

    t->size = data_size;
    t->nu = 1.5;
    t->xmax = 10.0;
    t->kmax = 5.0;

    t->j = (double *)malloc((data_size + 1) * sizeof(double));
    t->Jjj = (double *)malloc(((data_size + 1) * (data_size + 2) / 2) * sizeof(double));
    t->J2 = (double *)malloc((data_size + 1) * sizeof(double));

    f_in = (double *)malloc(data_size * sizeof(double));
    f_out = (double *)malloc(data_size * sizeof(double));

    r = 0.75;

    if (!t->j || !t->Jjj || !t->J2 || !f_in || !f_out) exit(1);

    for (size_t idx = 0; idx <= data_size; idx++) {
        t->j[idx] = 1.0 + (idx * 0.01);
    }

    for (size_t idx = 0; idx < ((data_size + 1) * (data_size + 2) / 2); idx++) {
        t->Jjj[idx] = 1.0 + (idx % 100) * 0.01;
    }

    for (size_t idx = 0; idx <= data_size; idx++) {
        t->J2[idx] = 1.0 + (idx * 0.02);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        f_in[idx] = 1.0 + (idx % 50) * 0.01;
        f_out[idx] = 0.0;
    }
}