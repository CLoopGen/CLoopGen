#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int k2;
extern int m;



void loop(){
for (m = 0; m < 3; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            // Reverse loop order to change data dependency pattern: now forward instead of backward
            // This introduces a new loop-carried RAW dependency due to reversed access
            for (k = 0; k <= grid_points[2] - 3; k++) {
                k1 = k + 1;
                k2 = k + 2;
                // Modify update to accumulate in reverse direction — now current depends on previous (k-1)
                // Original used future values (k+1, k+2); now simulate delayed update with shifted indexing
                if (k > 0) {
                    rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k1] * rhs[m][i][j][k] - lhs[n + 4][i][j][k2] * rhs[m][i][j][k1];
                }
            }
        }
    }
}
}
