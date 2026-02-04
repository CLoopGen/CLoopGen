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
for (j = 1; j <= 512; j++) {
    q = (j * 7) % 256 + 1;
    r = (j * 11) % 256 + 1;
    s = (j * 13) % 128 + 1;
    if (q >= xstart[0] && q <= xend[0] &&
        r >= ystart[0] && r <= yend[0] &&
        s >= zstart[0] && s <= zend[0]) {
        double temp_real = u1[s - zstart[0]][r - ystart[0]][q - xstart[0]].real;
        double temp_imag = u1[s - zstart[0]][r - ystart[0]][q - xstart[0]].imag;
        chk.real = chk.real + temp_real * temp_real;
        chk.imag = chk.imag + temp_imag * temp_imag;
    }
}
}
