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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[5];
    for (i = 0; i < 5; ++i)
        temp[i] = w->np[i] + w->dnp[i];
    for (i = 0; i < 5; ++i)
        w->np[i] = temp[i];
}
