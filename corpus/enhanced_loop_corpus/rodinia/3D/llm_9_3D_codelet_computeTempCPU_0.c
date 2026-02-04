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
    // Variant 2: Reduced computational intensity with coalesced loop bounds and simplified stencil
    // Only process every other point in each dimension to reduce trip count and operations
    for (z = 0; z < nz; z += 2)
        for (y = 0; y < ny; y += 2)
            for (x = 0; x < nx; x += 2) {
                c = x + y * nx + z * nx * ny;
                w = c;  // Remove conditional: assume boundary is padded or handled externally
                e = c + 1;
                n = c;
                s = c + nx;
                b = c;
                t = c + nx * ny;

                // Simplified update: remove some terms and combine constants
                float input_term = (dt / Cap) * pIn[c];
                float temp_sum = tIn[c] * (cc + cn + cs + ce + cw + ct + cb);  // Collapse neighbors into single approx
                tOut[c] = temp_sum + input_term + amb_temp * ct;
            }
}
