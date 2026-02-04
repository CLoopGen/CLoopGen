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
        for (x = 0; x < nx; x += 2) {
            int c1, c2, w1, w2, e1, e2, n1, n2, s1, s2, b1, b2, t1, t2;
            // First element
            c1 = x + y * nx + z * nx * ny;
            w1 = (x == 0) ? c1 : c1 - 1;
            e1 = (x == nx - 1) ? c1 : c1 + 1;
            n1 = (y == 0) ? c1 : c1 - nx;
            s1 = (y == ny - 1) ? c1 : c1 + nx;
            b1 = (z == 0) ? c1 : c1 - nx * ny;
            t1 = (z == nz - 1) ? c1 : c1 + nx * ny;
            tOut_t[c1] = cc * tIn_t[c1] + cw * tIn_t[w1] + ce * tIn_t[e1] + cs * tIn_t[s1] + cn * tIn_t[n1] + cb * tIn_t[b1] + ct * tIn_t[t1] + (dt / Cap) * pIn[c1] + ct * amb_temp;

            // Second element (if within bounds)
            if (x + 1 < nx) {
                c2 = c1 + 1;
                w2 = c1; // always valid since x+1 >= 1
                e2 = (x + 1 == nx - 1) ? c2 : c2 + 1;
                n2 = (y == 0) ? c2 : c2 - nx;
                s2 = (y == ny - 1) ? c2 : c2 + nx;
                b2 = (z == 0) ? c2 : c2 - nx * ny;
                t2 = (z == nz - 1) ? c2 : c2 + nx * ny;
                tOut_t[c2] = cc * tIn_t[c2] + cw * tIn_t[w2] + ce * tIn_t[e2] + cs * tIn_t[s2] + cn * tIn_t[n2] + cb * tIn_t[b2] + ct * tIn_t[t2] + (dt / Cap) * pIn[c2] + ct * amb_temp;
            }
        }
    }
}
}
