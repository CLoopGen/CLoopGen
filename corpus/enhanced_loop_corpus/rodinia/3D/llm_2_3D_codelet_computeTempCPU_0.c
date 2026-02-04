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
for (z = 0; z < nz; z++)
    for (y = 0; y < ny; y++)
        for (x = 0; x < nx; x++) {
            c = x + y * nx + z * nx * ny;
            w = (x == 0) ? c : c - 1;
            e = (x == nx - 1) ? c : c + 1;
            n = (y == 0) ? c : c - nx;
            s = (y == ny - 1) ? c : c + nx;
            b = (z == 0) ? c : c - nx * ny;
            t = (z == nz - 1) ? c : c + nx * ny;
            // Change memory access pattern to use array of structs-like layout via strided access
            // Assume data is laid out as [tIn_c, tIn_n, tIn_s, tIn_e, tIn_w, tIn_t, tIn_b] per point (interleaved)
            float *base = &tIn[c];
            float coeffs[] = {cc, cn, cs, ce, cw, ct, cb};
            int indices[] = {0, n - c, s - c, e - c, w - c, t - c, b - c};
            tOut[c] = 0.0f;
            for (int i = 0; i < 7; i++) {
                tOut[c] += base[indices[i]] * coeffs[i];
            }
            tOut[c] += (dt / Cap) * pIn[c] + ct * amb_temp;
        }
}
