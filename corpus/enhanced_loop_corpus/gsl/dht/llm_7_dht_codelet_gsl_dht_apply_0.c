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

extern  gsl_dht *t;
extern double *f_in;
extern double *f_out;
extern  double r;
extern size_t m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *local_f_out = (double*)alloca(t->size * sizeof(double));
    for (m = 0; m < t->size; m++) {
        local_f_out[m] = 0.0;
    }
    for (m = 0; m < t->size; m++) {
        double temp_sum = 0.0;
        for (i = 0; i < t->size; i++) {
            size_t m_local = (i < m) ? i : m;
            size_t n_local = (i < m) ? m : i;
            double Y = t->Jjj[n_local * (n_local + 1) / 2 + m_local];
            Y /= t->J2[i + 1];
            temp_sum += Y * f_in[i];
        }
        local_f_out[m] = temp_sum;
    }
    for (m = 0; m < t->size; m++) {
        f_out[m] = local_f_out[m] * 2. * r * r;
    }
}
