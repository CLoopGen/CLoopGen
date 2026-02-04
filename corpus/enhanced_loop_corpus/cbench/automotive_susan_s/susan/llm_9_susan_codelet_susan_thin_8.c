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
for (i = 2; i < y_size - 2; i++)
    for (j = 2; j < x_size - 2; j++) {
        int idx = i * x_size + j;
        if (mid[idx] >= 8) continue;

        centre = r[idx];
        mp = mid + (i - 1) * x_size + j - 1;
        n = 0;
        n += (mp[0] < 8); n += (mp[1] < 8); n += (mp[2] < 8);
        n += (mp[x_size] < 8); n += (mp[x_size + 2] < 8);
        n += (mp[x_size + x_size] < 8); n += (mp[x_size + x_size + 1] < 8); n += (mp[x_size + x_size + 2] < 8);

        if (n == 0) {
            mid[idx] = 100;
            continue;
        }

        if (n == 1 && mid[idx] < 6) {
            int offsets[9] = {
                (i-1)*x_size + j-1, (i-1)*x_size + j, (i-1)*x_size + j+1,
                i*x_size + j-1, -1,
                i*x_size + j+1,
                (i+1)*x_size + j-1, (i+1)*x_size + j, (i+1)*x_size + j+1
            };

            for (int k = 0; k < 9; k++)
                l[k] = (offsets[k] == -1) ? 0 : r[offsets[k]];

            uchar* mids = mid + (i-1)*x_size + j - 1;
            if (mids[0] < 8) {
                l[0] = l[1] = l[3] = 0;
                l[2] *= 2; l[6] *= 2; l[5] *= 3; l[7] *= 3; l[8] *= 4;
            } else if (mids[1] < 8) {
                l[1] = l[0] = l[2] = 0;
                l[3] *= 2; l[5] *= 2; l[6] *= 3; l[8] *= 3; l[7] *= 4;
            } else if (mids[2] < 8) {
                l[2] = l[1] = l[5] = 0;
                l[0] *= 2; l[8] *= 2; l[3] *= 3; l[7] *= 3; l[6] *= 4;
            } else if (mids[x_size] < 8) {
                l[3] = l[0] = l[6] = 0;
                l[1] *= 2; l[7] *= 2; l[2] *= 3; l[8] *= 3; l[5] *= 4;
            } else if (mids[x_size + 2] < 8) {
                l[5] = l[2] = l[8] = 0;
                l[1] *= 2; l[7] *= 2; l[0] *= 3; l[6] *= 3; l[3] *= 4;
            } else if (mids[x_size + x_size] < 8) {
                l[6] = l[3] = l[7] = 0;
                l[0] *= 2; l[8] *= 2; l[1] *= 3; l[5] *= 3; l[2] *= 4;
            } else if (mids[x_size + x_size + 1] < 8) {
                l[7] = l[6] = l[8] = 0;
                l[3] *= 2; l[5] *= 2; l[0] *= 3; l[2] *= 3; l[1] *= 4;
            } else if (mids[x_size + x_size + 2] < 8) {
                l[8] = l[5] = l[7] = 0;
                l[6] *= 2; l[2] *= 2; l[1] *= 3; l[3] *= 3; l[0] *= 4;
            }

            m = -1; a = b = 0;
            for (int ky = 0; ky < 3; ky++) {
                int row_base = ky * 3;
                for (int kx = 0; kx < 3; kx++) {
                    int val = l[row_base + kx];
                    if (val > m) {
                        m = val;
                        a = ky;
                        b = kx;
                    }
                }
            }

            if (m > 0) {
                int new_i = i + a - 1;
                int new_j = j + b - 1;
                int dst_idx = new_i * x_size + new_j;
                mid[dst_idx] = (mid[idx] < 4) ? 4 : mid[idx] + 1;

                if ((a << 1) + b < 3) {
                    i = new_i;
                    j = new_j - 1;
                    if (i < 2) i = 2;
                    if (j < 2) j = 2;
                }
            }
        }

        if (n == 2) {
            b00 = mid[(i-1)*x_size + j-1] < 8;
            b02 = mid[(i-1)*x_size + j+1] < 8;
            b20 = mid[(i+1)*x_size + j-1] < 8;
            b22 = mid[(i+1)*x_size + j+1] < 8;

            if ((b00 + b02 + b20 + b22) == 2 && ((b00 | b22) & (b02 | b20))) {
                if (b00 && b02) { x = 0; y = -1; }
                else if (b00 && b20) { x = -1; y = 0; }
                else if (b02 && b22) { x = 1; y = 0; }
                else { x = 0; y = 1; }

                if ((float)r[(i+y)*x_size + j+x] / centre > 0.7) {
                    int edge_ok = 0;
                    if (x == 0) {
                        int iy = i + (y << 1);
                        edge_ok = (mid[iy*x_size + j] > 7) && (mid[iy*x_size + j-1] > 7) && (mid[iy*x_size + j+1] > 7);
                    } else {
                        int jx = j + (x << 1);
                        edge_ok = (mid[i*x_size + jx] > 7) && (mid[(i+1)*x_size + jx] > 7) && (mid[(i-1)*x_size + jx] > 7);
                    }
                    if (edge_ok) {
                        mid[idx] = 100;
                        mid[(i+y)*x_size + j+x] = 3;
                    }
                }
            } else {
                b01 = mid[(i-1)*x_size + j] < 8;
                b12 = mid[i*x_size + j+1] < 8;
                b21 = mid[(i+1)*x_size + j] < 8;
                b10 = mid[i*x_size + j-1] < 8;

                if ((b01 + b12 + b21 + b10) == 2 && ((b10 | b12) & (b01 | b21))) {
                    int ext = 0;
                    ext |= b01 && (mid[(i-2)*x_size + j-1] < 8 || mid[(i-2)*x_size + j+1] < 8);
                    ext |= b10 && (mid[(i-1)*x_size + j-2] < 8 || mid[(i+1)*x_size + j-2] < 8);
                    ext |= b12 && (mid[(i-1)*x_size + j+2] < 8 || mid[(i+1)*x_size + j+2] < 8);
                    ext |= b21 && (mid[(i+2)*x_size + j-1] < 8 || mid[(i+2)*x_size + j+1] < 8);
                    if (ext) {
                        mid[idx] = 100;
                        i--; j--;
                        if (i < 2) i = 2;
                        if (j < 2) j = 2;
                    }
                }
            }
        }

        if (n > 2) {
            b01 = mid[(i-1)*x_size + j] < 8;
            b12 = mid[i*x_size + j+1] < 8;
            b21 = mid[(i+1)*x_size + j] < 8;
            b10 = mid[i*x_size + j-1] < 8;

            if ((b01 + b12 + b21 + b10) > 1) {
                b00 = mid[(i-1)*x_size + j-1] < 8;
                b02 = mid[(i-1)*x_size + j+1] < 8;
                b20 = mid[(i+1)*x_size + j-1] < 8;
                b22 = mid[(i+1)*x_size + j+1] < 8;

                p1 = b00 | b01;
                p2 = b02 | b12;
                p3 = b22 | b21;
                p4 = b20 | b10;

                int overlap = (b01 & p2) + (b12 & p3) + (b21 & p4) + (b10 & p1);
                if ((p1 + p2 + p3 + p4) - overlap < 2) {
                    mid[idx] = 100;
                    i--; j--;
                    if (i < 2) i = 2;
                    if (j < 2) j = 2;
                }
            }
        }
    }
}
