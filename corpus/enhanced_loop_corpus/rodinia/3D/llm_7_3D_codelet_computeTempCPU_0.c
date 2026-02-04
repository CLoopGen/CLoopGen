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
    for (z = nz - 1; z >= 0; z--)
        for (y = ny - 1; y >= 0; y--)
            for (x = nx - 1; x >= 0; x--) {
                c = x + y * nx + z * nx * ny;
                w = (x == 0) ? c : c - 1;
                e = (x == nx - 1) ? c : c + 1;
                n = (y == 0) ? c : c - nx;
                s = (y == ny - 1) ? c : c + nx;
                b = (z == 0) ? c : c - nx * ny;
                t = (z == nz - 1) ? c : c + nx * ny;
                float neighbor_sum = tIn[c] * cc;
                neighbor_sum += tIn[n] * cn;
                neighbor_sum += tIn[s] * cs;
                neighbor_sum += tIn[e] * ce;
                neighbor_sum += tIn[w] * cw;
                neighbor_sum += tIn[t] * ct;
                neighbor_sum += tIn[b] * cb;
                neighbor_sum += (dt / Cap) * pIn[c] + ct * amb_temp;
                tOut[c] = neighbor_sum;
            }
}
