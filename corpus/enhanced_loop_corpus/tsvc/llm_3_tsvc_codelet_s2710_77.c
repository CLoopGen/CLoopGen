#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 0; i < 32000; i += 8) {
        int idx0 = i;
        int idx1 = i + 1;
        int idx2 = i + 2;
        int idx3 = i + 3;
        int idx4 = i + 4;
        int idx5 = i + 5;
        int idx6 = i + 6;
        int idx7 = i + 7;

        if (idx0 < 32000) {
            if (a[idx0] > b[idx0]) {
                a[idx0] += b[idx0] * d[idx0];
                if (32000 > 10) {
                    c[idx0] += d[idx0] * d[idx0];
                } else {
                    c[idx0] = d[idx0] * e[idx0] + (real_t)1.;
                }
            } else {
                b[idx0] = a[idx0] + e[idx0] * e[idx0];
                if (x > (real_t)0.) {
                    c[idx0] = a[idx0] + d[idx0] * d[idx0];
                } else {
                    c[idx0] += e[idx0] * e[idx0];
                }
            }
        }

        if (idx1 < 32000) {
            if (a[idx1] > b[idx1]) {
                a[idx1] += b[idx1] * d[idx1];
                if (32000 > 10) {
                    c[idx1] += d[idx1] * d[idx1];
                } else {
                    c[idx1] = d[idx1] * e[idx1] + (real_t)1.;
                }
            } else {
                b[idx1] = a[idx1] + e[idx1] * e[idx1];
                if (x > (real_t)0.) {
                    c[idx1] = a[idx1] + d[idx1] * d[idx1];
                } else {
                    c[idx1] += e[idx1] * e[idx1];
                }
            }
        }

        if (idx2 < 32000) {
            if (a[idx2] > b[idx2]) {
                a[idx2] += b[idx2] * d[idx2];
                if (32000 > 10) {
                    c[idx2] += d[idx2] * d[idx2];
                } else {
                    c[idx2] = d[idx2] * e[idx2] + (real_t)1.;
                }
            } else {
                b[idx2] = a[idx2] + e[idx2] * e[idx2];
                if (x > (real_t)0.) {
                    c[idx2] = a[idx2] + d[idx2] * d[idx2];
                } else {
                    c[idx2] += e[idx2] * e[idx2];
                }
            }
        }

        if (idx3 < 32000) {
            if (a[idx3] > b[idx3]) {
                a[idx3] += b[idx3] * d[idx3];
                if (32000 > 10) {
                    c[idx3] += d[idx3] * d[idx3];
                } else {
                    c[idx3] = d[idx3] * e[idx3] + (real_t)1.;
                }
            } else {
                b[idx3] = a[idx3] + e[idx3] * e[idx3];
                if (x > (real_t)0.) {
                    c[idx3] = a[idx3] + d[idx3] * d[idx3];
                } else {
                    c[idx3] += e[idx3] * e[idx3];
                }
            }
        }

        if (idx4 < 32000) {
            if (a[idx4] > b[idx4]) {
                a[idx4] += b[idx4] * d[idx4];
                if (32000 > 10) {
                    c[idx4] += d[idx4] * d[idx4];
                } else {
                    c[idx4] = d[idx4] * e[idx4] + (real_t)1.;
                }
            } else {
                b[idx4] = a[idx4] + e[idx4] * e[idx4];
                if (x > (real_t)0.) {
                    c[idx4] = a[idx4] + d[idx4] * d[idx4];
                } else {
                    c[idx4] += e[idx4] * e[idx4];
                }
            }
        }

        if (idx5 < 32000) {
            if (a[idx5] > b[idx5]) {
                a[idx5] += b[idx5] * d[idx5];
                if (32000 > 10) {
                    c[idx5] += d[idx5] * d[idx5];
                } else {
                    c[idx5] = d[idx5] * e[idx5] + (real_t)1.;
                }
            } else {
                b[idx5] = a[idx5] + e[idx5] * e[idx5];
                if (x > (real_t)0.) {
                    c[idx5] = a[idx5] + d[idx5] * d[idx5];
                } else {
                    c[idx5] += e[idx5] * e[idx5];
                }
            }
        }

        if (idx6 < 32000) {
            if (a[idx6] > b[idx6]) {
                a[idx6] += b[idx6] * d[idx6];
                if (32000 > 10) {
                    c[idx6] += d[idx6] * d[idx6];
                } else {
                    c[idx6] = d[idx6] * e[idx6] + (real_t)1.;
                }
            } else {
                b[idx6] = a[idx6] + e[idx6] * e[idx6];
                if (x > (real_t)0.) {
                    c[idx6] = a[idx6] + d[idx6] * d[idx6];
                } else {
                    c[idx6] += e[idx6] * e[idx6];
                }
            }
        }

        if (idx7 < 32000) {
            if (a[idx7] > b[idx7]) {
                a[idx7] += b[idx7] * d[idx7];
                if (32000 > 10) {
                    c[idx7] += d[idx7] * d[idx7];
                } else {
                    c[idx7] = d[idx7] * e[idx7] + (real_t)1.;
                }
            } else {
                b[idx7] = a[idx7] + e[idx7] * e[idx7];
                if (x > (real_t)0.) {
                    c[idx7] = a[idx7] + d[idx7] * d[idx7];
                } else {
                    c[idx7] += e[idx7] * e[idx7];
                }
            }
        }
    }
}
}
