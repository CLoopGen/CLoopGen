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



void loop() {
    // Variant using consecutive spatial blocking and strided access with local caching
    const int block_size = 4;
    for (int ii = 4; ii < y_size - 4; ii += block_size) {
        for (int jj = 4; jj < x_size - 4; jj += block_size) {
            int ibound = (ii + block_size < y_size - 4) ? ii + block_size : y_size - 4;
            int jbound = (jj + block_size < x_size - 4) ? jj + block_size : x_size - 4;

            for (i = ii; i < ibound; i++) {
                for (j = jj; j < jbound; j++) {
                    if (mid[i * x_size + j] < 8) {
                        centre = r[i * x_size + j];
                        mp = mid + (i - 1) * x_size + j - 1;

                        // Strided access replaced by direct offset list (simulating vectorizable pattern)
                        n = (mp[0] < 8) + (mp[1] < 8) + (mp[2] < 8) +
                            (mp[x_size] < 8) + (mp[x_size + 2] < 8) +
                            (mp[2*x_size] < 8) + (mp[2*x_size + 1] < 8) + (mp[2*x_size + 2] < 8);

                        if (n == 0) {
                            mid[i * x_size + j] = 100;
                        } else if ((n == 1) && (mid[i * x_size + j] < 6)) {
                            // Load 3x3 neighborhood into l[] using flattened index arithmetic
                            int nidx = (i - 1) * x_size + j - 1;
                            int ridx = 0;
                            for (int dy = 0; dy < 3; dy++) {
                                for (int dx = 0; dx < 3; dx++) {
                                    if (dy == 1 && dx == 1) {
                                        l[ridx++] = 0;
                                    } else {
                                        l[ridx++] = r[nidx + dy * x_size + dx];
                                    }
                                }
                            }

                            // Conditional updates based on neighbor flags using direct comparisons
                            if (mid[nidx] < 8) {
                                l[0] = l[1] = l[3] = 0;
                                l[2] *= 2; l[6] *= 2; l[5] *= 3; l[7] *= 3; l[8] *= 4;
                            } else if (mid[nidx + 1] < 8) {
                                l[1] = l[0] = l[2] = 0;
                                l[3] *= 2; l[5] *= 2; l[6] *= 3; l[8] *= 3; l[7] *= 4;
                            } else if (mid[nidx + 2] < 8) {
                                l[2] = l[1] = l[5] = 0;
                                l[0] *= 2; l[8] *= 2; l[3] *= 3; l[7] *= 3; l[6] *= 4;
                            } else if (mid[nidx + x_size] < 8) {
                                l[3] = l[0] = l[6] = 0;
                                l[1] *= 2; l[7] *= 2; l[2] *= 3; l[8] *= 3; l[5] *= 4;
                            } else if (mid[nidx + x_size + 2] < 8) {
                                l[5] = l[2] = l[8] = 0;
                                l[1] *= 2; l[7] *= 2; l[0] *= 3; l[6] *= 3; l[3] *= 4;
                            } else if (mid[nidx + 2*x_size] < 8) {
                                l[6] = l[3] = l[7] = 0;
                                l[0] *= 2; l[8] *= 2; l[1] *= 3; l[5] *= 3; l[2] *= 4;
                            } else if (mid[nidx + 2*x_size + 1] < 8) {
                                l[7] = l[6] = l[8] = 0;
                                l[3] *= 2; l[5] *= 2; l[0] *= 3; l[2] *= 3; l[1] *= 4;
                            } else if (mid[nidx + 2*x_size + 2] < 8) {
                                l[8] = l[5] = l[7] = 0;
                                l[6] *= 2; l[2] *= 2; l[1] *= 3; l[3] *= 3; l[0] *= 4;
                            }

                            m = 0; a = 0; b = 0;
                            for (int idx = 0; idx < 9; idx++) {
                                if (l[idx] > m) {
                                    m = l[idx];
                                    a = idx / 3;
                                    b = idx % 3;
                                }
                            }
                            if (m > 0) {
                                int ni = i + a - 1, nj = j + b - 1;
                                mid[ni * x_size + nj] = (mid[i * x_size + j] < 4) ? 4 : mid[i * x_size + j] + 1;
                                if ((a + a + b) < 3) {
                                    i += a - 1;
                                    j += b - 2;
                                    if (i < 4) i = 4;
                                    if (j < 4) j = 4;
                                }
                            }
                        }
                        if (n == 2) {
                            b00 = mid[(i - 1)*x_size + j - 1] < 8;
                            b02 = mid[(i - 1)*x_size + j + 1] < 8;
                            b20 = mid[(i + 1)*x_size + j - 1] < 8;
                            b22 = mid[(i + 1)*x_size + j + 1] < 8;
                            if (((b00 + b02 + b20 + b22) == 2) && ((b00 | b22) & (b02 | b20))) {
                                x = (b00 && b02) ? 0 : (b00 ? -1 : (b02 ? 1 : 0));
                                y = (b00 && b02) ? -1 : (b00 ? 0 : (b02 ? 0 : 1));

                                if (((float)r[(i + y)*x_size + j + x] / centre) > 0.69999999999999996) {
                                    int vertical_ok = (x == 0) &&
                                        (mid[(i + 2*y)*x_size + j] > 7) &&
                                        (mid[(i + 2*y)*x_size + j - 1] > 7) &&
                                        (mid[(i + 2*y)*x_size + j + 1] > 7);
                                    int horizontal_ok = (y == 0) &&
                                        (mid[i*x_size + j + 2*x] > 7) &&
                                        (mid[(i+1)*x_size + j + 2*x] > 7) &&
                                        (mid[(i-1)*x_size + j + 2*x] > 7);
                                    if (vertical_ok || horizontal_ok) {
                                        mid[i*x_size + j] = 100;
                                        mid[(i + y)*x_size + j + x] = 3;
                                    }
                                }
                            } else {
                                b01 = mid[(i - 1)*x_size + j] < 8;
                                b12 = mid[i*x_size + j + 1] < 8;
                                b21 = mid[(i + 1)*x_size + j] < 8;
                                b10 = mid[i*x_size + j - 1] < 8;
                                if (((b01 + b12 + b21 + b10) == 2) && ((b10 | b12) & (b01 | b21)) &&
                                    ((b01 && ((mid[(i-2)*x_size + j-1] < 8) || (mid[(i-2)*x_size + j+1] < 8))) ||
                                     (b10 && ((mid[(i-1)*x_size + j-2] < 8) || (mid[(i+1)*x_size + j-2] < 8))) ||
                                     (b12 && ((mid[(i-1)*x_size + j+2] < 8) || (mid[(i+1)*x_size + j+2] < 8))) ||
                                     (b21 && ((mid[(i+2)*x_size + j-1] < 8) || (mid[(i+2)*x_size + j+1] < 8))))) {
                                    mid[i*x_size + j] = 100;
                                    i--; j -= 2;
                                    if (i < 4) i = 4;
                                    if (j < 4) j = 4;
                                }
                            }
                        }
                        if (n > 2) {
                            b01 = mid[(i - 1)*x_size + j] < 8;
                            b12 = mid[i*x_size + j + 1] < 8;
                            b21 = mid[(i + 1)*x_size + j] < 8;
                            b10 = mid[i*x_size + j - 1] < 8;
                            if ((b01 + b12 + b21 + b10) > 1) {
                                b00 = mid[(i - 1)*x_size + j - 1] < 8;
                                b02 = mid[(i - 1)*x_size + j + 1] < 8;
                                b20 = mid[(i + 1)*x_size + j - 1] < 8;
                                b22 = mid[(i + 1)*x_size + j + 1] < 8;
                                p1 = b00 | b01;
                                p2 = b02 | b12;
                                p3 = b22 | b21;
                                p4 = b20 | b10;
                                int edge_sum = (b01 & p2) + (b12 & p3) + (b21 & p4) + (b10 & p1);
                                if ((p1 + p2 + p3 + p4 - edge_sum) < 2) {
                                    mid[i*x_size + j] = 100;
                                    i--; j -= 2;
                                    if (i < 4) i = 4;
                                    if (j < 4) j = 4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
