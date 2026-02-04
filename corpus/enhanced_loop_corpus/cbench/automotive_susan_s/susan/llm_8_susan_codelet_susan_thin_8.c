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
for (i = 8; i < y_size - 8; i += 2)
    for (j = 8; j < x_size - 8; j += 2)
        if (mid[i * x_size + j] < 8) {
            centre = r[i * x_size + j];
            mp = mid + (i - 1) * x_size + j - 1;
            n = (*mp < 8) + (*(mp + 1) < 8) + (*(mp + 2) < 8) + (*(mp + x_size) < 8) + (*(mp + x_size + 2) < 8) + 
                (*(mp + x_size + x_size) < 8) + (*(mp + x_size + x_size + 1) < 8) + (*(mp + x_size + x_size + 2) < 8);
            if (n == 0)
                mid[i * x_size + j] = 100;
            else if ((n == 1) && (mid[i * x_size + j] < 6)) {
                l[0] = r[(i - 1) * x_size + j - 1];
                l[1] = r[(i - 1) * x_size + j];
                l[2] = r[(i - 1) * x_size + j + 1];
                l[3] = r[i * x_size + j - 1];
                l[4] = 0;
                l[5] = r[i * x_size + j + 1];
                l[6] = r[(i + 1) * x_size + j - 1];
                l[7] = r[(i + 1) * x_size + j];
                l[8] = r[(i + 1) * x_size + j + 1];

                if (mid[(i - 1) * x_size + j - 1] < 8) {
                    l[0] = l[1] = l[3] = 0;
                    l[2] <<= 1; l[6] <<= 1; l[5] *= 3; l[7] *= 3; l[8] <<= 2;
                } else if (mid[(i - 1) * x_size + j] < 8) {
                    l[1] = l[0] = l[2] = 0;
                    l[3] <<= 1; l[5] <<= 1; l[6] *= 3; l[8] *= 3; l[7] <<= 2;
                } else if (mid[(i - 1) * x_size + j + 1] < 8) {
                    l[2] = l[1] = l[5] = 0;
                    l[0] <<= 1; l[8] <<= 1; l[3] *= 3; l[7] *= 3; l[6] <<= 2;
                } else if (mid[i * x_size + j - 1] < 8) {
                    l[3] = l[0] = l[6] = 0;
                    l[1] <<= 1; l[7] <<= 1; l[2] *= 3; l[8] *= 3; l[5] <<= 2;
                } else if (mid[i * x_size + j + 1] < 8) {
                    l[5] = l[2] = l[8] = 0;
                    l[1] <<= 1; l[7] <<= 1; l[0] *= 3; l[6] *= 3; l[3] <<= 2;
                } else if (mid[(i + 1) * x_size + j - 1] < 8) {
                    l[6] = l[3] = l[7] = 0;
                    l[0] <<= 1; l[8] <<= 1; l[1] *= 3; l[5] *= 3; l[2] <<= 2;
                } else if (mid[(i + 1) * x_size + j] < 8) {
                    l[7] = l[6] = l[8] = 0;
                    l[3] <<= 1; l[5] <<= 1; l[0] *= 3; l[2] *= 3; l[1] <<= 2;
                } else if (mid[(i + 1) * x_size + j + 1] < 8) {
                    l[8] = l[5] = l[7] = 0;
                    l[6] <<= 1; l[2] <<= 1; l[1] *= 3; l[3] *= 3; l[0] <<= 2;
                }

                m = a = b = 0;
                for (y = 0; y < 3; y++) {
                    int base = y * 3;
                    for (x = 0; x < 3; x++)
                        if (l[base + x] > m) {
                            m = l[base + x];
                            a = y;
                            b = x;
                        }
                }
                if (m > 0) {
                    int target_idx = (i + a - 1) * x_size + j + b - 1;
                    mid[target_idx] = (mid[i * x_size + j] < 4) ? 4 : mid[i * x_size + j] + 1;
                    if ((a << 1) + b < 3) {
                        i += a - 1;
                        j += b - 2;
                        if (i < 8) i = 8;
                        if (j < 8) j = 8;
                    }
                }
            }
            else if (n == 2) {
                b00 = mid[(i - 1) * x_size + j - 1] < 8;
                b02 = mid[(i - 1) * x_size + j + 1] < 8;
                b20 = mid[(i + 1) * x_size + j - 1] < 8;
                b22 = mid[(i + 1) * x_size + j + 1] < 8;
                if (((b00 + b02 + b20 + b22) == 2) && ((b00 | b22) & (b02 | b20))) {
                    if (b00) {
                        x = b02 ? 0 : -1;
                        y = b02 ? -1 : 0;
                    } else {
                        x = b20 ? 1 : 0;
                        y = b20 ? 0 : 1;
                    }
                    if (((float)r[(i + y) * x_size + j + x] / centre) > 0.7f) {
                        int cond1 = (x == 0) && (mid[(i + (y << 1)) * x_size + j] > 7) &&
                                    (mid[(i + (y << 1)) * x_size + j - 1] > 7) &&
                                    (mid[(i + (y << 1)) * x_size + j + 1] > 7);
                        int cond2 = (y == 0) && (mid[i * x_size + j + (x << 1)] > 7) &&
                                    (mid[(i + 1) * x_size + j + (x << 1)] > 7) &&
                                    (mid[(i - 1) * x_size + j + (x << 1)] > 7);
                        if (cond1 || cond2) {
                            mid[i * x_size + j] = 100;
                            mid[(i + y) * x_size + j + x] = 3;
                        }
                    }
                } else {
                    b01 = mid[(i - 1) * x_size + j] < 8;
                    b12 = mid[i * x_size + j + 1] < 8;
                    b21 = mid[(i + 1) * x_size + j] < 8;
                    b10 = mid[i * x_size + j - 1] < 8;
                    if (((b01 + b12 + b21 + b10) == 2) && ((b10 | b12) & (b01 | b21)) &&
                        ((b01 & ((mid[(i - 2) * x_size + j - 1] < 8) | (mid[(i - 2) * x_size + j + 1] < 8))) |
                         (b10 & ((mid[(i - 1) * x_size + j - 2] < 8) | (mid[(i + 1) * x_size + j - 2] < 8))) |
                         (b12 & ((mid[(i - 1) * x_size + j + 2] < 8) | (mid[(i + 1) * x_size + j + 2] < 8))) |
                         (b21 & ((mid[(i + 2) * x_size + j - 1] < 8) | (mid[(i + 2) * x_size + j + 1] < 8))))) {
                        mid[i * x_size + j] = 100;
                        i -= 2;
                        j -= 3;
                        if (i < 8) i = 8;
                        if (j < 8) j = 8;
                    }
                }
            }
            else if (n > 2) {
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
                    if (((p1 + p2 + p3 + p4) - ((b01 & p2) + (b12 & p3) + (b21 & p4) + (b10 & p1))) < 2) {
                        mid[i * x_size + j] = 100;
                        i -= 2;
                        j -= 3;
                        if (i < 8) i = 8;
                        if (j < 8) j = 8;
                    }
                }
            }
        }
}
