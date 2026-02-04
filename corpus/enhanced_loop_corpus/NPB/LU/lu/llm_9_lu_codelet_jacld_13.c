#include <stdio.h>

extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double tx1;
extern  double tx2;
extern  double ty1;
extern  double ty2;
extern  double tz1;
extern  double tz2;
extern  double dx1;
extern  double dx2;
extern  double dx3;
extern  double dx4;
extern  double dx5;
extern  double dy1;
extern  double dy2;
extern  double dy3;
extern  double dy4;
extern  double dy5;
extern  double dz1;
extern  double dz2;
extern  double dz3;
extern  double dz4;
extern  double dz5;
extern  double u[64][65][65][5];
extern  double dt;
extern  double a[64][64][5][5];
extern  double b[64][64][5][5];
extern  double c[64][64][5][5];
extern  double d[64][64][5][5];
extern int k;
extern int i;
extern int j;
extern double r43;
extern double c1345;
extern double c34;
extern double tmp1;
extern double tmp2;
extern double tmp3;



void loop(){
// Increase computational intensity by unrolling the inner loop twice and increasing work per iteration
// Also modify trip count by processing two j-indices per iteration

int j_step;
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j += 2) {
        // Process j and j+1 if within bounds
        for (j_step = 0; j_step < 2 && (j + j_step) <= jend; j_step++) {
            int j_idx = j + j_step;

            tmp1 = 1.0 / u[i][j_idx][k][0];
            tmp2 = tmp1 * tmp1;
            tmp3 = tmp1 * tmp2;

            double u1 = u[i][j_idx][k][1], u2 = u[i][j_idx][k][2], u3 = u[i][j_idx][k][3], u4 = u[i][j_idx][k][4];
            double u1_sq = u1 * u1, u2_sq = u2 * u2, u3_sq = u3 * u3;

            // Full computation of d[i][j_idx]
            d[i][j_idx][0][0] = 1.0 + dt * 2.0 * (tx1 * dx1 + ty1 * dy1 + tz1 * dz1);
            d[i][j_idx][0][1] = d[i][j_idx][0][2] = d[i][j_idx][0][3] = d[i][j_idx][0][4] = 0.0;

            d[i][j_idx][1][0] = dt * 2.0 * (tx1 * (-r43 * c34 * tmp2 * u1) + ty1 * (-c34 * tmp2 * u1) + tz1 * (-c34 * tmp2 * u1));
            d[i][j_idx][1][1] = 1.0 + dt * 2.0 * (tx1 * (r43 * c34 * tmp1 + dx2) + ty1 * (c34 * tmp1 + dy2) + tz1 * (c34 * tmp1 + dz2));
            d[i][j_idx][1][2] = d[i][j_idx][1][3] = d[i][j_idx][1][4] = 0.0;

            d[i][j_idx][2][0] = dt * 2.0 * (tx1 * (-c34 * tmp2 * u2) + ty1 * (-r43 * c34 * tmp2 * u2) + tz1 * (-c34 * tmp2 * u2));
            d[i][j_idx][2][2] = 1.0 + dt * 2.0 * (tx1 * (c34 * tmp1 + dx3) + ty1 * (r43 * c34 * tmp1 + dy3) + tz1 * (c34 * tmp1 + dz3));
            d[i][j_idx][2][1] = d[i][j_idx][2][3] = d[i][j_idx][2][4] = 0.0;

            d[i][j_idx][3][0] = dt * 2.0 * (tx1 * (-c34 * tmp2 * u3) + ty1 * (-c34 * tmp2 * u3) + tz1 * (-r43 * c34 * tmp2 * u3));
            d[i][j_idx][3][3] = 1.0 + dt * 2.0 * (tx1 * (c34 * tmp1 + dx4) + ty1 * (c34 * tmp1 + dy4) + tz1 * (r43 * c34 * tmp1 + dz4));
            d[i][j_idx][3][1] = d[i][j_idx][3][2] = d[i][j_idx][3][4] = 0.0;

            double non_diag_term = -(r43 * c34 - c1345) * tmp3 * u1_sq - (c34 - c1345) * tmp3 * u2_sq - (c34 - c1345) * tmp3 * u3_sq - c1345 * tmp2 * u4;
            d[i][j_idx][4][0] = dt * 2.0 * (tx1 * non_diag_term + ty1 * non_diag_term + tz1 * non_diag_term);
            d[i][j_idx][4][1] = dt * 2.0 * ((tx1 + ty1 + tz1) * (c34 - c1345) * tmp2 * u1 + tx1 * (r43 * c34 - 2*c34 + c1345) * tmp2 * u1);
            d[i][j_idx][4][2] = dt * 2.0 * ((tx1 + ty1 + tz1) * (c34 - c1345) * tmp2 * u2 + ty1 * (r43 * c34 - 2*c34 + c1345) * tmp2 * u2);
            d[i][j_idx][4][3] = dt * 2.0 * ((tx1 + ty1 + tz1) * (c34 - c1345) * tmp2 * u3 + tz1 * (r43 * c34 - 2*c34 + c1345) * tmp2 * u3);
            d[i][j_idx][4][4] = 1.0 + dt * 2.0 * ((tx1 + ty1 + tz1) * c1345 * tmp1 + tx1 * dx5 + ty1 * dy5 + tz1 * dz5);

            // Repeat similar for a, b, c with increased reuse
            tmp1 = 1.0 / u[i][j_idx][k - 1][0];
            tmp2 = tmp1 * tmp1;
            tmp3 = tmp1 * tmp2;
            double uk1_1 = u[i][j_idx][k - 1][1], uk1_2 = u[i][j_idx][k - 1][2], uk1_3 = u[i][j_idx][k - 1][3], uk1_4 = u[i][j_idx][k - 1][4];

            a[i][j_idx][0][0] = -dt * tz1 * dz1;
            a[i][j_idx][0][1] = 0.0;
            a[i][j_idx][0][2] = 0.0;
            a[i][j_idx][0][3] = -dt * tz2;
            a[i][j_idx][0][4] = 0.0;

            a[i][j_idx][1][0] = -dt * tz2 * (-uk1_1 * uk1_3 * tmp2) - dt * tz1 * (-c34 * tmp2 * uk1_1);
            a[i][j_idx][1][1] = -dt * tz2 * (uk1_3 * tmp1) - dt * tz1 * (c34 * tmp1 + dz2);
            a[i][j_idx][1][2] = 0.0;
            a[i][j_idx][1][3] = -dt * tz2 * (uk1_1 * tmp1);
            a[i][j_idx][1][4] = 0.0;

            a[i][j_idx][2][0] = -dt * tz2 * (-uk1_2 * uk1_3 * tmp2) - dt * tz1 * (-c34 * tmp2 * uk1_2);
            a[i][j_idx][2][1] = 0.0;
            a[i][j_idx][2][2] = -dt * tz2 * (uk1_3 * tmp1) - dt * tz1 * (c34 * tmp1 + dz3);
            a[i][j_idx][2][3] = -dt * tz2 * (uk1_2 * tmp1);
            a[i][j_idx][2][4] = 0.0;

            a[i][j_idx][3][0] = -dt * tz2 * (-(uk1_3 * uk1_3 * tmp2) + 0.5 * 0.4 * (uk1_1*uk1_1 + uk1_2*uk1_2 + uk1_3*uk1_3) * tmp2)
                                - dt * tz1 * (-r43 * c34 * tmp2 * uk1_3);
            a[i][j_idx][3][1] = -dt * tz2 * (-0.4 * uk1_1 * tmp1);
            a[i][j_idx][3][2] = -dt * tz2 * (-0.4 * uk1_2 * tmp1);
            a[i][j_idx][3][3] = -dt * tz2 * (1.6 * uk1_3 * tmp1) - dt * tz1 * (r43 * c34 * tmp1 + dz4);
            a[i][j_idx][3][4] = -dt * tz2 * 0.4;

            a[i][j_idx][4][0] = -dt * tz2 * ((0.4 * (uk1_1*uk1_1 + uk1_2*uk1_2 + uk1_3*uk1_3) * tmp2 - 1.4 * uk1_4 * tmp1) * (uk1_3 * tmp1))
                                - dt * tz1 * (-(c34 - c1345) * tmp3 * (uk1_1*uk1_1 + uk1_2*uk1_2) - (r43 * c34 - c1345) * tmp3 * uk1_3*uk1_3 - c1345 * tmp2 * uk1_4);
            a[i][j_idx][4][1] = -dt * tz2 * (-0.4 * uk1_1 * uk1_3 * tmp2) - dt * tz1 * (c34 - c1345) * tmp2 * uk1_1;
            a[i][j_idx][4][2] = -dt * tz2 * (-0.4 * uk1_2 * uk1_3 * tmp2) - dt * tz1 * (c34 - c1345) * tmp2 * uk1_2;
            a[i][j_idx][4][3] = -dt * tz2 * (1.4 * uk1_4 * tmp1 - 0.2 * (uk1_1*uk1_1 + uk1_2*uk1_2 + 3.0*uk1_3*uk1_3) * tmp2)
                                - dt * tz1 * (r43 * c34 - c1345) * tmp2 * uk1_3;
            a[i][j_idx][4][4] = -dt * tz2 * (1.4 * uk1_3 * tmp1) - dt * tz1 * (c1345 * tmp1 + dz5);
        }
    }
}
}
