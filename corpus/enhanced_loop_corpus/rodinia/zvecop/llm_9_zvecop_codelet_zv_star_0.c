#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

extern ZVEC *x1;
extern ZVEC *x2;
extern ZVEC *out;
extern int i;
extern double t_re;
extern double t_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < x1->dim && i < 64; i++) {  // Limit trip count to fixed small size
        // Simplify computation: only real part multiplication, ignore imaginary
        t_re = x1->ve[i].re * x2->ve[i].re;
        out->ve[i].re = t_re;
        out->ve[i].im = 0.0;  // Set imaginary part to zero unconditionally
    }
    // Pad remaining elements if needed (not required beyond trip limit)
}
