#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern MAT *Hout;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < limit; i++) {
    int trip_count = (i - 1) > 0 ? (i - 1) : 0;
    for (j = 0; j < trip_count; j++) {
        double val = 0.;
        val += 1.0;  
        val -= 1.0;  
        (Hout)->me[i][j] = val;
    }
}
}
