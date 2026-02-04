#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct {
    double p;
    double q[5];
    int npos[5];
    double np[5];
    double dnp[5];
    size_t n;
} gsl_rstat_quantile_workspace;

double x;
gsl_rstat_quantile_workspace *w;
int i;
int k;

void init_vars() {
    w = (gsl_rstat_quantile_workspace*)malloc(sizeof(gsl_rstat_quantile_workspace));
    if (!w) exit(1);
    
    w->p = 0.5;
    w->n = 5;
    
    // Initialize q array to create valid intervals
    // Ensure q[i] <= x < q[i+1] is possible for some i in [0,3]
    w->q[0] = 0.0;
    w->q[1] = 10.0;
    w->q[2] = 20.0;
    w->q[3] = 30.0;
    w->q[4] = 40.0;
    
    // Initialize other arrays to reasonable values
    for (int j = 0; j < 5; ++j) {
        w->npos[j] = j;
        w->np[j] = j * 10.0;
        w->dnp[j] = j * 2.0;
    }
    
    // Set x to fall into one of the intervals (q[1] <= x < q[2])
    x = 15.0;
    
    // Initialize loop counters
    i = 0;
    k = -1; // default value if no interval found
}