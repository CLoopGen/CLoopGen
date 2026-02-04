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
        if (mid[i * x_size + j] < 8) {
            centre = r[i * x_size + j];
            mp = mid + (i - 1) * x_size + j - 1;
            n = 0;
            n += (*mp < 8);
            n += (*(mp + 1) < 8);
            n += (*(mp + 2) < 8);
            n += (*(mp + x_size) < 8);
            n += (*(mp + x_size + 2) < 8);
            n += (*(mp + 2*x_size) < 8);
            n += (*(mp + 2*x_size + 1) < 8);
            n += (*(mp + 2*x_size + 2) < 8);

            if (n == 0) {
                mid[i * x_size + j] = 100;
            } else if (n == 1 && mid[i * x_size + j] < 6) {
                int offsets[9] = {
                    (i-1)*x_size + j-1, (i-1)*x_size + j, (i-1)*x_size + j+1,
                    i*x_size + j-1, 0, i*x_size + j+1,
                    (i+1)*x_size + j-1, (i+1)*x_size + j, (i+1)*x_size + j+1
                };
                for (int k = 0; k < 9; k++) {
                    if (offsets[k] == 0) continue;
                    l[k] = r[offsets[k]];
                }

                if (mid[(i-1)*x_size + j-1] < 8) {
                    l[0] = l[1] = l[3] = 0;
                    l[2] <<= 1; l[6] <<= 1; 
                    l[5] *= 3; l[7] *= 3; 
                    l[8] <<= 2;
                } else if (mid[(i-1)*x_size + j] < 8) {
                    l[1] = l[0] = l[2] = 0;
                    l[3] <<= 1; l[5] <<= 1; 
                    l[6] *= 3; l[8] *= 3; 
                    l[7] <<= 2;
                } else if (mid[(i-1)*x_size + j+1] < 8) {
                    l[2] = l[1] = l[5] = 0;
                    l[0] <<= 1; l[8] <<= 1; 
                    l[3] *= 3; l[7] *= 3; 
                    l[6] <<= 2;
                } else if (mid[i*x_size + j-1] < 8) {
                    l[3] = l[0] = l[6] = 0;
                    l[1] <<= 1; l[7] <<= 1; 
                    l[2] *= 3; l[8] *= 3; 
                    l[5] <<= 2;
                } else if (mid[i*x_size + j+1] < 8) {
                    l[5] = l[2] = l[8] = 0;
                    l[1] <<= 1; l[7] <<= 1; 
                    l[0] *= 3; l[6] *= 3; 
                    l[3] <<= 2;
                } else if (mid[(i+1)*x_size + j-1] < 8) {
                    l[6] = l[3] = l[7] = 0;
                    l[0] <<= 1; l[8] <<= 1; 
                    l[1] *= 3; l[5] *= 3; 
                    l[2] <<= 2;
                } else if (mid[(i+1)*x_size + j] < 8) {
                    l[7] = l[6] = l[8] = 0;
                    l[3] <<= 1; l[5] <<= 1; 
                    l[0] *= 3; l[2] *= 3; 
                    l[1] <<= 2;
                } else if (mid[(i+1)*x_size + j+1] < 8) {
                    l[8] = l[5] = l[7] = 0;
                    l[6] <<= 1; l[2] <<= 1; 
                    l[1] *= 3; l[3] *= 3; 
                    l[0] <<= 2;
                }

                m = a = b = 0;
                for (y = 0; y < 3; ++y) {
                    for (x = 0; x < 3; ++x) {
                        int val = l[y*3 + x];
                        if (val > m) {
                            m = val;
                            a = y;
                            b = x;
                        }
                    }
                }

                if (m > 0) {
                    int idx = (i + a - 1) * x_size + j + b - 1;
                    mid[idx] = (mid[i * x_size + j] < 4) ? 4 : mid[i * x_size + j] + 1;

                    if ((a << 1) + b < 3) {
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
                int diag_sum = b00 + b02 + b20 + b22;
                if (diag_sum == 2 && ((b00 | b22) & (b02 | b20))) {
                    if (b00) {
                        y = b02 ? -1 : 0;
                        x = b02 ? 0 : -1;
                    } else {
                        y = b22 ? 1 : 0;
                        x = b22 ? 0 : 1;
                    }
                    float ratio = (float)r[(i + y) * x_size + j + x] / (float)centre;
                    if (ratio > 0.69999999999999996) {
                        int cond1 = (x == 0) && (mid[(i+2*y)*x_size + j] > 7) && (mid[(i+2*y)*x_size + j-1] > 7) && (mid[(i+2*y)*x_size + j+1] > 7);
                        int cond2 = (y == 0) && (mid[i*x_size + j+2*x] > 7) && (mid[(i+1)*x_size + j+2*x] > 7) && (mid[(i-1)*x_size + j+2*x] > 7);
                        if (cond1 || cond2) {
                            mid[i*x_size + j] = 100;
                            mid[(i+y)*x_size + j+x] = 3;
                        }
                    }
                } else {
                    b01 = mid[(i-1)*x_size + j] < 8;
                    b12 = mid[i*x_size + j+1] < 8;
                    b21 = mid[(i+1)*x_size + j] < 8;
                    b10 = mid[i*x_size + j-1] < 8;
                    int edge_sum = b01 + b12 + b21 + b10;
                    if (edge_sum == 2 && ((b10 | b12) & (b01 | b21))) {
                        int corner_check = (b01 & ((mid[(i-2)*x_size + j-1] < 8) | (mid[(i-2)*x_size + j+1] < 8))) |
                                          (b10 & ((mid[(i-1)*x_size + j-2] < 8) | (mid[(i+1)*x_size + j-2] < 8))) |
                                          (b12 & ((mid[(i-1)*x_size + j+2] < 8) | (mid[(i+1)*x_size + j+2] < 8))) |
                                          (b21 & ((mid[(i+2)*x_size + j-1] < 8) | (mid[(i+2)*x_size + j+1] < 8)));
                        if (corner_check) {
                            mid[i*x_size + j] = 100;
                            i--;
                            j -= 2;
                            if (i < 4) i = 4;
                            if (j < 4) j = 4;
                        }
                    }
                }
            } else if (n > 2) {
                b01 = mid[(i-1)*x_size + j] < 8;
                b12 = mid[i*x_size + j+1] < 8;
                b21 = mid[(i+1)*x_size + j] < 8;
                b10 = mid[i*x_size + j-1] < 8;
                if (b01 + b12 + b21 + b10 > 1) {
                    b00 = mid[(i-1)*x_size + j-1] < 8;
                    b02 = mid[(i-1)*x_size + j+1] < 8;
                    b20 = mid[(i+1)*x_size + j-1] < 8;
                    b22 = mid[(i+1)*x_size + j+1] < 8;
                    p1 = b00 | b01;
                    p2 = b02 | b12;
                    p3 = b22 | b21;
                    p4 = b20 | b10;
                    int total = p1 + p2 + p3 + p4;
                    int overlap = (b01 & p2) + (b12 & p3) + (b21 & p4) + (b10 & p1);
                    if (total - overlap < 2) {
                        mid[i*x_size + j] = 100;
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
}
