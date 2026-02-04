#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float amb_temp;
extern float *pIn;
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
extern float *tIn_t;
extern float *tOut_t;
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to favor spatial locality via reordered nested loops (zyx -> xyz), enabling consecutive access in innermost dimension
for (int x = 0; x < nx; x++) {
    for (int z = 0; z < nz; z++) {
        for (int y = 0; y < ny; y++) {
            int c = x + y * nx + z * nx * ny;
            int w = (x == 0) ? c : c - 1;
            int e = (x == nx - 1) ? c : c + 1;
            int n = (y == 0) ? c : c - nx;
            int s = (y == ny - 1) ? c : c + nx;
            int b = (z == 0) ? c : c - nx * ny;
            int t = (z == nz - 1) ? c : c + nx * ny;

            // Access memory with stride-1 pattern in the innermost loop (y-direction now innermost and contiguous in memory)
            tOut_t[c] = cc * tIn_t[c] +
                        cw * tIn_t[w] +
                        ce * tIn_t[e] +
                        cs * tIn_t[s] +
                        cn * tIn_t[n] +
                        cb * tIn_t[b] +
                        ct * tIn_t[t] +
                        (dt / Cap) * pIn[c] +
                        ct * amb_temp;
        }
    }
}
}
