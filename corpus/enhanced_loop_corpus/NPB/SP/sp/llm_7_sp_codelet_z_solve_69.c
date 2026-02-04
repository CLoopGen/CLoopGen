#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int m;



void loop(){
double update_buffer[65][65] = {0};
int m_start = 3;
int m_end = 5;
for (m = m_start; m < m_end; m++) {
    n = (m - 3 + 1) * 5;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            update_buffer[i][j] = lhs[n + 3][i][j][k] * rhs[m][i][j][k1];
        }
    }
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            rhs[m][i][j][k] -= update_buffer[i][j];
        }
    }
}
}
