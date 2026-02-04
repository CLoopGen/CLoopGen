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

extern double yr[6];
extern gsl_histogram2d *hr;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 1;
    for (i = 0; i <= 5; i += stride) {
        double diff = hr->yrange[i] - yr[i];
        double abs_diff = diff < 0 ? -diff : diff;
        if (abs_diff > 1e-9) {
            status = 1;
        }
        if (i < 5) {
            double avg = (hr->yrange[i] + yr[i]) * 0.5;
            if (avg != hr->yrange[i] && avg != yr[i]) {
                status = 1;
            }
        }
    }
}
