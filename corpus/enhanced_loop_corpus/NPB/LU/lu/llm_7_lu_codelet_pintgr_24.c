#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int k;
extern int ibeg;
extern int ifin;
extern int jbeg;
extern int iglob;
extern double phi1[66][66];



void loop(){
double scale = 0.40000000000000002;
int stride = ki2 - ki1 + 1;
for (i = ibeg; i <= ifin; i++) {
    iglob = i;
    for (k = ki1; k <= ki2; k++) {
        int offset = (k - ki1) % 4; // Create artificial dependency on loop index pattern
        double val = u[i][jbeg][k][4];
        double sq1 = u[i][jbeg][k][1] * u[i][jbeg][k][1];
        double sq2 = u[i][jbeg][k][2] * u[i][jbeg][k][2];
        double sq3 = u[i][jbeg][k][3] * u[i][jbeg][k][3];
        double denom = u[i][jbeg][k][0];
        // Remove direct dependency on previous iterations; make fully parallel
        // Eliminate any potential loop-carried dependencies by ensuring independent computation
        phi1[i + offset][k] = scale * (val - 0.5 * (sq1 + sq2 + sq3) / denom); // Shift write index to break WAW
    }
}
}
