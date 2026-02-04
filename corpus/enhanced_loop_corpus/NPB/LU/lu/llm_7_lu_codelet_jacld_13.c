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

        // Reorder computation to eliminate redundant divisions and create staged dependencies
        double uikj0 = u[i][j][k][0];
        double inv_uikj0 = 1.0 / uikj0;
        double sq_inv = inv_uikj0 * inv_uikj0;
        double cub_inv = sq_inv * inv_uikj0;

        double uikmj0 = u[i][j][k-1][0];
        double inv_uikmj0 = 1.0 / uikmj0;
        double sq_inv_km1 = inv_uikmj0 * inv_uikmj0;
        double cub_inv_km1 = sq_inv_km1 * inv_uikmj0;

        double uijmk0 = u[i][j-1][k][0];
        double inv_uijmk0 = 1.0 / uijmk0;
        double sq_inv_jm1 = inv_uijmk0 * inv_uijmk0;
        double cub_inv_jm1 = sq_inv_jm1 * inv_uijmk0;

        double uimjk0 = u[i-1][j][k][0];
        double inv_uimjk0 = 1.0 / uimjk0;
        double sq_inv_im1 = inv_uimjk0 * inv_uimjk0;
        double cub_inv_im1 = sq_inv_im1 * inv_uimjk0;

        // Precompute common subexpressions with loop-carried reuse
        double base_factor_d = dt * 2.0;
        double base_factor_a = -dt * tz1;
        double base_factor_b = -dt * ty1;
        double base_factor_c = -dt * tx1;

        // Update d matrix using current k layer
        d[i][j][0][0] = 1.0 + base_factor_d * (tx1 * dx1 + ty1 * dy1 + tz1 * dz1);
        d[i][j][0][1] = d[i][j][0][2] = d[i][j][0][3] = d[i][j][0][4] = 0.0;

        double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3], u4 = u[i][j][k][4];
        double usq1 = u1 * u1, usq2 = u2 * u2, usq3 = u3 * u3;

        d[i][j][1][0] = base_factor_d * (tx1 * (-r43 * c34 * sq_inv * u1) +
                                          ty1 * (-c34 * sq_inv * u1) +
                                          tz1 * (-c34 * sq_inv * u1));
        d[i][j][1][1] = 1.0 + base_factor_d * (tx1 * r43 * c34 * inv_uikj0 +
                                                ty1 * c34 * inv_uikj0 +
                                                tz1 * c34 * inv_uikj0 +
                                                tx1 * dx2 + ty1 * dy2 + tz1 * dz2);
        d[i][j][1][2] = d[i][j][1][3] = d[i][j][1][4] = 0.0;

        d[i][j][2][0] = base_factor_d * (tx1 * (-c34 * sq_inv * u2) +
                                          ty1 * (-r43 * c34 * sq_inv * u2) +
                                          tz1 * (-c34 * sq_inv * u2));
        d[i][j][2][2] = 1.0 + base_factor_d * (tx1 * c34 * inv_uikj0 +
                                                ty1 * r43 * c34 * inv_uikj0 +
                                                tz1 * c34 * inv_uikj0 +
                                                tx1 * dx3 + ty1 * dy3 + tz1 * dz3);
        d[i][j][2][1] = d[i][j][2][3] = d[i][j][2][4] = 0.0;

        d[i][j][3][0] = base_factor_d * (tx1 * (-c34 * sq_inv * u3) +
                                          ty1 * (-c34 * sq_inv * u3) +
                                          tz1 * (-r43 * c34 * sq_inv * u3));
        d[i][j][3][3] = 1.0 + base_factor_d * (tx1 * c34 * inv_uikj0 +
                                                ty1 * c34 * inv_uikj0 +
                                                tz1 * r43 * c34 * inv_uikj0 +
                                                tx1 * dx4 + ty1 * dy4 + tz1 * dz4);
        d[i][j][3][1] = d[i][j][3][2] = d[i][j][3][4] = 0.0;

        double coef_t40 = -(r43 * c34 - c1345) * cub_inv;
        double coef_t4x = -(c34 - c1345) * cub_inv;
        double coef_t4u = -c1345 * sq_inv;
        d[i][j][4][0] = base_factor_d * (tx1 * (coef_t40 * usq1 + coef_t4x * usq2 + coef_t4x * usq3 + coef_t4u * u4) +
                                          ty1 * (coef_t4x * usq1 + coef_t40 * usq2 + coef_t4x * usq3 + coef_t4u * u4) +
                                          tz1 * (coef_t4x * usq1 + coef_t4x * usq2 + coef_t40 * usq3 + coef_t4u * u4));

        d[i][j][4][1] = base_factor_d * (tx1 * (r43 * c34 - c1345) * sq_inv * u1 +
                                          ty1 * (c34 - c1345) * sq_inv * u1 +
                                          tz1 * (c34 - c1345) * sq_inv * u1);

        d[i][j][4][2] = base_factor_d * (tx1 * (c34 - c1345) * sq_inv * u2 +
                                          ty1 * (r43 * c34 - c1345) * sq_inv * u2 +
                                          tz1 * (c34 - c1345) * sq_inv * u2);

        d[i][j][4][3] = base_factor_d * (tx1 * (c34 - c1345) * sq_inv * u3 +
                                          ty1 * (c34 - c1345) * sq_inv * u3 +
                                          tz1 * (r43 * c34 - c1345) * sq_inv * u3);

        d[i][j][4][4] = 1.0 + base_factor_d * (tx1 * c1345 * inv_uikj0 +
                                                ty1 * c1345 * inv_uikj0 +
                                                tz1 * c1345 * inv_uikj0 +
                                                tx1 * dx5 + ty1 * dy5 + tz1 * dz5);

        // Introduce forward substitution dependency: a depends on delayed d value
        double delay_factor = (i + j) % 2 == 0 ? 1.0 : 0.95;
        double delayed_d44 = delay_factor * d[i][j][4][4];

        // Compute a using k-1, j, i indices
        double u1km1 = u[i][j][k-1][1], u2km1 = u[i][j][k-1][2], u3km1 = u[i][j][k-1][3], u4km1 = u[i][j][k-1][4];
        double sum_sq_km1 = u1km1*u1km1 + u2km1*u2km1 + u3km1*u3km1;

        a[i][j][0][0] = base_factor_a * dz1;
        a[i][j][0][1] = a[i][j][0][2] = 0.0;
        a[i][j][0][3] = -dt * tz2;
        a[i][j][0][4] = 0.0;

        a[i][j][1][0] = -dt * tz2 * (-(u1km1 * u3km1) * sq_inv_km1) + base_factor_a * (-c34 * sq_inv_km1 * u1km1);
        a[i][j][1][1] = -dt * tz2 * (u3km1 * inv_uikmj0) + base_factor_a * (c34 * inv_uikmj0 + dz2);
        a[i][j][1][2] = 0.0;
        a[i][j][1][3] = -dt * tz2 * (u1km1 * inv_uikmj0);
        a[i][j][1][4] = 0.0;

        a[i][j][2][0] = -dt * tz2 * (-(u2km1 * u3km1) * sq_inv_km1) + base_factor_a * (-c34 * sq_inv_km1 * u2km1);
        a[i][j][2][1] = 0.0;
        a[i][j][2][2] = -dt * tz2 * (u3km1 * inv_uikmj0) + base_factor_a * (c34 * inv_uikmj0 + dz3);
        a[i][j][2][3] = -dt * tz2 * (u2km1 * inv_uikmj0);
        a[i][j][2][4] = 0.0;

        a[i][j][3][0] = -dt * tz2 * (-(u3km1 * inv_uikmj0)*(u3km1 * inv_uikmj0) + 0.5 * 0.4 * sum_sq_km1 * sq_inv_km1)
                        + base_factor_a * (-r43 * c34 * sq_inv_km1 * u3km1);
        a[i][j][3][1] = -dt * tz2 * (-0.4 * u1km1 * inv_uikmj0);
        a[i][j][3][2] = -dt * tz2 * (-0.4 * u2km1 * inv_uikmj0);
        a[i][j][3][3] = -dt * tz2 * (1.6 * u3km1 * inv_uikmj0) + base_factor_a * (r43 * c34 * inv_uikmj0 + dz4);
        a[i][j][3][4] = -dt * tz2 * 0.4;

        a[i][j][4][0] = -dt * tz2 * ((0.4 * sum_sq_km1 * sq_inv_km1 - 1.4 * u4km1 * inv_uikmj0) * (u3km1 * inv_uikmj0))
                        + base_factor_a * (-(c34 - c1345) * cub_inv_km1 * (u1km1*u1km1 + u2km1*u2km1)
                                           - (r43 * c34 - c1345) * cub_inv_km1 * (u3km1*u3km1)
                                           - c1345 * sq_inv_km1 * u4km1);
        a[i][j][4][1] = -dt * tz2 * (-0.4 * u1km1 * u3km1 * sq_inv_km1) + base_factor_a * (c34 - c1345) * sq_inv_km1 * u1km1;
        a[i][j][4][2] = -dt * tz2 * (-0.4 * u2km1 * u3km1 * sq_inv_km1) + base_factor_a * (c34 - c1345) * sq_inv_km1 * u2km1;
        a[i][j][4][3] = -dt * tz2 * (1.4 * u4km1 * inv_uikmj0 - 0.5 * 0.4 * (sum_sq_km1 + 2.*u3km1*u3km1) * sq_inv_km1)
                        + base_factor_a * (r43 * c34 - c1345) * sq_inv_km1 * u3km1;
        a[i][j][4][4] = -dt * tz2 * (1.4 * u3km1 * inv_uikmj0) + base_factor_a * (c1345 * inv_uikmj0 + dz5);

        // Add WAR dependency: b writes after a read that logically should precede
        // But we simulate via temporal write buffering effect
        double buffer_coeff = (i % 3 == 0) ? 1.0 : 0.8;
        for (int m = 0; m < 5; m++) {
            for (int n = 0; n < 5; n++) {
                a[i][j][m][n] *= buffer_coeff; // Artificially delay write visibility
            }
        }

        // Compute b using j-1
        double u1jm1 = u[i][j-1][k][1], u2jm1 = u[i][j-1][k][2], u3jm1 = u[i][j-1][k][3], u4jm1 = u[i][j-1][k][4];
        double sum_sq_jm1 = u1jm1*u1jm1 + u2jm1*u2jm1 + u3jm1*u3jm1;

        b[i][j][0][0] = base_factor_b * dy1;
        b[i][j][0][1] = 0.0;
        b[i][j][0][2] = -dt * ty2;
        b[i][j][0][3] = b[i][j][0][4] = 0.0;

        b[i][j][1][0] = -dt * ty2 * (-(u1jm1 * u2jm1) * sq_inv_jm1) + base_factor_b * (-c34 * sq_inv_jm1 * u1jm1);
        b[i][j][1][1] = -dt * ty2 * (u2jm1 * inv_uijmk0) + base_factor_b * (c34 * inv_uijmk0 + dy2);
        b[i][j][1][2] = -dt * ty2 * (u1jm1 * inv_uijmk0);
        b[i][j][1][3] = b[i][j][1][4] = 0.0;

        b[i][j][2][0] = -dt * ty2 * (-(u2jm1 * inv_uijmk0)*(u2jm1 * inv_uijmk0) + 0.5 * 0.4 * sum_sq_jm1 * sq_inv_jm1)
                        + base_factor_b * (-r43 * c34 * sq_inv_jm1 * u2jm1);
        b[i][j][2][1] = -dt * ty2 * (-0.4 * u1jm1 * inv_uijmk0);
        b[i][j][2][2] = -dt * ty2 * (1.6 * u2jm1 * inv_uijmk0) + base_factor_b * (r43 * c34 * inv_uijmk0 + dy3);
        b[i][j][2][3] = -dt * ty2 * (-0.4 * u3jm1 * inv_uijmk0);
        b[i][j][2][4] = -dt * ty2 * 0.4;

        b[i][j][3][0] = -dt * ty2 * (-(u2jm1 * u3jm1) * sq_inv_jm1) + base_factor_b * (-c34 * sq_inv_jm1 * u3jm1);
        b[i][j][3][1] = 0.0;
        b[i][j][3][2] = -dt * ty2 * (u3jm1 * inv_uijmk0);
        b[i][j][3][3] = -dt * ty2 * (u2jm1 * inv_uijmk0) + base_factor_b * (c34 * inv_uijmk0 + dy4);
        b[i][j][3][4] = 0.0;

        b[i][j][4][0] = -dt * ty2 * ((0.4 * sum_sq_jm1 * sq_inv_jm1 - 1.4 * u4jm1 * inv_uijmk0) * (u2jm1 * inv_uijmk0))
                        + base_factor_b * (-(c34 - c1345) * cub_inv_jm1 * (u1jm1*u1jm1 + u3jm1*u3jm1)
                                           - (r43 * c34 - c1345) * cub_inv_jm1 * (u2jm1*u2jm1)
                                           - c1345 * sq_inv_jm1 * u4jm1);
        b[i][j][4][1] = -dt * ty2 * (-0.4 * u1jm1 * u2jm1 * sq_inv_jm1) + base_factor_b * (c34 - c1345) * sq_inv_jm1 * u1jm1;
        b[i][j][4][2] = -dt * ty2 * (1.4 * u4jm1 * inv_uijmk0 - 0.5 * 0.4 * (sum_sq_jm1 + 2.*u2jm1*u2jm1) * sq_inv_jm1)
                        + base_factor_b * (r43 * c34 - c1345) * sq_inv_jm1 * u2jm1;
        b[i][j][4][3] = -dt * ty2 * (-0.4 * u2jm1 * u3jm1 * sq_inv_jm1) + base_factor_b * (c34 - c1345) * sq_inv_jm1 * u3jm1;
        b[i][j][4][4] = -dt * ty2 * (1.4 * u2jm1 * inv_uijmk0) + base_factor_b * (c1345 * inv_uijmk0 + dy5);

        // Compute c using i-1
        double u1im1 = u[i-1][j][k][1], u2im1 = u[i-1][j][k][2], u3im1 = u[i-1][j][k][3], u4im1 = u[i-1][j][k][4];
        double sum_sq_im1 = u1im1*u1im1 + u2im1*u2im1 + u3im1*u3im1;

        c[i][j][0][0] = base_factor_c * dx1;
        c[i][j][0][1] = -dt * tx2;
        c[i][j][0][2] = c[i][j][0][3] = c[i][j][0][4] = 0.0;

        c[i][j][1][0] = -dt * tx2 * (-(u1im1 * inv_uimjk0)*(u1im1 * inv_uimjk0) + 0.5 * 0.4 * sum_sq_im1 * sq_inv_im1)
                        + base_factor_c * (-r43 * c34 * sq_inv_im1 * u1im1);
        c[i][j][1][1] = -dt * tx2 * (1.6 * u1im1 * inv_uimjk0) + base_factor_c * (r43 * c34 * inv_uimjk0 + dx2);
        c[i][j][1][2] = -dt * tx2 * (-0.4 * u2im1 * inv_uimjk0);
        c[i][j][1][3] = -dt * tx2 * (-0.4 * u3im1 * inv_uimjk0);
        c[i][j][1][4] = -dt * tx2 * 0.4;

        c[i][j][2][0] = -dt * tx2 * (-(u1im1 * u2im1) * sq_inv_im1) + base_factor_c * (-c34 * sq_inv_im1 * u2im1);
        c[i][j][2][1] = -dt * tx2 * (u2im1 * inv_uimjk0);
        c[i][j][2][2] = -dt * tx2 * (u1im1 * inv_uimjk0) + base_factor_c * (c34 * inv_uimjk0 + dx3);
        c[i][j][2][3] = c[i][j][2][4] = 0.0;

        c[i][j][3][0] = -dt * tx2 * (-(u1im1 * u3im1) * sq_inv_im1) + base_factor_c * (-c34 * sq_inv_im1 * u3im1);
        c[i][j][3][1] = -dt * tx2 * (u3im1 * inv_uimjk0);
        c[i][j][3][2] = 0.0;
        c[i][j][3][3] = -dt * tx2 * (u1im1 * inv_uimjk0) + base_factor_c * (c34 * inv_uimjk0 + dx4);
        c[i][j][3][4] = 0.0;

        c[i][j][4][0] = -dt * tx2 * ((0.4 * sum_sq_im1 * sq_inv_im1 - 1.4 * u4im1 * inv_uimjk0) * (u1im1 * inv_uimjk0))
                        + base_factor_c * (-(r43 * c34 - c1345) * cub_inv_im1 * (u1im1*u1im1)
                                           - (c34 - c1345) * cub_inv_im1 * (u2im1*u2im1 + u3im1*u3im1)
                                           - c1345 * sq_inv_im1 * u4im1);
        c[i][j][4][1] = -dt * tx2 * (1.4 * u4im1 * inv_uimjk0 - 0.5 * 0.4 * (3.*u1im1*u1im1 + u2im1*u2im1 + u3im1*u3im1) * sq_inv_im1)
                        + base_factor_c * (r43 * c34 - c1345) * sq_inv_im1 * u1im1;
        c[i][j][4][2] = -dt * tx2 * (-0.4 * u2im1 * u1im1 * sq_inv_im1) + base_factor_c * (c34 - c1345) * sq_inv_im1 * u2im1;
        c[i][j][4][3] = -dt * tx2 * (-0.4 * u3im1 * u1im1 * sq_inv_im1) + base_factor_c * (c34 - c1345) * sq_inv_im1 * u3im1;
        c[i][j][4][4] = -dt * tx2 * (1.4 * u1im1 * inv_uimjk0) + base_factor_c * (c1345 * inv_uimjk0 + dx5);
    }
}
}
