#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *i0;
extern real *z__;
extern real *dmin__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real d__;
extern integer j4;
extern real emin;
extern real temp;
extern real safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with increased stride (access every 8th element, simulating block processing)
    integer step;
    for (step = *i0 << 2; step <= i__1; step += 8) {  // Double the increment to create strided traversal
        j4 = step;
        // Simulate irregular or strided pattern: skip some updates, process only on 8-stride
        z__[j4 - 2] = d__ + z__[j4 - 1];
        if (z__[j4 - 2] == 0.F) {
            z__[j4] = 0.F;
            d__ = z__[j4 + 1];
            *dmin__ = d__;
            emin = 0.F;
        } else if (safmin * z__[j4 + 1] < z__[j4 - 2] && safmin * z__[j4 - 2] < z__[j4 + 1]) {
            temp = z__[j4 + 1] / z__[j4 - 2];
            z__[j4] = z__[j4 - 1] * temp;
            d__ *= temp;
        } else {
            z__[j4] = z__[j4 + 1] * (z__[j4 - 1] / z__[j4 - 2]);
            d__ = z__[j4 + 1] * (d__ / z__[j4 - 2]);
        }
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        r__1 = emin, r__2 = z__[j4];
        emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
        
        // Optional second update within same iteration (simulates burst in strided access)
        if (j4 + 4 <= i__1) {
            integer j4_inner = j4 + 4;
            z__[j4_inner - 2] = d__ + z__[j4_inner - 1];
            if (z__[j4_inner - 2] == 0.F) {
                z__[j4_inner] = 0.F;
                d__ = z__[j4_inner + 1];
                *dmin__ = d__;
                emin = 0.F;
            } else if (safmin * z__[j4_inner + 1] < z__[j4_inner - 2] && safmin * z__[j4_inner - 2] < z__[j4_inner + 1]) {
                temp = z__[j4_inner + 1] / z__[j4_inner - 2];
                z__[j4_inner] = z__[j4_inner - 1] * temp;
                d__ *= temp;
            } else {
                z__[j4_inner] = z__[j4_inner + 1] * (z__[j4_inner - 1] / z__[j4_inner - 2]);
                d__ = z__[j4_inner + 1] * (d__ / z__[j4_inner - 2]);
            }
            *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
            r__1 = emin, r__2 = z__[j4_inner];
            emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
        }
    }
}
