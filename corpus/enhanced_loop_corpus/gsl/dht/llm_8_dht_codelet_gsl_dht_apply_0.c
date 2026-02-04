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
    for (m = 0; m < t->size; m++) {
        double sum = 0.;
        double Y;
        size_t unroll_factor = 4;
        i = 0;
        // Unrolled loop to increase computational intensity
        for (; i + 3 < t->size; i += 4) {
            size_t m_local1, n_local1, m_local2, n_local2, m_local3, n_local3, m_local4, n_local4;
            if (i < m) {
                m_local1 = i;     n_local1 = m;
            } else {
                m_local1 = m;     n_local1 = i;
            }
            if (i+1 < m) {
                m_local2 = i+1;   n_local2 = m;
            } else {
                m_local2 = m;     n_local2 = i+1;
            }
            if (i+2 < m) {
                m_local3 = i+2;   n_local3 = m;
            } else {
                m_local3 = m;     n_local3 = i+2;
            }
            if (i+3 < m) {
                m_local4 = i+3;   n_local4 = m;
            } else {
                m_local4 = m;     n_local4 = i+3;
            }

            Y = t->Jjj[n_local1 * (n_local1 + 1) / 2 + m_local1] / t->J2[i + 1];
            sum += Y * f_in[i];

            Y = t->Jjj[n_local2 * (n_local2 + 1) / 2 + m_local2] / t->J2[i + 2];
            sum += Y * f_in[i+1];

            Y = t->Jjj[n_local3 * (n_local3 + 1) / 2 + m_local3] / t->J2[i + 3];
            sum += Y * f_in[i+2];

            Y = t->Jjj[n_local4 * (n_local4 + 1) / 2 + m_local4] / t->J2[i + 4];
            sum += Y * f_in[i+3];
        }
        // Handle remaining elements
        for (; i < t->size; i++) {
            size_t m_local, n_local;
            if (i < m) {
                m_local = i;
                n_local = m;
            } else {
                m_local = m;
                n_local = i;
            }
            Y = t->Jjj[n_local * (n_local + 1) / 2 + m_local] / t->J2[i + 1];
            sum += Y * f_in[i];
        }
        f_out[m] = sum * 2. * r * r;
    }
}
