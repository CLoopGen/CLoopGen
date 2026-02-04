#include <stdio.h>

extern  int nz;
extern  int ist;
extern  int iend;
extern  double rsd[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int L1;
extern int L2;
extern double q;
extern double u31;



void loop(){
for (k = 1; k <= nz - 2; k++) {
    for (j = L1; j <= L2; j++) {
        for (i = ist; i <= iend; i++) {
            int idx = i * 65 * 65 * 5 + j * 65 * 5 + k * 5;
            flux[0][0][0][idx + 0] = rsd[0][0][0][idx + 2];
            double u31 = rsd[0][0][0][idx + 2] / rsd[0][0][0][idx + 0];
            double q = 0.5 * (rsd[0][0][0][idx + 1] * rsd[0][0][0][idx + 1] +
                              rsd[0][0][0][idx + 2] * rsd[0][0][0][idx + 2] +
                              rsd[0][0][0][idx + 3] * rsd[0][0][0][idx + 3]) / rsd[0][0][0][idx + 0];
            flux[0][0][0][idx + 1] = rsd[0][0][0][idx + 1] * u31;
            flux[0][0][0][idx + 2] = rsd[0][0][0][idx + 2] * u31 + 0.4 * (rsd[0][0][0][idx + 4] - q);
            flux[0][0][0][idx + 3] = rsd[0][0][0][idx + 3] * u31;
            flux[0][0][0][idx + 4] = (1.4 * rsd[0][0][0][idx + 4] - 0.4 * q) * u31;
        }
    }
}
}
