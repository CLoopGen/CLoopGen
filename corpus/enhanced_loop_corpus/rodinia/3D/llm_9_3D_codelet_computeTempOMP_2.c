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
for (z = 0; z < nz; z += 2) {
    int y;
    for (y = 0; y < ny; y++) {
        int x;
        for (x = 0; x < nx; x++) {
            int c, w, e, n, s, b, t;
            // Process current point
            c = x + y * nx + z * nx * ny;
            w = (x == 0) ? c : c - 1;
            e = (x == nx - 1) ? c : c + 1;
            n = (y == 0) ? c : c - nx;
            s = (y == ny - 1) ? c : c + nx;
            b = (z == 0) ? c : c - nx * ny;
            t = (z == nz - 1) ? c : c + nx * ny;
            float val = cc * tIn_t[c] + cw * tIn_t[w] + ce * tIn_t[e] + cs * tIn_t[s] + cn * tIn_t[n] + cb * tIn_t[b] + ct * tIn_t[t] + (dt / Cap) * pIn[c] + ct * amb_temp;
            tOut_t[c] = val;

            // Additional computation to increase arithmetic intensity
            // Apply a smoothing step using the updated value
            if (z + 1 < nz) {
                int c_next = c + nx * ny;
                tOut_t[c_next] = 0.5f * (tOut_t[c_next] + val); // Artificial dependency to increase compute
            }
        }
    }
    // Extra inner work to increase computational load
    for (y = 0; y < ny / 2; y++) {
        int idx = y * nx + z * nx * ny;
        tOut_t[idx] = (tOut_t[idx] + tOut_t[idx + nx - 1]) * 0.5f;
    }
}
}
