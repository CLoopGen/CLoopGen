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

            // Remove conditional branching by precomputing neighbor indices with bounds-aware selection
            w = (x > 0) ? c - 1 : c;
            e = (x < nx - 1) ? c + 1 : c;
            n = (y > 0) ? c - nx : c;
            s = (y < ny - 1) ? c + nx : c;
            b = (z > 0) ? c - nx * ny : c;
            t = (z < nz - 1) ? c + nx * ny : c;

            // Introduce early-out based on input data (new control path)
            if (pIn[c] <= 0.0f && tIn[c] >= amb_temp) {
                tOut[c] = tIn[c];
                continue;
            }

            tOut[c] = tIn[c] * cc + tIn[n] * cn + tIn[s] * cs + tIn[e] * ce + tIn[w] * cw + tIn[t] * ct + tIn[b] * cb + (dt / Cap) * pIn[c] + ct * amb_temp;
        }
}
