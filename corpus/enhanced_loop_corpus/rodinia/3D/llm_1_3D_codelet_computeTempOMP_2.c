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
int idx = 0;
for (z = 0; z < nz; z++) {
    int y;
    for (y = 0; y < ny; y++) {
        int x;
        for (x = 0; x < nx; x++) {
            int c, w, e, n, s, b, t;
            c = idx;
            w = (x == 0) ? c : c - 1;
            e = (x == nx - 1) ? c : c + 1;
            n = (y == 0) ? c : c - nx;
            s = (y == ny - 1) ? c : c + nx;
            b = (z == 0) ? c : c - nx * ny;
            t = (z == nz - 1) ? c : c + nx * ny;
            tOut_t[c] = cc * tIn_t[c] + cw * tIn_t[w] + ce * tIn_t[e] + cs * tIn_t[s] + cn * tIn_t[n] + cb * tIn_t[b] + ct * tIn_t[t] + (dt / Cap) * pIn[c] + ct * amb_temp;
            idx++;
        }
    }
}
}
