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

extern gsl_rstat_quantile_workspace *w;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = k + 1; i <= 4; ++i)
    ++(w->npos[i]);

}
