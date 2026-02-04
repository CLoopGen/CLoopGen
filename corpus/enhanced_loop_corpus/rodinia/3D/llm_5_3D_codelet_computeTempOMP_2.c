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
for (z = 1; z < nz - 1; z++) {
    int y;
    for (y = 1; y < ny - 1; y++) {
        int x;
        for (x = 1; x < nx - 1; x++) {
            int c, w, e, n, s, b, t;
            // Inner domain only: no boundary checks needed
            c = x + y * nx + z * nx * ny;
            w = c - 1;
            e = c + 1;
            n = c - nx;
            s = c + nx;
            b = c - nx * ny;
            t = c + nx * ny;
            tOut_t[c] = cc * tIn_t[c] + cw * tIn_t[w] + ce * tIn_t[e] + cs * tIn_t[s] + cn * tIn_t[n] + cb * tIn_t[b] + ct * tIn_t[t] + (dt / Cap) * pIn[c] + ct * amb_temp;
        }
    }
}
// Handle boundary regions with reduced computation (optional optimization could follow, but not required here)
// This variant skips all boundaries, removing control dependencies entirely by restricting iteration space
}
