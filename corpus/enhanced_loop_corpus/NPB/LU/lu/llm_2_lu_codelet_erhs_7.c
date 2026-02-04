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
            // First, update frct using flux differences with modified memory access: reverse i-loop to create backward strided access
            for (i = iend; i >= ist; i--) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] = frct[i][j][k][m] - tx2 * (flux[i + 1][j][k][m] - flux[i - 1][j][k][m]);
                }
            }
            // Compute flux using forward access but with indirect indexing via pointer arithmetic simulation
            double (*rsd_ptr)[65][65][5] = &rsd[0];
            for (i = ist; i <= L2; i++) {
                double *rsd_i   = (double *)(&(rsd_ptr[i][j][k][0]));
                double *rsd_im1 = (double *)(&(rsd_ptr[i-1][j][k][0]));
                tmp = 1. / rsd_i[0];
                u21i = tmp * rsd_i[1];
                u31i = tmp * rsd_i[2];
                u41i = tmp * rsd_i[3];
                u51i = tmp * rsd_i[4];
                tmp = 1. / rsd_im1[0];
                u21im1 = tmp * rsd_im1[1];
                u31im1 = tmp * rsd_im1[2];
                u41im1 = tmp * rsd_im1[3];
                u51im1 = tmp * rsd_im1[4];
                flux[i][j][k][1] = (4. / 3.) * tx3 * (u21i - u21im1);
                flux[i][j][k][2] = tx3 * (u31i - u31im1);
                flux[i][j][k][3] = tx3 * (u41i - u41im1);
                flux[i][j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * tx3 * 
                                   ((u21i * u21i + u31i * u31i + u41i * u41i) - (u21im1 * u21im1 + u31im1 * u31im1 + u41im1 * u41im1)) +
                                   (1. / 6.) * tx3 * (u21i * u21i - u21im1 * u21im1) +
                                   1.3999999999999999 * 1.3999999999999999 * tx3 * (u51i - u51im1);
            }
            // Update frct with central differences and diffusion terms using non-unit stride: step by 2
            for (i = ist; i <= iend; i += 2) {
                frct[i][j][k][0] = frct[i][j][k][0] + dx1 * tx1 * (rsd[i - 1][j][k][0] - 2. * rsd[i][j][k][0] + rsd[i + 1][j][k][0]);
                frct[i][j][k][1] = frct[i][j][k][1] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][1] - flux[i][j][k][1]) + dx2 * tx1 * (rsd[i - 1][j][k][1] - 2. * rsd[i][j][k][1] + rsd[i + 1][j][k][1]);
                frct[i][j][k][2] = frct[i][j][k][2] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][2] - flux[i][j][k][2]) + dx3 * tx1 * (rsd[i - 1][j][k][2] - 2. * rsd[i][j][k][2] + rsd[i + 1][j][k][2]);
                frct[i][j][k][3] = frct[i][j][k][3] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][3] - flux[i][j][k][3]) + dx4 * tx1 * (rsd[i - 1][j][k][3] - 2. * rsd[i][j][k][3] + rsd[i + 1][j][k][3]);
                frct[i][j][k][4] = frct[i][j][k][4] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][4] - flux[i][j][k][4]) + dx5 * tx1 * (rsd[i - 1][j][k][4] - 2. * rsd[i][j][k][4] + rsd[i + 1][j][k][4]);
            }
            // Handle remaining index if iend - ist + 1 is odd
            if ((iend - ist + 1) % 2 == 1) {
                i = iend;
                frct[i][j][k][0] = frct[i][j][k][0] + dx1 * tx1 * (rsd[i - 1][j][k][0] - 2. * rsd[i][j][k][0] + rsd[i + 1][j][k][0]);
                frct[i][j][k][1] = frct[i][j][k][1] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][1] - flux[i][j][k][1]) + dx2 * tx1 * (rsd[i - 1][j][k][1] - 2. * rsd[i][j][k][1] + rsd[i + 1][j][k][1]);
                frct[i][j][k][2] = frct[i][j][k][2] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][2] - flux[i][j][k][2]) + dx3 * tx1 * (rsd[i - 1][j][k][2] - 2. * rsd[i][j][k][2] + rsd[i + 1][j][k][2]);
                frct[i][j][k][3] = frct[i][j][k][3] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][3] - flux[i][j][k][3]) + dx4 * tx1 * (rsd[i - 1][j][k][3] - 2. * rsd[i][j][k][3] + rsd[i + 1][j][k][3]);
                frct[i][j][k][4] = frct[i][j][k][4] + tx3 * 0.10000000000000001 * 1. * (flux[i + 1][j][k][4] - flux[i][j][k][4]) + dx5 * tx1 * (rsd[i - 1][j][k][4] - 2. * rsd[i][j][k][4] + rsd[i + 1][j][k][4]);
            }
            // Apply damping at boundaries with consecutive access in m, but interlaced i updates
            for (m = 0; m < 5; m++) {
                frct[1][j][k][m] = frct[1][j][k][m] - dsspm * (+5. * rsd[1][j][k][m] - 4. * rsd[2][j][k][m] + rsd[3][j][k][m]);
                frct[2][j][k][m] = frct[2][j][k][m] - dsspm * (-4. * rsd[1][j][k][m] + 6. * rsd[2][j][k][m] - 4. * rsd[3][j][k][m] + rsd[4][j][k][m]);
            }
            ist1 = 3;
            iend1 = nx - 4;
            // Use blocked access pattern: process two points at a time for spatial locality
            for (i = ist1; i <= iend1 - 1; i += 2) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] = frct[i][j][k][m] - dsspm * (rsd[i - 2][j][k][m] - 4. * rsd[i - 1][j][k][m] + 6. * rsd[i][j][k][m] - 4. * rsd[i + 1][j][k][m] + rsd[i + 2][j][k][m]);
                    frct[i+1][j][k][m] = frct[i+1][j][k][m] - dsspm * (rsd[i - 1][j][k][m] - 4. * rsd[i][j][k][m] + 6. * rsd[i+1][j][k][m] - 4. * rsd[i + 2][j][k][m] + rsd[i + 3][j][k][m]);
                }
            }
            // Clean up last point if range is odd
            if ((iend1 - ist1 + 1) % 2 == 1) {
                i = iend1;
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] = frct[i][j][k][m] - dsspm * (rsd[i - 2][j][k][m] - 4. * rsd[i - 1][j][k][m] + 6. * rsd[i][j][k][m] - 4. * rsd[i + 1][j][k][m] + rsd[i + 2][j][k][m]);
                }
            }
            for (m = 0; m < 5; m++) {
                frct[nx - 3][j][k][m] = frct[nx - 3][j][k][m] - dsspm * (rsd[nx - 5][j][k][m] - 4. * rsd[nx - 4][j][k][m] + 6. * rsd[nx - 3][j][k][m] - 4. * rsd[nx - 2][j][k][m]);
                frct[nx - 2][j][k][m] = frct[nx - 2][j][k][m] - dsspm * (rsd[nx - 4][j][k][m] - 4. * rsd[nx - 3][j][k][m] + 5. * rsd[nx - 2][j][k][m]);
            }
        }
    }
}
