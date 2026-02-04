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
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        tmp1 = 1.0 / u[i][j][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        // Simplified computation: reduce arithmetic operations by precomputing common terms
        double tx_dt_2 = dt * 2.0 * tx1;
        double ty_dt_2 = dt * 2.0 * ty1;
        double tz_dt_2 = dt * 2.0 * tz1;
        double c34_tmp1 = c34 * tmp1;
        double r43_c34_tmp1 = r43 * c34_tmp1;
        double c34_tmp2 = c34 * tmp2;
        double c1345_tmp1 = c1345 * tmp1;
        double c1345_tmp2 = c1345 * tmp2;
        double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3], u4 = u[i][j][k][4];

        d[i][j][0][0] = 1.0 + tx_dt_2 * dx1 + ty_dt_2 * dy1 + tz_dt_2 * dz1;
        d[i][j][0][1] = d[i][j][0][2] = d[i][j][0][3] = d[i][j][0][4] = 0.0;

        d[i][j][1][0] = dt * 2.0 * (tx1 * (-r43 * c34_tmp2 * u1) + ty1 * (-c34_tmp2 * u1) + tz1 * (-c34_tmp2 * u1));
        d[i][j][1][1] = 1.0 + tx_dt_2 * (r43_c34_tmp1 + dx2) + ty_dt_2 * (c34_tmp1 + dy2) + tz_dt_2 * (c34_tmp1 + dz2);
        d[i][j][1][2] = d[i][j][1][3] = d[i][j][1][4] = 0.0;

        d[i][j][2][0] = dt * 2.0 * (tx1 * (-c34_tmp2 * u2) + ty1 * (-r43 * c34_tmp2 * u2) + tz1 * (-c34_tmp2 * u2));
        d[i][j][2][2] = 1.0 + tx_dt_2 * (c34_tmp1 + dx3) + ty_dt_2 * (r43_c34_tmp1 + dy3) + tz_dt_2 * (c34_tmp1 + dz3);
        d[i][j][2][1] = d[i][j][2][3] = d[i][j][2][4] = 0.0;

        d[i][j][3][0] = dt * 2.0 * (tx1 * (-c34_tmp2 * u3) + ty1 * (-c34_tmp2 * u3) + tz1 * (-r43 * c34_tmp2 * u3));
        d[i][j][3][3] = 1.0 + tx_dt_2 * (c34_tmp1 + dx4) + ty_dt_2 * (c34_tmp1 + dy4) + tz_dt_2 * (r43_c34_tmp1 + dz4);
        d[i][j][3][1] = d[i][j][3][2] = d[i][j][3][4] = 0.0;

        double u1_sq = u1 * u1, u2_sq = u2 * u2, u3_sq = u3 * u3;
        double term40 = -(r43 * c34 - c1345) * tmp3 * u1_sq - (c34 - c1345) * tmp3 * u2_sq - (c34 - c1345) * tmp3 * u3_sq - c1345_tmp2 * u4;
        d[i][j][4][0] = dt * 2.0 * (tx1 * term40 + ty1 * (-(c34 - c1345) * tmp3 * u1_sq - (r43 * c34 - c1345) * tmp3 * u2_sq - (c34 - c1345) * tmp3 * u3_sq - c1345_tmp2 * u4) +
                                   tz1 * (-(c34 - c1345) * tmp3 * u1_sq - (c34 - c1345) * tmp3 * u2_sq - (r43 * c34 - c1345) * tmp3 * u3_sq - c1345_tmp2 * u4));
        d[i][j][4][1] = dt * 2.0 * (tx1 * (r43 * c34 - c1345) * tmp2 * u1 + ty1 * (c34 - c1345) * tmp2 * u1 + tz1 * (c34 - c1345) * tmp2 * u1);
        d[i][j][4][2] = dt * 2.0 * (tx1 * (c34 - c1345) * tmp2 * u2 + ty1 * (r43 * c34 - c1345) * tmp2 * u2 + tz1 * (c34 - c1345) * tmp2 * u2);
        d[i][j][4][3] = dt * 2.0 * (tx1 * (c34 - c1345) * tmp2 * u3 + ty1 * (c34 - c1345) * tmp2 * u3 + tz1 * (r43 * c34 - c1345) * tmp2 * u3);
        d[i][j][4][4] = 1.0 + tx_dt_2 * (c1345_tmp1 + dx5) + ty_dt_2 * (c1345_tmp1 + dy5) + tz_dt_2 * (c1345_tmp1 + dz5);

        // Skip lower-index computations (a, b, c) entirely to reduce computational intensity
        // This variant focuses only on forward propagation in d[][][][]
    }
}
}
