#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz5;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    for (int jj = 1; jj <= grid_points[1] - 2; jj++) {
        for (int kk = 1; kk <= grid_points[2] - 2; kk++) {
            for (int ii = i; ii <= i + 1; ii++) {
                lhs[0][ii][jj][kk] = lhs[0][ii][jj][kk] + comz1;
                lhs[1][ii][jj][kk] = lhs[1][ii][jj][kk] - comz4;
                if (ii == i) {
                    lhs[2][ii][jj][kk] = lhs[2][ii][jj][kk] + comz6;
                    lhs[3][ii][jj][kk] = lhs[3][ii][jj][kk] - comz4;
                } else {
                    lhs[2][ii][jj][kk] = lhs[2][ii][jj][kk] + comz5;
                }
            }
        }
    }
}
