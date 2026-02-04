#include <stdio.h>

#include <inttypes.h>

typedef struct x509err2alert_st {
    int x509err;
    int alert;
} X509ERR2ALERT;

extern  X509ERR2ALERT x509table[];
extern int x509err;
extern  X509ERR2ALERT *tp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 3, followed by cleanup in natural order
    int stride = 3;
    X509ERR2ALERT *p = x509table;
    int i;

    // Strided forward traversal to quickly skip through the array
    for (i = 0; p[i * stride].x509err != 0; i++) {
        if (p[i * stride].x509err == x509err) {
            tp = &p[i * stride];
            return;
        }
    }

    // Fallback: linear scan from last strided position to ensure no element is missed
    // Start from where the stride stopped or from beginning if no stride hit
    X509ERR2ALERT *start = (i == 0) ? x509table : &p[(i-1) * stride];
    for (tp = start; tp->x509err != 0; ++tp) {
        if (tp->x509err == x509err)
            break;
    }
}
