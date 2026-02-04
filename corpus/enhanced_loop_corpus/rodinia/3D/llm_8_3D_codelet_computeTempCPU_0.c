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
    // Variant 1: Increased computational intensity with unrolled inner loop and additional arithmetic operations
    for (z = 0; z < nz; z++)
        for (y = 0; y < ny; y++)
            for (x = 0; x < nx; x += 4) {  // Unroll x-loop by factor of 4
                int c1, c2, c3, c4;
                int w1, w2, w3, w4;
                int e1, e2, e3, e4;
                int n1, n2, n3, n4;
                int s1, s2, s3, s4;
                int b1, b2, b3, b4;
                int t1, t2, t3, t4;

                float temp1, temp2, temp3, temp4;
                float coef = (dt / Cap) * 1.25f + 0.1f * amb_temp;  // Additional computation

                if (x < nx) {
                    c1 = x + y * nx + z * nx * ny;
                    w1 = (x == 0) ? c1 : c1 - 1;
                    e1 = (x == nx - 1) ? c1 : c1 + 1;
                    n1 = (y == 0) ? c1 : c1 - nx;
                    s1 = (y == ny - 1) ? c1 : c1 + nx;
                    b1 = (z == 0) ? c1 : c1 - nx * ny;
                    t1 = (z == nz - 1) ? c1 : c1 + nx * ny;

                    temp1 = tIn[c1] * cc + tIn[n1] * cn + tIn[s1] * cs + tIn[e1] * ce +
                            tIn[w1] * cw + tIn[t1] * ct + tIn[b1] * cb + coef * pIn[c1] +
                            ct * amb_temp * 1.1f;
                    tOut[c1] = temp1 * (1.0f + 0.01f * temp1);  // Nonlinear feedback
                }

                if (x + 1 < nx) {
                    c2 = (x+1) + y * nx + z * nx * ny;
                    w2 = (x+1 == 0) ? c2 : c2 - 1;
                    e2 = (x+1 == nx - 1) ? c2 : c2 + 1;
                    n2 = (y == 0) ? c2 : c2 - nx;
                    s2 = (y == ny - 1) ? c2 : c2 + nx;
                    b2 = (z == 0) ? c2 : c2 - nx * ny;
                    t2 = (z == nz - 1) ? c2 : c2 + nx * ny;

                    temp2 = tIn[c2] * cc + tIn[n2] * cn + tIn[s2] * cs + tIn[e2] * ce +
                            tIn[w2] * cw + tIn[t2] * ct + tIn[b2] * cb + coef * pIn[c2] +
                            ct * amb_temp * 1.1f;
                    tOut[c2] = temp2 * (1.0f + 0.01f * temp2);
                }

                if (x + 2 < nx) {
                    c3 = (x+2) + y * nx + z * nx * ny;
                    w3 = (x+2 == 0) ? c3 : c3 - 1;
                    e3 = (x+2 == nx - 1) ? c3 : c3 + 1;
                    n3 = (y == 0) ? c3 : c3 - nx;
                    s3 = (y == ny - 1) ? c3 : c3 + nx;
                    b3 = (z == 0) ? c3 : c3 - nx * ny;
                    t3 = (z == nz - 1) ? c3 : c3 + nx * ny;

                    temp3 = tIn[c3] * cc + tIn[n3] * cn + tIn[s3] * cs + tIn[e3] * ce +
                            tIn[w3] * cw + tIn[t3] * ct + tIn[b3] * cb + coef * pIn[c3] +
                            ct * amb_temp * 1.1f;
                    tOut[c3] = temp3 * (1.0f + 0.01f * temp3);
                }

                if (x + 3 < nx) {
                    c4 = (x+3) + y * nx + z * nx * ny;
                    w4 = (x+3 == 0) ? c4 : c4 - 1;
                    e4 = (x+3 == nx - 1) ? c4 : c4 + 1;
                    n4 = (y == 0) ? c4 : c4 - nx;
                    s4 = (y == ny - 1) ? c4 : c4 + nx;
                    b4 = (z == 0) ? c4 : c4 - nx * ny;
                    t4 = (z == nz - 1) ? c4 : c4 + nx * ny;

                    temp4 = tIn[c4] * cc + tIn[n4] * cn + tIn[s4] * cs + tIn[e4] * ce +
                            tIn[w4] * cw + tIn[t4] * ct + tIn[b4] * cb + coef * pIn[c4] +
                            ct * amb_temp * 1.1f;
                    tOut[c4] = temp4 * (1.0f + 0.01f * temp4);
                }
            }
}
