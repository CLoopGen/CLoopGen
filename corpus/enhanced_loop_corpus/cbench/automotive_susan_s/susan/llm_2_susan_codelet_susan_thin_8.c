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
    for (i = 4; i < y_size - 4; i += 2) {
        for (j = 4; j < x_size - 4; j += 2) {
            int idx = i * x_size + j;
            if (mid[idx] < 8) {
                centre = r[idx];
                mp = mid + (i - 1) * x_size + j - 1;
                n = (*mp < 8) + (*(mp + 1) < 8) + (*(mp + 2) < 8) +
                    (*(mp + x_size) < 8) + (*(mp + x_size + 2) < 8) +
                    (*(mp + 2*x_size) < 8) + (*(mp + 2*x_size + 1) < 8) + (*(mp + 2*x_size + 2) < 8);

                if (n == 0) {
                    mid[idx] = 100;
                } else if ((n == 1) && (mid[idx] < 6)) {
                    int offsets[9] = {
                        (i-1)*x_size + j-1, (i-1)*x_size + j, (i-1)*x_size + j+1,
                        i*x_size + j-1, 0, i*x_size + j+1,
                        (i+1)*x_size + j-1, (i+1)*x_size + j, (i+1)*x_size + j+1
                    };
                    for (int k = 0; k < 9; k++) {
                        if (k == 4) continue;
                        l[k] = r[offsets[k]];
                    }
                    l[4] = 0;

                    int corner_idx = -1;
                    if (mid[(i-1)*x_size + j-1] < 8) corner_idx = 0;
                    else if (mid[(i-1)*x_size + j] < 8) corner_idx = 1;
                    else if (mid[(i-1)*x_size + j+1] < 8) corner_idx = 2;
                    else if (mid[i*x_size + j-1] < 8) corner_idx = 3;
                    else if (mid[i*x_size + j+1] < 8) corner_idx = 5;
                    else if (mid[(i+1)*x_size + j-1] < 8) corner_idx = 6;
                    else if (mid[(i+1)*x_size + j] < 8) corner_idx = 7;
                    else if (mid[(i+1)*x_size + j+1] < 8) corner_idx = 8;

                    if (corner_idx != -1) {
                        int mult[9] = {1,1,1,1,1,1,1,1,1};
                        switch(corner_idx) {
                            case 0: l[0]=0;l[1]=0;l[3]=0; mult[2]=2;mult[6]=2;mult[5]=3;mult[7]=3;mult[8]=4; break;
                            case 1: l[1]=0;l[0]=0;l[2]=0; mult[3]=2;mult[5]=2;mult[6]=3;mult[8]=3;mult[7]=4; break;
                            case 2: l[2]=0;l[1]=0;l[5]=0; mult[0]=2;mult[8]=2;mult[3]=3;mult[7]=3;mult[6]=4; break;
                            case 3: l[3]=0;l[0]=0;l[6]=0; mult[1]=2;mult[7]=2;mult[2]=3;mult[8]=3;mult[5]=4; break;
                            case 5: l[5]=0;l[2]=0;l[8]=0; mult[1]=2;mult[7]=2;mult[0]=3;mult[6]=3;mult[3]=4; break;
                            case 6: l[6]=0;l[3]=0;l[7]=0; mult[0]=2;mult[8]=2;mult[1]=3;mult[5]=3;mult[2]=4; break;
                            case 7: l[7]=0;l[6]=0;l[8]=0; mult[3]=2;mult[5]=2;mult[0]=3;mult[2]=3;mult[1]=4; break;
                            case 8: l[8]=0;l[5]=0;l[7]=0; mult[6]=2;mult[2]=2;mult[1]=3;mult[3]=3;mult[0]=4; break;
                        }
                        for (int k = 0; k < 9; k++) {
                            if (k != corner_idx && k != 4) l[k] *= mult[k];
                        }
                    }

                    m = 0; a = 0; b = 0;
                    for (y = 0; y < 3; y++) {
                        for (x = 0; x < 3; x++) {
                            int val = l[y*3 + x];
                            if (val > m) {
                                m = val;
                                a = y;
                                b = x;
                            }
                        }
                    }

                    if (m > 0) {
                        int new_i = i + a - 1, new_j = j + b - 1;
                        if (mid[idx] < 4)
                            mid[new_i * x_size + new_j] = 4;
                        else
                            mid[new_i * x_size + new_j] = mid[idx] + 1;

                        if ((a + a + b) < 3) {
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
                    if (((b00 + b02 + b20 + b22) == 2) && ((b00 | b22) & (b02 | b20))) {
                        if (b00) {
                            x = (b02 ? 0 : -1);
                            y = (b02 ? -1 : 0);
                        } else {
                            x = (b02 ? 1 : 0);
                            y = (b02 ? 0 : 1);
                        }
                        if (((float)r[(i+y)*x_size + j+x] / (float)centre) > 0.7) {
                            int axis_ok = (x == 0) ?
                                (mid[(i+2*y)*x_size + j] > 7 && mid[(i+2*y)*x_size + j-1] > 7 && mid[(i+2*y)*x_size + j+1] > 7) :
                                (mid[i*x_size + j+2*x] > 7 && mid[(i+1)*x_size + j+2*x] > 7 && mid[(i-1)*x_size + j+2*x] > 7);
                            if (axis_ok) {
                                mid[idx] = 100;
                                mid[(i+y)*x_size + j+x] = 3;
                            }
                        }
                    } else {
                        b01 = mid[(i-1)*x_size + j] < 8;
                        b12 = mid[i*x_size + j+1] < 8;
                        b21 = mid[(i+1)*x_size + j] < 8;
                        b10 = mid[i*x_size + j-1] < 8;
                        if (((b01 + b12 + b21 + b10) == 2) && ((b10 | b12) & (b01 | b21)) &&
                            ((b01 & ((mid[(i-2)*x_size + j-1] < 8) | (mid[(i-2)*x_size + j+1] < 8))) |
                             (b10 & ((mid[(i-1)*x_size + j-2] < 8) | (mid[(i+1)*x_size + j-2] < 8))) |
                             (b12 & ((mid[(i-1)*x_size + j+2] < 8) | (mid[(i+1)*x_size + j+2] < 8))) |
                             (b21 & ((mid[(i+2)*x_size + j-1] < 8) | (mid[(i+2)*x_size + j+1] < 8))))) {
                            mid[idx] = 100;
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
                        p1 = b00 | b01; p2 = b02 | b12;
                        p3 = b22 | b21; p4 = b20 | b10;
                        if (((p1 + p2 + p3 + p4) - ((b01 & p2) + (b12 & p3) + (b21 & p4) + (b10 & p1))) < 2) {
                            mid[idx] = 100;
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
