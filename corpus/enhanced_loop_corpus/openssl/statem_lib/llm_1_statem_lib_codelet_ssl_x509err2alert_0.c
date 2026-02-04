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
for (int found = 0; !found && tp->x509err != 0; ++tp) {
    for (int i = 0; i < 1; ++i) {  // Artificially nested inner loop with single iteration
        if (tp->x509err == x509err) {
            found = 1;
            break;
        }
    }
}
}
