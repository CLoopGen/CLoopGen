#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern size_t i;
extern size_t i1;
extern size_t i2;
extern size_t i3;
extern size_t i4;
extern double expected;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_expected = 0.;
    for (i = 0; i < 397; i++) {
        temp_expected = 0.;
        if (i == i1) {
            temp_expected = 1.;
        } 
        if (i == i2) {
            temp_expected = 2.;
        } 
        if (i == i3) {
            temp_expected = 3.;
        } 
        if (i == i4) {
            temp_expected = 4.;
        }
        if (h->bin[i] != temp_expected) {
            status = 1;
        }
    }
}
