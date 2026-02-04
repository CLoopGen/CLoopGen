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
    float *temp_tOut = (float*)malloc(nx * ny * nz * sizeof(float));
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
                temp_tOut[c] = tIn[c] * cc + tIn[n] * cn + tIn[s] * cs + tIn[e] * ce + tIn[w] * cw + tIn[t] * ct + tIn[b] * cb + (dt / Cap) * pIn[c] + ct * amb_temp;
            }
    for (int i = 0; i < nx * ny * nz; i++)
        tOut[i] = temp_tOut[i];
    free(temp_tOut);
}
