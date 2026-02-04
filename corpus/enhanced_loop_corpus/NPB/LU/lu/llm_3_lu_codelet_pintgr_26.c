#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int j;
extern int k;
extern int ibeg;
extern int jbeg;
extern int jfin;
extern int jglob;
extern double phi1[66][66];



void loop(){
for (j = jbeg; j <= jfin; j += 2) {
    jglob = j;
    for (k = ki1; k <= ki2; k += 2) {
        phi1[j][k] = 0.40000000000000002 * (u[ibeg][j][k][4] - 0.5 * (((u[ibeg][j][k][1]) * (u[ibeg][j][k][1])) + ((u[ibeg][j][k][2]) * (u[ibeg][j][k][2])) + ((u[ibeg][j][k][3]) * (u[ibeg][j][k][3]))) / u[ibeg][j][k][0]);
        if (j + 1 <= jfin) {
            phi1[j+1][k] = 0.40000000000000002 * (u[ibeg][j+1][k][4] - 0.5 * (((u[ibeg][j+1][k][1]) * (u[ibeg][j+1][k][1])) + ((u[ibeg][j+1][k][2]) * (u[ibeg][j+1][k][2])) + ((u[ibeg][j+1][k][3]) * (u[ibeg][j+1][k][3]))) / u[ibeg][j+1][k][0]);
        }
        if (k + 1 <= ki2) {
            phi1[j][k+1] = 0.40000000000000002 * (u[ibeg][j][k+1][4] - 0.5 * (((u[ibeg][j][k+1][1]) * (u[ibeg][j][k+1][1])) + ((u[ibeg][j][k+1][2]) * (u[ibeg][j][k+1][2])) + ((u[ibeg][j][k+1][3]) * (u[ibeg][j][k+1][3]))) / u[ibeg][j][k+1][0]);
            if (j + 1 <= jfin) {
                phi1[j+1][k+1] = 0.40000000000000002 * (u[ibeg][j+1][k+1][4] - 0.5 * (((u[ibeg][j+1][k+1][1]) * (u[ibeg][j+1][k+1][1])) + ((u[ibeg][j+1][k+1][2]) * (u[ibeg][j+1][k+1][2])) + ((u[ibeg][j+1][k+1][3]) * (u[ibeg][j+1][k+1][3]))) / u[ibeg][j+1][k+1][0]);
            }
        }
    }
}
}
