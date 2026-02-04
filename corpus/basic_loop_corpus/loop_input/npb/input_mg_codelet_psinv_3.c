#include <stdlib.h>
#include <string.h>

double ***r;
double ***u;
int n1 = 256;
int n2 = 256;
int n3 = 256;
double c[4] = {0.1, 0.2, 0.3, 0.4};
int i3;
int i2;
int i1;
double r1[1037];
double r2[1037];

void init_vars() {
    // Allocate r and u as 3D arrays with dimensions [n3][n2][n1]
    r = (double***)calloc(n3, sizeof(double**));
    u = (double***)calloc(n3, sizeof(double**));
    
    for (int i = 0; i < n3; i++) {
        r[i] = (double**)calloc(n2, sizeof(double*));
        u[i] = (double**)calloc(n2, sizeof(double*));
        
        for (int j = 0; j < n2; j++) {
            r[i][j] = (double*)calloc(n1, sizeof(double));
            u[i][j] = (double*)calloc(n1, sizeof(double));
        }
    }

    // Initialize r with non-zero values to avoid trivial computation
    for (int i = 0; i < n3; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < n1; k++) {
                r[i][j][k] = (double)(i + j + k) * 1e-3;
            }
        }
    }

    // Ensure r1 and r2 are initialized to zero
    memset(r1, 0, sizeof(r1));
    memset(r2, 0, sizeof(r2));

    // Adjust loop bounds to prevent out-of-bounds access
    // Original loop uses i3 from 1 to n3-2, i2 from 1 to n2-2, i1 from 0 to n1-1
    // So we need at least 3 in each dimension -> ensured by n1=n2=n3=256
}