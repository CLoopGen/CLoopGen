#include <stdio.h>

extern  int nx;
extern  int nz;
extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double tx1;
extern  double tx2;
extern  double tx3;
extern  double dx1;
extern  double dx2;
extern  double dx3;
extern  double dx4;
extern  double dx5;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int L2;
extern int ist1;
extern int iend1;
extern double dsspm;
extern double tmp;
extern double u21i;
extern double u31i;
extern double u41i;
extern double u51i;
extern double u21im1;
extern double u31im1;
extern double u41im1;
extern double u51im1;



void loop(){
    for (j = jst; j <= jend; j++) {
        for (k = 1; k <= nz - 2; k++) {
            // Change memory access pattern: reorder loops to k -> i -> m -> j for better cache reuse in j
            // But since j is outermost, simulate strided access by unrolling m and fusing operations
            for (i = ist; i <= iend; i++) {
                for (m = 0; m < 5; m++) {
                    // Use direct array base offset with precomputed strides to simulate indirect access
                    int idx = i;
                    frct[idx][j][k][m] = frct[idx][j][k][m] - tx2 * (flux[idx + 1][j][k][m] - flux[idx - 1][j][k][m]);
                }
            }
            // Compute flux using indirect indexing via array of pointers for rsd slices
            double *rsd_jk[64]; // simulate slice pointers for rsd[*][j][k]
            double *flux_jk[64];
            for (int ip = 0; ip < nx; ip++) {
                rsd_jk[ip] = &(rsd[ip][j][k][0]);
                flux_jk[ip] = &(flux[ip][j][k][0]);
            }
            for (i = ist; i <= L2; i++) {
                tmp = 1. / rsd_jk[i][0];
                u21i = tmp * rsd_jk[i][1];
                u31i = tmp * rsd_jk[i][2];
                u41i = tmp * rsd_jk[i][3];
                u51i = tmp * rsd_jk[i][4];
                tmp = 1. / rsd_jk[i-1][0];
                u21im1 = tmp * rsd_jk[i-1][1];
                u31im1 = tmp * rsd_jk[i-1][2];
                u41im1 = tmp * rsd_jk[i-1][3];
                u51im1 = tmp * rsd_jk[i-1][4];
                flux_jk[i][1] = (4. / 3.) * tx3 * (u21i - u21im1);
                flux_jk[i][2] = tx3 * (u31i - u31im1);
                flux_jk[i][3] = tx3 * (u41i - u41im1);
                flux_jk[i][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * tx3 * 
                               ((u21i * u21i + u31i * u31i + u41i * u41i) - (u21im1 * u21im1 + u31im1 * u31im1 + u41im1 * u41im1)) +
                               (1. / 6.) * tx3 * (u21i * u21i - u21im1 * u21im1) +
                               1.3999999999999999 * 1.3999999999999999 * tx3 * (u51i - u51im1);
            }
            // Update frct using consecutive access in m and vectorizable form
            for (i = ist; i <= iend; i++) {
                double *frct_ikm = &(frct[i][j][k][0]);
                double *rsd_ikm = &(rsd[i][j][k][0]);
                double *rsd_im1km = &(rsd[i-1][j][k][0]);
                double *rsd_ip1km = &(rsd[i+1][j][k][0]);
                double *flux_ikm = &(flux[i][j][k][0]);
                double *flux_ip1km = &(flux[i+1][j][k][0]);

                frct_ikm[0] += dx1 * tx1 * (rsd_im1km[0] - 2. * rsd_ikm[0] + rsd_ip1km[0]);
                frct_ikm[1] += tx3 * 0.10000000000000001 * 1. * (flux_ip1km[1] - flux_ikm[1]) + dx2 * tx1 * (rsd_im1km[1] - 2. * rsd_ikm[1] + rsd_ip1km[1]);
                frct_ikm[2] += tx3 * 0.10000000000000001 * 1. * (flux_ip1km[2] - flux_ikm[2]) + dx3 * tx1 * (rsd_im1km[2] - 2. * rsd_ikm[2] + rsd_ip1km[2]);
                frct_ikm[3] += tx3 * 0.10000000000000001 * 1. * (flux_ip1km[3] - flux_ikm[3]) + dx4 * tx1 * (rsd_im1km[3] - 2. * rsd_ikm[3] + rsd_ip1km[3]);
                frct_ikm[4] += tx3 * 0.10000000000000001 * 1. * (flux_ip1km[4] - flux_ikm[4]) + dx5 * tx1 * (rsd_im1km[4] - 2. * rsd_ikm[4] + rsd_ip1km[4]);
            }
            // Boundary damping with gather-scatter style access: collect rsd values into local arrays
            for (m = 0; m < 5; m++) {
                double r[5];
                r[0] = rsd[1][j][k][m]; r[1] = rsd[2][j][k][m]; r[2] = rsd[3][j][k][m]; r[3] = rsd[4][j][k][m];
                frct[1][j][k][m] -= dsspm * (+5. * r[0] - 4. * r[1] + r[2]);
                frct[2][j][k][m] -= dsspm * (-4. * r[0] + 6. * r[1] - 4. * r[2] + r[3]);
            }
            ist1 = 3;
            iend1 = nx - 4;
            // Inner stencil with indirect loop control via pointer walk
            double (*fptr)[5] = &(frct[ist1][j][k]);
            double (*rptr)[5] = &(rsd[ist1][j][k]);
            for (int idx = 0; idx <= iend1 - ist1; idx++) {
                double *f = fptr[idx];
                double *r_m2 = (idx >= 2) ? &(rptr[idx-2][0]) : &(rsd[ist1 + idx - 2][j][k][0]);
                double *r_m1 = (idx >= 1) ? &(rptr[idx-1][0]) : &(rsd[ist1 + idx - 1][j][k][0]);
                double *r_0  = &(rptr[idx][0]);
                double *r_p1 = (idx <= (iend1 - ist1) - 1) ? &(rptr[idx+1][0]) : &(rsd[ist1 + idx + 1][j][k][0]);
                double *r_p2 = (idx <= (iend1 - ist1) - 2) ? &(rptr[idx+2][0]) : &(rsd[ist1 + idx + 2][j][k][0]);
                for (m = 0; m < 5; m++) {
                    f[m] -= dsspm * (r_m2[m] - 4. * r_m1[m] + 6. * r_0[m] - 4. * r_p1[m] + r_p2[m]);
                }
            }
            // Final boundary points with explicit indexing
            for (m = 0; m < 5; m++) {
                double *r = &(rsd[nx-5][j][k][0]);
                frct[nx - 3][j][k][m] -= dsspm * (r[m] - 4. * r[m+1] + 6. * r[m+2] - 4. * r[m+3]);
                frct[nx - 2][j][k][m] -= dsspm * (r[m+1] - 4. * r[m+2] + 5. * r[m+3]);
            }
        }
    }
}
