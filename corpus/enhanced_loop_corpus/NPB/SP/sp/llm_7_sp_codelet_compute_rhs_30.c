#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
double coeff[4] = {-4.0, 6.0, -4.0, 1.0};
int offsets[4] = {i - 1, i, i + 1, i + 2};
for (m = 0; m < 5; m++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double sum = 0.0;
            for (int n = 0; n < 4; n++) {
                sum += coeff[n] * u[m][offsets[n]][j][k];
            }
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * sum;
        }
    }
}
}
