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
            w = c - 1;
            e = c + 1;
            n = c - nx;
            s = c + nx;
            b = c - nx * ny;
            t = c + nx * ny;

            // Clamp indices to stay within valid bounds (removes conditionals by using arithmetic clamping)
            if (x == 0)       w = c;
            if (x == nx-1)    e = c;
            if (y == 0)       n = c;
            if (y == ny-1)    s = c;
            if (z == 0)       b = c;
            if (z == nz-1)    t = c;

            tOut[c] = tIn[c] * cc + tIn[n] * cn + tIn[s] * cs + tIn[e] * ce + tIn[w] * cw + tIn[t] * ct + tIn[b] * cb + (dt / Cap) * pIn[c] + ct * amb_temp;
        }
}
