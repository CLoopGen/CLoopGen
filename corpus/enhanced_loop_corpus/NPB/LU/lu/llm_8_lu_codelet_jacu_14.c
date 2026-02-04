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
        tmp1 = 1. / u[i][j][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;
        double tx1_dt2 = tx1 * dt * 2.;
        double ty1_dt2 = ty1 * dt * 2.;
        double tz1_dt2 = tz1 * dt * 2.;
        double r43_c34 = r43 * c34;
        double c34_tmp1 = c34 * tmp1;
        double c34_tmp2 = c34 * tmp2;
        double c1345_tmp1 = c1345 * tmp1;
        double dx_sum = tx1 * dx1 + ty1 * dy1 + tz1 * dz1;
        double dy_sum = tx1 * dx2 + ty1 * dy2 + tz1 * dz2;
        double dz_sum = tx1 * dx3 + ty1 * dy3 + tz1 * dz3;
        double dw_sum = tx1 * dx4 + ty1 * dy4 + tz1 * dz4;
        double dv_sum = tx1 * dx5 + ty1 * dy5 + tz1 * dz5;

        d[i][j][0][0] = 1. + tx1_dt2 * dx1 + ty1_dt2 * dy1 + tz1_dt2 * dz1;
        d[i][j][0][1] = d[i][j][0][2] = d[i][j][0][3] = d[i][j][0][4] = 0.;

        double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3], u4 = u[i][j][k][4];
        d[i][j][1][0] = dt * 2. * (tx1 * (-r43_c34 * c34_tmp2 * u1) + ty1 * (-c34_tmp2 * u1) + tz1 * (-c34_tmp2 * u1));
        d[i][j][1][1] = 1. + tx1_dt2 * (r43_c34 * tmp1 + dx2) + ty1_dt2 * (c34_tmp1 + dy2) + tz1_dt2 * (c34_tmp1 + dz2);
        d[i][j][1][2] = d[i][j][1][3] = d[i][j][1][4] = 0.;

        d[i][j][2][0] = dt * 2. * (tx1 * (-c34_tmp2 * u2) + ty1 * (-r43_c34 * c34_tmp2 * u2) + tz1 * (-c34_tmp2 * u2));
        d[i][j][2][2] = 1. + tx1_dt2 * (c34_tmp1 + dx3) + ty1_dt2 * (r43_c34 * tmp1 + dy3) + tz1_dt2 * (c34_tmp1 + dz3);
        d[i][j][2][1] = d[i][j][2][3] = d[i][j][2][4] = 0.;

        d[i][j][3][0] = dt * 2. * (tx1 * (-c34_tmp2 * u3) + ty1 * (-c34_tmp2 * u3) + tz1 * (-r43_c34 * c34_tmp2 * u3));
        d[i][j][3][3] = 1. + tx1_dt2 * (c34_tmp1 + dx4) + ty1_dt2 * (c34_tmp1 + dy4) + tz1_dt2 * (r43_c34 * tmp1 + dz4);
        d[i][j][3][1] = d[i][j][3][2] = d[i][j][3][4] = 0.;

        double sq_u1 = u1 * u1, sq_u2 = u2 * u2, sq_u3 = u3 * u3;
        double term40 = -(r43_c34 - c1345) * tmp3 * sq_u1 - (c34 - c1345) * tmp3 * sq_u2 - (c34 - c1345) * tmp3 * sq_u3 - c1345 * tmp2 * u4;
        d[i][j][4][0] = dt * 2. * (tx1 * term40 + ty1 * (-(c34 - c1345) * tmp3 * sq_u1 - (r43_c34 - c1345) * tmp3 * sq_u2 - (c34 - c1345) * tmp3 * sq_u3 - c1345 * tmp2 * u4) +
                             tz1 * (-(c34 - c1345) * tmp3 * sq_u1 - (c34 - c1345) * tmp3 * sq_u2 - (r43_c34 - c1345) * tmp3 * sq_u3 - c1345 * tmp2 * u4));
        d[i][j][4][1] = dt * 2. * (tx1 * (r43_c34 - c1345) * tmp2 * u1 + ty1 * (c34 - c1345) * tmp2 * u1 + tz1 * (c34 - c1345) * tmp2 * u1);
        d[i][j][4][2] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u2 + ty1 * (r43_c34 - c1345) * tmp2 * u2 + tz1 * (c34 - c1345) * tmp2 * u2);
        d[i][j][4][3] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u3 + ty1 * (c34 - c1345) * tmp2 * u3 + tz1 * (r43_c34 - c1345) * tmp2 * u3);
        d[i][j][4][4] = 1. + tx1_dt2 * (c1345_tmp1 + dx5) + ty1_dt2 * (c1345_tmp1 + dy5) + tz1_dt2 * (c1345_tmp1 + dz5);

        tmp1 = 1. / u[i + 1][j][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;
        double inv_u1 = u[i + 1][j][k][1] * tmp1;
        double inv_u2 = u[i + 1][j][k][2] * tmp1;
        double inv_u3 = u[i + 1][j][k][3] * tmp1;
        double inv_u4 = u[i + 1][j][k][4] * tmp1;
        double sum_sq_inv = inv_u1 * inv_u1 + inv_u2 * inv_u2 + inv_u3 * inv_u3;
        double tx2_half_gamma = 0.2 * tx2;
        double tx2_16 = 1.6 * tx2;

        a[i][j][0][0] = -dt * tx1 * dx1;
        a[i][j][0][1] = dt * tx2;
        a[i][j][0][2] = a[i][j][0][3] = a[i][j][0][4] = 0.;

        a[i][j][1][0] = dt * tx2 * (-sum_sq_inv + 0.4 * 0.5 * sum_sq_inv) - dt * tx1 * (-r43_c34 * tmp2 * u[i + 1][j][k][1]);
        a[i][j][1][1] = tx2_16 * inv_u1 - dt * tx1 * (r43_c34 * tmp1 + dx2);
        a[i][j][1][2] = -tx2_half_gamma * inv_u2;
        a[i][j][1][3] = -tx2_half_gamma * inv_u3;
        a[i][j][1][4] = dt * tx2 * 0.4;

        a[i][j][2][0] = dt * tx2 * (-inv_u1 * inv_u2) - dt * tx1 * (-c34 * tmp2 * u[i + 1][j][k][2]);
        a[i][j][2][1] = dt * tx2 * inv_u2;
        a[i][j][2][2] = dt * tx2 * inv_u1 - dt * tx1 * (c34 * tmp1 + dx3);
        a[i][j][2][3] = a[i][j][2][4] = 0.;

        a[i][j][3][0] = dt * tx2 * (-inv_u1 * inv_u3) - dt * tx1 * (-c34 * tmp2 * u[i + 1][j][k][3]);
        a[i][j][3][1] = dt * tx2 * inv_u3;
        a[i][j][3][2] = 0.;
        a[i][j][3][3] = dt * tx2 * inv_u1 - dt * tx1 * (c34 * tmp1 + dx4);
        a[i][j][3][4] = 0.;

        double tx2_energy_term = tx2 * (0.4 * sum_sq_inv - 1.3999999999999999 * inv_u4);
        a[i][j][4][0] = dt * tx2_energy_term * inv_u1 - dt * tx1 * (-(r43_c34 - c1345) * tmp3 * (u[i + 1][j][k][1]*u[i + 1][j][k][1]) - 
                    (c34 - c1345) * tmp3 * (u[i + 1][j][k][2]*u[i + 1][j][k][2]) - 
                    (c34 - c1345) * tmp3 * (u[i + 1][j][k][3]*u[i + 1][j][k][3]) - c1345 * tmp2 * u[i + 1][j][k][4]);
        a[i][j][4][1] = dt * (tx2 * (1.3999999999999999 * inv_u4 - 0.5 * 0.4 * ((3.*inv_u1*inv_u1 + inv_u2*inv_u2 + inv_u3*inv_u3))) - 
                     tx1 * (r43_c34 - c1345) * tmp2 * u[i + 1][j][k][1]);
        a[i][j][4][2] = dt * (tx2 * (-0.4 * inv_u2 * inv_u1) - tx1 * (c34 - c1345) * tmp2 * u[i + 1][j][k][2]);
        a[i][j][4][3] = dt * (tx2 * (-0.4 * inv_u3 * inv_u1) - tx1 * (c34 - c1345) * tmp2 * u[i + 1][j][k][3]);
        a[i][j][4][4] = dt * (tx2 * 1.3999999999999999 * inv_u1 - tx1 * (c1345 * tmp1 + dx5));

        tmp1 = 1. / u[i][j + 1][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;
        double inv_v1 = u[i][j + 1][k][1] * tmp1;
        double inv_v2 = u[i][j + 1][k][2] * tmp1;
        double inv_v3 = u[i][j + 1][k][3] * tmp1;
        double inv_v4 = u[i][j + 1][k][4] * tmp1;
        double sum_sq_v = inv_v1 * inv_v1 + inv_v2 * inv_v2 + inv_v3 * inv_v3;

        b[i][j][0][0] = -dt * ty1 * dy1;
        b[i][j][0][2] = dt * ty2;
        b[i][j][0][1] = b[i][j][0][3] = b[i][j][0][4] = 0.;

        b[i][j][1][0] = dt * ty2 * (-inv_v1 * inv_v2) - dt * ty1 * (-c34 * tmp2 * u[i][j + 1][k][1]);
        b[i][j][1][1] = dt * ty2 * inv_v2 - dt * ty1 * (c34 * tmp1 + dy2);
        b[i][j][1][2] = dt * ty2 * inv_v1;
        b[i][j][1][3] = b[i][j][1][4] = 0.;

        b[i][j][2][0] = dt * ty2 * (-sum_sq_v + 0.5 * 0.4 * sum_sq_v) - dt * ty1 * (-r43_c34 * tmp2 * u[i][j + 1][k][2]);
        b[i][j][2][1] = -ty2 * 0.4 * inv_v1;
        b[i][j][2][2] = ty2 * 1.6 * inv_v2 - dt * ty1 * (r43_c34 * tmp1 + dy3);
        b[i][j][2][3] = -ty2 * 0.4 * inv_v3;
        b[i][j][2][4] = dt * ty2 * 0.4;

        b[i][j][3][0] = dt * ty2 * (-inv_v2 * inv_v3) - dt * ty1 * (-c34 * tmp2 * u[i][j + 1][k][3]);
        b[i][j][3][2] = dt * ty2 * inv_v3;
        b[i][j][3][3] = dt * ty2 * inv_v2 - dt * ty1 * (c34 * tmp1 + dy4);
        b[i][j][3][1] = b[i][j][3][4] = 0.;

        double ty2_energy_term = ty2 * (0.4 * sum_sq_v - 1.3999999999999999 * inv_v4);
        b[i][j][4][0] = dt * ty2_energy_term * inv_v2 - dt * ty1 * (-(c34 - c1345) * tmp3 * (u[i][j + 1][k][1]*u[i][j + 1][k][1]) - 
                    (r43_c34 - c1345) * tmp3 * (u[i][j + 1][k][2]*u[i][j + 1][k][2]) - 
                    (c34 - c1345) * tmp3 * (u[i][j + 1][k][3]*u[i][j + 1][k][3]) - c1345 * tmp2 * u[i][j + 1][k][4]);
        b[i][j][4][1] = dt * (ty2 * (-0.4 * inv_v1 * inv_v2) - ty1 * (c34 - c1345) * tmp2 * u[i][j + 1][k][1]);
        b[i][j][4][2] = dt * (ty2 * (1.3999999999999999 * inv_v4 - 0.5 * 0.4 * (inv_v1*inv_v1 + 3.*inv_v2*inv_v2 + inv_v3*inv_v3)) - 
                     ty1 * (r43_c34 - c1345) * tmp2 * u[i][j + 1][k][2]);
        b[i][j][4][3] = dt * (ty2 * (-0.4 * inv_v3 * inv_v2) - ty1 * (c34 - c1345) * tmp2 * u[i][j + 1][k][3]);
        b[i][j][4][4] = dt * (ty2 * 1.3999999999999999 * inv_v2 - ty1 * (c1345 * tmp1 + dy5));

        tmp1 = 1. / u[i][j][k + 1][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;
        double inv_w1 = u[i][j][k + 1][1] * tmp1;
        double inv_w2 = u[i][j][k + 1][2] * tmp1;
        double inv_w3 = u[i][j][k + 1][3] * tmp1;
        double inv_w4 = u[i][j][k + 1][4] * tmp1;
        double sum_sq_w = inv_w1 * inv_w1 + inv_w2 * inv_w2 + inv_w3 * inv_w3;

        c[i][j][0][0] = -dt * tz1 * dz1;
        c[i][j][0][3] = dt * tz2;
        c[i][j][0][1] = c[i][j][0][2] = c[i][j][0][4] = 0.;

        c[i][j][1][0] = dt * tz2 * (-inv_w1 * inv_w3) - dt * tz1 * (-c34 * tmp2 * u[i][j][k + 1][1]);
        c[i][j][1][1] = dt * tz2 * inv_w3 - dt * tz1 * (c34 * tmp1 + dz2);
        c[i][j][1][3] = dt * tz2 * inv_w1;
        c[i][j][1][2] = c[i][j][1][4] = 0.;

        c[i][j][2][0] = dt * tz2 * (-inv_w2 * inv_w3) - dt * tz1 * (-c34 * tmp2 * u[i][j][k + 1][2]);
        c[i][j][2][2] = dt * tz2 * inv_w3 - dt * tz1 * (c34 * tmp1 + dz3);
        c[i][j][2][3] = dt * tz2 * inv_w2;
        c[i][j][2][1] = c[i][j][2][4] = 0.;

        c[i][j][3][0] = dt * tz2 * (-sum_sq_w + 0.5 * 0.4 * sum_sq_w) - dt * tz1 * (-r43_c34 * tmp2 * u[i][j][k + 1][3]);
        c[i][j][3][1] = -tz2 * 0.4 * inv_w1;
        c[i][j][3][2] = -tz2 * 0.4 * inv_w2;
        c[i][j][3][3] = tz2 * 1.6 * inv_w3 - dt * tz1 * (r43_c34 * tmp1 + dz4);
        c[i][j][3][4] = dt * tz2 * 0.4;

        double tz2_energy_term = tz2 * (0.4 * sum_sq_w - 1.3999999999999999 * inv_w4);
        c[i][j][4][0] = dt * tz2_energy_term * inv_w3 - dt * tz1 * (-(c34 - c1345) * tmp3 * (u[i][j][k + 1][1]*u[i][j][k + 1][1]) - 
                    (c34 - c1345) * tmp3 * (u[i][j][k + 1][2]*u[i][j][k + 1][2]) - 
                    (r43_c34 - c1345) * tmp3 * (u[i][j][k + 1][3]*u[i][j][k + 1][3]) - c1345 * tmp2 * u[i][j][k + 1][4]);
        c[i][j][4][1] = dt * (tz2 * (-0.4 * inv_w1 * inv_w3) - tz1 * (c34 - c1345) * tmp2 * u[i][j][k + 1][1]);
        c[i][j][4][2] = dt * (tz2 * (-0.4 * inv_w2 * inv_w3) - tz1 * (c34 - c1345) * tmp2 * u[i][j][k + 1][2]);
        c[i][j][4][3] = dt * (tz2 * (1.3999999999999999 * inv_w4 - 0.5 * 0.4 * (inv_w1*inv_w1 + inv_w2*inv_w2 + 3.*inv_w3*inv_w3)) - 
                     tz1 * (r43_c34 - c1345) * tmp2 * u[i][j][k + 1][3]);
        c[i][j][4][4] = dt * (tz2 * 1.3999999999999999 * inv_w3 - tz1 * (c1345 * tmp1 + dz5));
    }
}
}
