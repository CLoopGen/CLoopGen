#include <stdlib.h>
#include <math.h>

double ***z;
int mm1 = 128;
int mm2 = 128;
int mm3 = 128;
double ***u;
int i3;
int i2;
int i1;
int d1 = 1;
int d2 = 1;
int d3 = 1;
int t1 = 1;
int t2 = 1;

static double ***allocate_3d_double(int dim1, int dim2, int dim3) {
    double ***ptr = (double***)malloc(dim1 * sizeof(double**));
    double **data = (double**)malloc(dim1 * dim2 * sizeof(double*));
    double *values = (double*)calloc(dim1 * dim2 * dim3, sizeof(double));
    for (int i = 0; i < dim1; i++) {
        ptr[i] = &data[i * dim2];
        for (int j = 0; j < dim2; j++) {
            ptr[i][j] = &values[(i * dim2 + j) * dim3];
        }
    }
    return ptr;
}

void init_vars() {
    const int U_DIM1 = 2 * mm3 - d3 - 1 + 1;
    const int U_DIM2 = 2 * mm2 - d2 - 1 + 1;
    const int U_DIM3 = 2 * mm1 - d1 - 1 + 1;

    const int Z_DIM1 = mm3 + 1;
    const int Z_DIM2 = mm2 + 1;
    const int Z_DIM3 = mm1 + 1;

    u = allocate_3d_double(U_DIM1, U_DIM2, U_DIM3);
    z = allocate_3d_double(Z_DIM1, Z_DIM2, Z_DIM3);

    for (int i = 0; i < Z_DIM1; i++) {
        for (int j = 0; j < Z_DIM2; j++) {
            for (int k = 0; k < Z_DIM3; k++) {
                z[i][j][k] = ((double)rand()) / RAND_MAX;
            }
        }
    }

    for (int i = 0; i < U_DIM1; i++) {
        for (int j = 0; j < U_DIM2; j++) {
            for (int k = 0; k < U_DIM3; k++) {
                u[i][j][k] = ((double)rand()) / RAND_MAX;
            }
        }
    }
}