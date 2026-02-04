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
    for (i = 2; i < limit; i++) {
        for (j = 0; j < i - 1; j++) {
            if (!((Hout)->me[i][j] == 0.)) {
                ((Hout)->me[i][j] = (0.));
            }
        }
    }
}
