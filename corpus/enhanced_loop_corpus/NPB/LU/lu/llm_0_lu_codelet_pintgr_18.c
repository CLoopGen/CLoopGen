#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int ibeg;
extern int ifin;
extern int jbeg;
extern int jfin;
extern int iglob;
extern int jglob;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = ibeg; i <= ifin; i++) {
    iglob = i;
    for (j = jbeg; j <= jfin; j++) {
        jglob = j;
        for (k = ki1; k <= ki2; k++) {
            if (k == ki1) {
                phi1[i][j] = 0.40000000000000002 * (u[i][j][k][4] - 0.5 * (((u[i][j][k][1]) * (u[i][j][k][1])) + ((u[i][j][k][2]) * (u[i][j][k][2])) + ((u[i][j][k][3]) * (u[i][j][k][3]))) / u[i][j][k][0]);
            }
            if (k == ki2) {
                phi2[i][j] = 0.40000000000000002 * (u[i][j][k][4] - 0.5 * (((u[i][j][k][1]) * (u[i][j][k][1])) + ((u[i][j][k][2]) * (u[i][j][k][2])) + ((u[i][j][k][3]) * (u[i][j][k][3]))) / u[i][j][k][0]);
            }
        }
    }
}
}
