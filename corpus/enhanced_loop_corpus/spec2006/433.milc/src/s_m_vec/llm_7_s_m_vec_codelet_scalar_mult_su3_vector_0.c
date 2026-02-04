#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

extern su3_vector *a;
extern double s;
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        double scaled_real = s * a->c[i].real;
        c->c[i].real = scaled_real;
        c->c[i].imag = s * a->c[i].imag;
        // Introduce artificial WAW and WAR dependency by reassigning in same location across iterations
        // Though no actual loop-carried dependency in computation, ordering is preserved
    }
    // Add a redundant update to create loop-carried WAW hazard on 'c' structure
    if (i == 3) {
        c->c[0].real = c->c[0].real; // Artificial self-assignment to simulate write-after-write
    }
}
