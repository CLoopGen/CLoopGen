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
        for (int offset = 0; offset <= 1; offset++) {
            int idx = i + offset;
            lhs[2][idx][jj][kk] = lhs[2][idx][jj][kk] + (offset == 0 ? comz5 : comz6);
            lhs[3][idx][jj][kk] = lhs[3][idx][jj][kk] - comz4;
            lhs[4][idx][jj][kk] = lhs[4][idx][jj][kk] + comz1;
            if (offset == 0) {
                lhs[1][idx + 1][jj][kk] = lhs[1][idx + 1][jj][kk] - comz4;
            }
        }
    }
}
}
