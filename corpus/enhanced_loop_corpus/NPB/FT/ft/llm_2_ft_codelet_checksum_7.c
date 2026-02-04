#include <stdio.h>

typedef struct {
    double real;
    double imag;
} dcomplex;

extern  int xstart[3];
extern  int ystart[3];
extern  int zstart[3];
extern  int xend[3];
extern  int yend[3];
extern  int zend[3];
extern dcomplex u1[128][256][256];
extern int j;
extern int q;
extern int r;
extern int s;
extern dcomplex chk;



void loop(){
for (j = 1; j <= 1024; j++) {
    q = j % 256 + 1;
    if (q >= xstart[0] && q <= xend[0]) {
        r = (3 * j) % 256 + 1;
        if (r >= ystart[0] && r <= yend[0]) {
            s = (5 * j) % 128 + 1;
            if (s >= zstart[0] && s <= zend[0]) {
                int idx_s = s - zstart[0];
                int idx_r = r - ystart[0];
                int idx_q = q - xstart[0];
                // Modify memory access to be consecutive in flattened array form using pointer arithmetic
                dcomplex *base = &u1[0][0][0];
                long offset = idx_s * 256 * 256 + idx_r * 256 + idx_q;
                chk.real += (base + offset)->real;
                chk.imag += (base + offset)->imag;
            }
        }
    }
}
}
