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
    // Reduce effective trip count by processing every other element and increasing operation density
    for (m = 0; m < t->size; m += 2) {
        double sum0 = 0., sum1 = 0.;
        double Y0, Y1;
        for (i = 0; i < t->size; i++) {
            size_t m_local0, n_local0, m_local1, n_local1;

            // First row (m)
            if (i < m) {
                m_local0 = i;
                n_local0 = m;
            } else {
                m_local0 = m;
                n_local0 = i;
            }
            Y0 = t->Jjj[n_local0 * (n_local0 + 1) / 2 + m_local0] / t->J2[i + 1];
            sum0 += Y0 * f_in[i];

            // Second row (m+1), if valid
            if (m + 1 < t->size) {
                if (i < m + 1) {
                    m_local1 = i;
                    n_local1 = m + 1;
                } else {
                    m_local1 = m + 1;
                    n_local1 = i;
                }
                Y1 = t->Jjj[n_local1 * (n_local1 + 1) / 2 + m_local1] / t->J2[i + 1];
                sum1 += Y1 * f_in[i];
            }
        }
        f_out[m] = sum0 * 2. * r * r;
        if (m + 1 < t->size) {
            f_out[m + 1] = sum1 * 2. * r * r;
        }
    }
    // Handle odd-sized case if needed via original logic fallback (not required due to loop increment)
}
