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
    if (q < xstart[0] || q > xend[0]) continue;
    r = (3 * j) % 256 + 1;
    if (r < ystart[0] || r > yend[0]) continue;
    s = (5 * j) % 128 + 1;
    if (s < zstart[0] || s > zend[0]) continue;
    chk.real += u1[s - zstart[0]][r - ystart[0]][q - xstart[0]].real;
    chk.imag += u1[s - zstart[0]][r - ystart[0]][q - xstart[0]].imag;
}
}
