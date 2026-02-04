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
for (z = 0; z < nz; z++) {
    int y;
    for (y = 0; y < ny; y++) {
        int x;
        for (x = 0; x < nx; x++) {
            int c, w, e, n, s, b, t;
            c = x + y * nx + z * nx * ny;
            // Eliminate conditional branches by using arithmetic to compute neighbor indices
            w = c - ((x > 0) ? 1 : 0);
            e = c + ((x < nx - 1) ? 1 : 0);
            n = c - ((y > 0) ? nx : 0);
            s = c + ((y < ny - 1) ? nx : 0);
            b = c - ((z > 0) ? nx * ny : 0);
            t = c + ((z < nz - 1) ? nx * ny : 0);
            // Use clamped indices: if condition fails, fall back to center point
            w = (x > 0) ? w : c;
            e = (x < nx - 1) ? e : c;
            n = (y > 0) ? n : c;
            s = (y < ny - 1) ? s : c;
            b = (z > 0) ? b : c;
            t = (z < nz - 1) ? t : c;
            tOut_t[c] = cc * tIn_t[c] + cw * tIn_t[w] + ce * tIn_t[e] + cs * tIn_t[s] + cn * tIn_t[n] + cb * tIn_t[b] + ct * tIn_t[t] + (dt / Cap) * pIn[c] + ct * amb_temp;
        }
    }
}
}
