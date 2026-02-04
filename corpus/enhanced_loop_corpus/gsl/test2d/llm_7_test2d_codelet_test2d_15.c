#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern gsl_histogram2d *h;
extern gsl_histogram2d *h1;
extern gsl_histogram2d *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < 107 * 239; j += 2) {
        size_t idx1 = j;
        size_t idx2 = j + 1;
        int local_status1 = 0, local_status2 = 0;
        
        if (idx1 < 107 * 239) {
            if (h1->bin[idx1] != g->bin[idx1] + h->bin[idx1])
                local_status1 = 1;
        }
        if (idx2 < 107 * 239) {
            if (h1->bin[idx2] != g->bin[idx2] + h->bin[idx2])
                local_status2 = 1;
        }
        if (local_status1 || local_status2)
            status = 1;
    }
}
