#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[65][65][65][5];
extern double rms[5];
extern int i;
extern int j;
extern int k;
extern int m;
extern double add;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            double temp_rms[5] = {0}; // Introduce local accumulation to remove WAW and WAR dependencies on rms[]
            for (m = 0; m < 5; m++) {
                add = rhs[i][j][k][m];
                temp_rms[m] = add * add;
            }
            // Update global rms[] only once per (i,j,k) to reduce loop-carried write conflicts
            for (m = 0; m < 5; m++) {
                rms[m] = rms[m] + temp_rms[m];
            }
        }
    }
}
}
