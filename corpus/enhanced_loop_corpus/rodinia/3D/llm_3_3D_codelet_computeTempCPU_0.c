#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float amb_temp;
extern float *pIn;
extern float *tIn;
extern float *tOut;
extern int nx;
extern int ny;
extern int nz;
extern float Cap;
extern float dt;
extern float ce;
extern float cw;
extern float cn;
extern float cs;
extern float ct;
extern float cb;
extern float cc;
extern int c;
extern int w;
extern int e;
extern int n;
extern int s;
extern int b;
extern int t;
extern int x;
extern int y;
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change to indirect (gather) memory access using precomputed neighbor indices
// Precompute index map externally (assumed available), here we simulate with local logic
int * __restrict idx = (int*)malloc((nx * ny * nz) * 7 * sizeof(int));
#pragma omp simd
for (int i = 0; i < nx * ny * nz; i++) {
    x = i % nx;
    y = (i / nx) % ny;
    z = i / (nx * ny);
    int c = x + y * nx + z * nx * ny;
    int w = (x == 0) ? c : c - 1;
    int e = (x == nx - 1) ? c : c + 1;
    int n = (y == 0) ? c : c - nx;
    int s = (y == ny - 1) ? c : c + nx;
    int b = (z == 0) ? c : c - nx * ny;
    int t = (z == nz - 1) ? c : c + nx * ny;
    idx[i*7+0] = c;   // center
    idx[i*7+1] = n;   // north
    idx[i*7+2] = s;   // south
    idx[i*7+3] = e;   // east
    idx[i*7+4] = w;   // west
    idx[i*7+5] = t;   // top
    idx[i*7+6] = b;   // bottom
}

for (z = 0; z < nz; z++)
    for (y = 0; y < ny; y++)
        for (x = 0; x < nx; x++) {
            int i = x + y * nx + z * nx * ny;
            int *idx_base = &idx[i * 7];
            tOut[idx_base[0]] = 
                tIn[idx_base[0]] * cc +
                tIn[idx_base[1]] * cn +
                tIn[idx_base[2]] * cs +
                tIn[idx_base[3]] * ce +
                tIn[idx_base[4]] * cw +
                tIn[idx_base[5]] * ct +
                tIn[idx_base[6]] * cb +
                (dt / Cap) * pIn[idx_base[0]] + ct * amb_temp;
        }
free(idx);
}
