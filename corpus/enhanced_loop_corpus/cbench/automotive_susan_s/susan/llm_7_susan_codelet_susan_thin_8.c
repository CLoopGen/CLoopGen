#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int *r;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int l[9];
extern int centre;
extern int b01;
extern int b12;
extern int b21;
extern int b10;
extern int p1;
extern int p2;
extern int p3;
extern int p4;
extern int b00;
extern int b02;
extern int b20;
extern int b22;
extern int m;
extern int n;
extern int a;
extern int b;
extern int x;
extern int y;
extern int i;
extern int j;
extern uchar *mp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < y_size - 4; i++) {
    for (j = 4; j < x_size - 4; j++) {
        if (mid[i * x_size + j] >= 8) continue;

        centre = r[i * x_size + j];
        mp = mid + (i - 1) * x_size + j - 1;

        // Introduce temporary variables to break memory-based WAW and WAR dependencies
        int temp_n = 0;
        temp_n += (*(mp) < 8);
        temp_n += (*(mp + 1) < 8);
        temp_n += (*(mp + 2) < 8);
        temp_n += (*(mp + x_size) < 8);
        temp_n += (*(mp + x_size + 2) < 8);
        temp_n += (*(mp + x_size + x_size) < 8);
        temp_n += (*(mp + x_size + x_size + 1) < 8);
        temp_n += (*(mp + x_size + x_size + 2) < 8);

        n = temp_n;

        if (n == 0) {
            mid[i * x_size + j] = 100;
            continue;
        }

        if ((n == 1) && (mid[i * x_size + j] < 6)) {
            // Precompute all neighbor values first to eliminate potential RAW hazards during conditional updates
            int nb[9];
            nb[0] = r[(i - 1) * x_size + j - 1];
            nb[1] = r[(i - 1) * x_size + j];
            nb[2] = r[(i - 1) * x_size + j + 1];
            nb[3] = r[i * x_size + j - 1];
            nb[4] = 0;
            nb[5] = r[i * x_size + j + 1];
            nb[6] = r[(i + 1) * x_size + j - 1];
            nb[7] = r[(i + 1) * x_size + j];
            nb[8] = r[(i + 1) * x_size + j + 1];

            uchar cond0 = mid[(i - 1) * x_size + j - 1] < 8;
            uchar cond1 = mid[(i - 1) * x_size + j] < 8;
            uchar cond2 = mid[(i - 1) * x_size + j + 1] < 8;
            uchar cond3 = mid[i * x_size + j - 1] < 8;
            uchar cond4 = mid[i * x_size + j + 1] < 8;
            uchar cond6 = mid[(i + 1) * x_size + j - 1] < 8;
            uchar cond7 = mid[(i + 1) * x_size + j] < 8;
            uchar cond8 = mid[(i + 1) * x_size + j + 1] < 8;

            // Apply transformations based on conditions without immediate write-back
            if (cond0) {
                nb[0] = nb[1] = nb[3] = 0;
                nb[2] *= 2; nb[6] *= 2; nb[5] *= 3; nb[7] *= 3; nb[8] *= 4;
            } else if (cond1) {
                nb[1] = nb[0] = nb[2] = 0;
                nb[3] *= 2; nb[5] *= 2; nb[6] *= 3; nb[8] *= 3; nb[7] *= 4;
            } else if (cond2) {
                nb[2] = nb[1] = nb[5] = 0;
                nb[0] *= 2; nb[8] *= 2; nb[3] *= 3; nb[7] *= 3; nb[6] *= 4;
            } else if (cond3) {
                nb[3] = nb[0] = nb[6] = 0;
                nb[1] *= 2; nb[7] *= 2; nb[2] *= 3; nb[8] *= 3; nb[5] *= 4;
            } else if (cond4) {
                nb[5] = nb[2] = nb[8] = 0;
                nb[1] *= 2; nb[7] *= 2; nb[0] *= 3; nb[6] *= 3; nb[3] *= 4;
            } else if (cond6) {
                nb[6] = nb[3] = nb[7] = 0;
                nb[0] *= 2; nb[8] *= 2; nb[1] *= 3; nb[5] *= 3; nb[2] *= 4;
            } else if (cond7) {
                nb[7] = nb[6] = nb[8] = 0;
                nb[3] *= 2; nb[5] *= 2; nb[0] *= 3; nb[2] *= 3; nb[1] *= 4;
            } else if (cond8) {
                nb[8] = nb[5] = nb[7] = 0;
                nb[6] *= 2; nb[2] *= 2; nb[1] *= 3; nb[3] *= 3; nb[0] *= 4;
            }

            m = 0; a = 0; b = 0;
            for (y = 0; y < 3; y++) {
                for (x = 0; x < 3; x++) {
                    int idx = y * 3 + x;
                    if (nb[idx] > m) {
                        m = nb[idx];
                        a = y;
                        b = x;
                    }
                }
            }

            if (m > 0) {
                int target_i = i + a - 1;
                int target_j = j + b - 1;
                if (mid[i * x_size + j] < 4)
                    mid[target_i * x_size + target_j] = 4;
                else
                    mid[target_i * x_size + target_j] = mid[i * x_size + j] + 1;

                if ((a * 2 + b) < 3) {
                    i += a - 1;
                    j += b - 2;
                    if (i < 4) i = 4;
                    if (j < 4) j = 4;
                }
            }
        }

        if (n == 2) {
            b00 = mid[(i - 1) * x_size + j - 1] < 8;
            b02 = mid[(i - 1) * x_size + j + 1] < 8;
            b20 = mid[(i + 1) * x_size + j - 1] < 8;
            b22 = mid[(i + 1) * x_size + j + 1] < 8;

            if (((b00 + b02 + b20 + b22) == 2) && ((b00 | b22) & (b02 | b20))) {
                if (b00) {
                    x = b02 ? 0 : -1;
                    y = b02 ? -1 : 0;
                } else {
                    x = b22 ? 1 : 0;
                    y = b22 ? 0 : 1;
                }

                float ratio = (float)r[(i + y) * x_size + j + x] / (float)centre;
                if (ratio > 0.69999999999999996) {
                    int ext_cond = (x == 0) ?
                        (mid[(i + 2*y)*x_size + j] > 7 && mid[(i + 2*y)*x_size + j - 1] > 7 && mid[(i + 2*y)*x_size + j + 1] > 7) :
                        (mid[i*x_size + j + 2*x] > 7 && mid[(i+1)*x_size + j + 2*x] > 7 && mid[(i-1)*x_size + j + 2*x] > 7);
                    if (ext_cond) {
                        mid[i * x_size + j] = 100;
                        mid[(i + y) * x_size + j + x] = 3;
                    }
                }
            } else {
                b01 = mid[(i - 1) * x_size + j] < 8;
                b12 = mid[i * x_size + j + 1] < 8;
                b21 = mid[(i + 1) * x_size + j] < 8;
                b10 = mid[i * x_size + j - 1] < 8;

                if (((b01 + b12 + b21 + b10) == 2) && ((b10 | b12) & (b01 | b21))) {
                    int corner_cond = (b01 & ((mid[(i - 2)*x_size + j - 1] < 8) | (mid[(i - 2)*x_size + j + 1] < 8))) |
                                      (b10 & ((mid[(i - 1)*x_size + j - 2] < 8) | (mid[(i + 1)*x_size + j - 2] < 8))) |
                                      (b12 & ((mid[(i - 1)*x_size + j + 2] < 8) | (mid[(i + 1)*x_size + j + 2] < 8))) |
                                      (b21 & ((mid[(i + 2)*x_size + j - 1] < 8) | (mid[(i + 2)*x_size + j + 1] < 8)));

                    if (corner_cond) {
                        mid[i * x_size + j] = 100;
                        i--;
                        j -= 2;
                        if (i < 4) i = 4;
                        if (j < 4) j = 4;
                    }
                }
            }
        }

        if (n > 2) {
            b01 = mid[(i - 1) * x_size + j] < 8;
            b12 = mid[i * x_size + j + 1] < 8;
            b21 = mid[(i + 1) * x_size + j] < 8;
            b10 = mid[i * x_size + j - 1] < 8;

            if ((b01 + b12 + b21 + b10) > 1) {
                b00 = mid[(i - 1) * x_size + j - 1] < 8;
                b02 = mid[(i - 1) * x_size + j + 1] < 8;
                b20 = mid[(i + 1) * x_size + j - 1] < 8;
                b22 = mid[(i + 1) * x_size + j + 1] < 8;

                p1 = b00 | b01;
                p2 = b02 | b12;
                p3 = b22 | b21;
                p4 = b20 | b10;

                int overlap = (b01 & p2) + (b12 & p3) + (b21 & p4) + (b10 & p1);
                if ((p1 + p2 + p3 + p4 - overlap) < 2) {
                    mid[i * x_size + j] = 100;
                    i--;
                    j -= 2;
                    if (i < 4) i = 4;
                    if (j < 4) j = 4;
                }
            }
        }
    }
}
}
