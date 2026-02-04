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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling by 2 elements
    X509ERR2ALERT *p = x509table;
    for (; p->x509err != 0; p += 2) {
        if (p->x509err == x509err) {
            tp = p;
            return;
        }
        if ((p+1)->x509err == 0) break;
        if ((p+1)->x509err == x509err) {
            tp = p + 1;
            return;
        }
    }
    // Handle odd-sized tail or single element
    for (; p->x509err != 0; ++p)
        if (p->x509err == x509err)
            break;
    tp = p;
}
