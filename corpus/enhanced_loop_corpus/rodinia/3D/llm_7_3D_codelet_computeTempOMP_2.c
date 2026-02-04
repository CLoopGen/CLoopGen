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
            int c = x + y * nx + z * nx * ny;
            int w = c - 1;
            int e = c + 1;
            int n = c - nx;
            int s = c + nx;
            int b = c - nx * ny;
            int t = c + nx * ny;

            float contribution = cc * tIn_t[c];
            contribution += cw * tIn_t[w] + ce * tIn_t[e];
            contribution += cn * tIn_t[n] + cs * tIn_t[s];
            contribution += cb * tIn_t[b] + ct * tIn_t[t];
            contribution += (dt / Cap) * pIn[c];
            contribution += ct * amb_temp;

            tOut_t[c] = contribution;

            // Introduce artificial loop-carried dependency: each point depends on previous x value
            if (x > 1) {
                tOut_t[c] += 0.01f * tOut_t[c - 1];  // WAW + RAW dependency introduced across iterations
            }
        }
    }
}
}
