#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int j;
extern int k;
extern int ifin;
extern int jbeg;
extern int jfin;
extern int jglob;
extern double phi2[66][66];

void loop(){
for (j = jbeg; j <= jfin; j++) {
    jglob = j;
    for (k = ki1; k <= ki2; k++) {
        phi2[j][k] = 0.40000000000000002 * (u[ifin][j][k][4] - 0.5 * (((u[ifin][j][k][1]) * (u[ifin][j][k][1])) + ((u[ifin][j][k][2]) * (u[ifin][j][k][2])) + ((u[ifin][j][k][3]) * (u[ifin][j][k][3]))) / u[ifin][j][k][0]);
    }
}

}
