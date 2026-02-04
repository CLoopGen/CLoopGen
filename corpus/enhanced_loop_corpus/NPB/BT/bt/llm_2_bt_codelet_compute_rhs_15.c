#include <stdio.h>

extern  int grid_points[3];
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern double rho_inv;



void loop(){
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                int idx = i * grid_points[1] * grid_points[2] + j * grid_points[2] + k;
                rho_inv = 1.0 / ((double*)u)[idx * 5 + 0];
                ((double*)rho_i)[idx] = rho_inv;
                ((double*)us)[idx] = ((double*)u)[idx * 5 + 1] * rho_inv;
                ((double*)vs)[idx] = ((double*)u)[idx * 5 + 2] * rho_inv;
                ((double*)ws)[idx] = ((double*)u)[idx * 5 + 3] * rho_inv;
                double sq = 0.5 * (
                    ((double*)u)[idx * 5 + 1] * ((double*)u)[idx * 5 + 1] +
                    ((double*)u)[idx * 5 + 2] * ((double*)u)[idx * 5 + 2] +
                    ((double*)u)[idx * 5 + 3] * ((double*)u)[idx * 5 + 3]
                ) * rho_inv;
                ((double*)square)[idx] = sq;
                ((double*)qs)[idx] = sq * rho_inv;
            }
        }
    }
}
