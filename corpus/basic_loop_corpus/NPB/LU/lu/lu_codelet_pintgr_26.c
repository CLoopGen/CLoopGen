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
for (j = jbeg; j <= jfin; j++) {
    jglob = j;
    for (k = ki1; k <= ki2; k++) {
        phi1[j][k] = 0.40000000000000002 * (u[ibeg][j][k][4] - 0.5 * (((u[ibeg][j][k][1]) * (u[ibeg][j][k][1])) + ((u[ibeg][j][k][2]) * (u[ibeg][j][k][2])) + ((u[ibeg][j][k][3]) * (u[ibeg][j][k][3]))) / u[ibeg][j][k][0]);
    }
}

}
