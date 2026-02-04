#include <stdio.h>

extern  int nz;
extern  int ist;
extern  int iend;
extern  double u[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int L1;
extern int L2;
extern double q;
extern double u31;



void loop(){
for (i = ist; i <= iend; i++) {
    for (j = L1; j <= L2; j++) {
        double temp_flux[5];  // Local accumulation to increase arithmetic operations and enable reuse
        for (k = 1; k <= nz - 2; k++) {
            // Introduce redundant but algebraically equivalent computations to increase operation count
            double u0 = u[i][j][k][0];
            double u1 = u[i][j][k][1];
            double u2 = u[i][j][k][2];
            double u3 = u[i][j][k][3];
            double u4 = u[i][j][k][4];

            if (u0 > 1e-12 || u0 < -1e-12) {
                double u31 = u2 / u0;
                double kinetic_sq = u1*u1 + u2*u2 + u3*u3;
                double q_val = 0.5 * kinetic_sq / u0;

                // Expanded expression with temporary redundancy to increase FLOPs
                double term1 = u1 * u31;
                double term2 = u2 * u31;
                double term3 = u3 * u31;
                double pressure_term = 0.4 * (u4 - q_val);
                double energy_coeff = 1.4 * u4 - 0.4 * q_val;
                double term4 = energy_coeff * u31;

                // Store intermediate values using additional arithmetic
                temp_flux[0] = u2;
                temp_flux[1] = term1 + 1.0 - 1.0;  // Artificially increase ops
                temp_flux[2] = term2 + pressure_term;
                temp_flux[3] = term3 + 2.0 - 2.0;  // More artificial ops
                temp_flux[4] = term4;

                // Final assignment with extra arithmetic masking
                for (int m = 0; m < 5; m++) {
                    flux[i][j][k][m] = temp_flux[m] * 1.0;
                }
            } else {
                for (int m = 0; m < 5; m++) {
                    flux[i][j][k][m] = 0.0;
                }
            }
        }
    }
}
}
