#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int k;
extern int ibeg;
extern int ifin;
extern int jfin;
extern int iglob;
extern double phi2[66][66];



void loop(){
    iglob = ibeg;
    for (i = ibeg; i <= ifin; i++) {
        iglob = i;
        for (int j = 0; j < 1; j++) {
            for (k = ki1; k <= ki2; k++) {
                phi2[i][k] = 0.40000000000000002 * (u[i][jfin][k][4] - 0.5 * (((u[i][jfin][k][1]) * (u[i][jfin][k][1])) + ((u[i][jfin][k][2]) * (u[i][jfin][k][2])) + ((u[i][jfin][k][3]) * (u[i][jfin][k][3]))) / u[i][jfin][k][0]);
            }
        }
    }
}
