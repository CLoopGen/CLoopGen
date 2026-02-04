#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double p;
    double q[5];
    int npos[5];
    double np[5];
    double dnp[5];
    size_t n;
} gsl_rstat_quantile_workspace;

extern  double x;
extern gsl_rstat_quantile_workspace *w;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = -1;
    for (i = 0; i <= 3 && k == -1; ++i) {
        double qi = w->q[i];
        double qi1 = w->q[i + 1];
        if (qi <= x && x < qi1) {
            k = i;
        }
    }
}
