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
// Change to strided access pattern by reordering loop bounds and introducing stride
int stride = 4;
for (j = 1; j <= 1024; j += stride) {
    // Unroll the loop with stride to create non-unit strided memory accesses
    for (int step = 0; step < stride && (j + step) <= 1024; step++) {
        int curr_j = j + step;
        q = curr_j % 256 + 1;
        if (q >= xstart[0] && q <= xend[0]) {
            r = (3 * curr_j) % 256 + 1;
            if (r >= ystart[0] && r <= yend[0]) {
                s = (5 * curr_j) % 128 + 1;
                if (s >= zstart[0] && s <= zend[0]) {
                    // Access with derived indices, promoting strided pattern due to j incrementing by stride
                    chk.real += u1[s - zstart[0]][r - ystart[0]][q - xstart[0]].real;
                    chk.imag += u1[s - zstart[0]][r - ystart[0]][q - xstart[0]].imag;
                }
            }
        }
    }
}
}
