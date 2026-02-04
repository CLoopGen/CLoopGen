#include <stdint.h>

typedef struct x509err2alert_st {
    int x509err;
    int alert;
} X509ERR2ALERT;

X509ERR2ALERT x509table[32768];
int x509err;
X509ERR2ALERT *tp;

void init_vars() {
    for (int i = 0; i < 32767; ++i) {
        x509table[i].x509err = i + 1;
        x509table[i].alert = 1000 + i;
    }
    x509table[32767].x509err = 0;
    x509table[32767].alert = 0;
    x509err = 16384;
    tp = x509table;
}