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
    for (i = 4; i < y_size - 4; i += 2) {
        for (j = 4; j < x_size - 4; j += 2) {
            if (mid[i * x_size + j] >= 8) continue;

            centre = r[i * x_size + j];
            mp = mid + (i - 1) * x_size + j - 1;
            n = 0;
            n += (mp[0] < 8); n += (mp[1] < 8); n += (mp[2] < 8);
            n += (mp[x_size] < 8); n += (mp[x_size + 2] < 8);
            n += (mp[2*x_size] < 8); n += (mp[2*x_size + 1] < 8); n += (mp[2*x_size + 2] < 8);

            if (n == 0) {
                mid[i * x_size + j] = 100;
            } else if (n == 1 && mid[i * x_size + j] < 6) {
                // Load 3x3 neighborhood values with conditional scaling
                #define IDX(y,x) r[(i + (y))*x_size + j + (x)]
                l[0] = IDX(-1,-1); l[1] = IDX(-1, 0); l[2] = IDX(-1, 1);
                l[3] = IDX( 0,-1); l[4] = 0;         l[5] = IDX( 0, 1);
                l[6] = IDX( 1,-1); l[7] = IDX( 1, 0); l[8] = IDX( 1, 1);
                #undef IDX

                const uchar* mptr = mid + (i-1)*x_size + j - 1;
                if (mptr[0] < 8) {
                    l[0] = l[1] = l[3] = 0; l[2]*=2; l[6]*=2; l[5]*=3; l[7]*=3; l[8]*=4;
                } else if (mptr[1] < 8) {
                    l[1] = l[0] = l[2] = 0; l[3]*=2; l[5]*=2; l[6]*=3; l[8]*=3; l[7]*=4;
                } else if (mptr[2] < 8) {
                    l[2] = l[1] = l[5] = 0; l[0]*=2; l[8]*=2; l[3]*=3; l[7]*=3; l[6]*=4;
                } else if (mptr[x_size] < 8) {
                    l[3] = l[0] = l[6] = 0; l[1]*=2; l[7]*=2; l[2]*=3; l[8]*=3; l[5]*=4;
                } else if (mptr[x_size+2] < 8) {
                    l[5] = l[2] = l[8] = 0; l[1]*=2; l[7]*=2; l[0]*=3; l[6]*=3; l[3]*=4;
                } else if (mptr[2*x_size] < 8) {
                    l[6] = l[3] = l[7] = 0; l[0]*=2; l[8]*=2; l[1]*=3; l[5]*=3; l[2]*=4;
                } else if (mptr[2*x_size+1] < 8) {
                    l[7] = l[6] = l[8] = 0; l[3]*=2; l[5]*=2; l[0]*=3; l[2]*=3; l[1]*=4;
                } else if (mptr[2*x_size+2] < 8) {
                    l[8] = l[5] = l[7] = 0; l[6]*=2; l[2]*=2; l[1]*=3; l[3]*=3; l[0]*=4;
                }

                m = 0; a = 0; b = 0;
                for (int yy = 0; yy < 3; yy++) {
                    for (int xx = 0; xx < 3; xx++) {
                        int idx = yy * 3 + xx;
                        if (l[idx] > m) {
                            m = l[idx];
                            a = yy;
                            b = xx;
                        }
                    }
                }

                if (m > 0) {
                    int ni = i + a - 1, nj = j + b - 1;
                    mid[ni * x_size + nj] = (mid[i*x_size+j] < 4) ? 4 : mid[i*x_size+j] + 1;

                    if (a + b < 2) {
                        i += a - 1;
                        j += b - 2;
                        if (i < 4) i = 4;
                        if (j < 4) j = 4;
                    }
                }
            } else if (n == 2) {
                b00 = mid[(i-1)*x_size + j-1] < 8;
                b02 = mid[(i-1)*x_size + j+1] < 8;
                b20 = mid[(i+1)*x_size + j-1] < 8;
                b22 = mid[(i+1)*x_size + j+1] < 8;

                if ((b00 + b02 + b20 + b22) == 2 && (b00 || b22) && (b02 || b20)) {
                    x = y = 0;
                    if (b00) {
                        x = b02 ? 0 : -1;
                        y = b02 ? -1 : 0;
                    } else {
                        x = b20 ? 1 : 0;
                        y = b20 ? 0 : 1;
                    }

                    int nx = j + x, ny = i + y;
                    if (((float)r[ny * x_size + nx] / centre) > 0.7f) {
                        int edge_ok = (x == 0) ?
                            (mid[(ny+y)*x_size + nx] > 7 && mid[(ny+y)*x_size + nx-1] > 7 && mid[(ny+y)*x_size + nx+1] > 7) :
                            (mid[ny*x_size + nx+x] > 7 && mid[(ny+1)*x_size + nx+x] > 7 && mid[(ny-1)*x_size + nx+x] > 7);
                        if (edge_ok) {
                            mid[i*x_size + j] = 100;
                            mid[ny*x_size + nx] = 3;
                        }
                    }
                } else {
                    b01 = mid[(i-1)*x_size + j] < 8;
                    b12 = mid[i*x_size + j+1] < 8;
                    b21 = mid[(i+1)*x_size + j] < 8;
                    b10 = mid[i*x_size + j-1] < 8;

                    int two_adj = (b01 + b12 + b21 + b10) == 2;
                    int cross = (b10 || b12) && (b01 || b21);
                    int extend = 0;
                    if (b01) extend |= (mid[(i-2)*x_size + j-1] < 8) || (mid[(i-2)*x_size + j+1] < 8);
                    if (b10) extend |= (mid[(i-1)*x_size + j-2] < 8) || (mid[(i+1)*x_size + j-2] < 8);
                    if (b12) extend |= (mid[(i-1)*x_size + j+2] < 8) || (mid[(i+1)*x_size + j+2] < 8);
                    if (b21) extend |= (mid[(i+2)*x_size + j-1] < 8) || (mid[(i+2)*x_size + j+1] < 8);

                    if (two_adj && cross && extend) {
                        mid[i*x_size + j] = 100;
                        i--; j -= 2;
                        if (i < 4) i = 4;
                        if (j < 4) j = 4;
                    }
                }
            } else if (n > 2) {
                b01 = mid[(i-1)*x_size + j] < 8;
                b12 = mid[i*x_size + j+1] < 8;
                b21 = mid[(i+1)*x_size + j] < 8;
                b10 = mid[i*x_size + j-1] < 8;

                if ((b01 + b12 + b21 + b10) > 1) {
                    b00 = mid[(i-1)*x_size + j-1] < 8;
                    b02 = mid[(i-1)*x_size + j+1] < 8;
                    b20 = mid[(i+1)*x_size + j-1] < 8;
                    b22 = mid[(i+1)*x_size + j+1] < 8;

                    p1 = b00 || b01; p2 = b02 || b12;
                    p3 = b22 || b21; p4 = b20 || b10;

                    int sum_p = p1 + p2 + p3 + p4;
                    int overlaps = (b01 && p2) + (b12 && p3) + (b21 && p4) + (b10 && p1);
                    if (sum_p - overlaps < 2) {
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
