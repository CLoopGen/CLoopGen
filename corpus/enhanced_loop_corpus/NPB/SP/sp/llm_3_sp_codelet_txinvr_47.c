#include <stdio.h>

extern  int grid_points[3];
extern  double c2;
extern  double bt;
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double ainv[65][65][65];
extern  double rho_i[65][65][65];
extern  double speed[65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double t1;
extern double t2;
extern double t3;
extern double ac;
extern double ru1;
extern double uu;
extern double vv;
extern double ww;
extern double r1;
extern double r2;
extern double r3;
extern double r4;
extern double r5;
extern double ac2inv;



void loop(){
int ni = grid_points[0], nj = grid_points[1], nk = grid_points[2];
for (i = 1; i <= ni - 2; i += 2) {
    for (j = 1; j <= nj - 2; j += 2) {
        for (k = 1; k <= nk - 2; k += 2) {
            int indices[8][3] = {
                {i,   j,   k},
                {i+1, j,   k},
                {i,   j+1, k},
                {i+1, j+1, k},
                {i,   j,   k+1},
                {i+1, j,   k+1},
                {i,   j+1, k+1},
                {i+1, j+1, k+1}
            };
            for (int idx = 0; idx < 8; idx++) {
                int ci = indices[idx][0];
                int cj = indices[idx][1];
                int ck = indices[idx][2];
                if (ci <= ni-2 && cj <= nj-2 && ck <= nk-2) {
                    ru1 = rho_i[ci][cj][ck];
                    uu = us[ci][cj][ck];
                    vv = vs[ci][cj][ck];
                    ww = ws[ci][cj][ck];
                    ac = speed[ci][cj][ck];
                    ac2inv = ainv[ci][cj][ck] * ainv[ci][cj][ck];
                    r1 = rhs[0][ci][cj][ck];
                    r2 = rhs[1][ci][cj][ck];
                    r3 = rhs[2][ci][cj][ck];
                    r4 = rhs[3][ci][cj][ck];
                    r5 = rhs[4][ci][cj][ck];
                    t1 = c2 * ac2inv * (qs[ci][cj][ck] * r1 - uu * r2 - vv * r3 - ww * r4 + r5);
                    t2 = bt * ru1 * (uu * r1 - r2);
                    t3 = (bt * ru1 * ac) * t1;
                    rhs[0][ci][cj][ck] = r1 - t1;
                    rhs[1][ci][cj][ck] = -ru1 * (ww * r1 - r4);
                    rhs[2][ci][cj][ck] = ru1 * (vv * r1 - r3);
                    rhs[3][ci][cj][ck] = -t2 + t3;
                    rhs[4][ci][cj][ck] = t2 + t3;
                }
            }
        }
    }
}
}
