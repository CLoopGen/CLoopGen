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
    X509ERR2ALERT *local_tp;
    int match_index = -1;
    int i;

    for (i = 0; x509table[i].x509err != 0; ++i) {
        if (x509table[i].x509err == x509err && match_index == -1) {
            match_index = i; // Introduce WAW-free recording of first match
        }
    }

    local_tp = &x509table[match_index != -1 ? match_index : i];
    tp = local_tp; // Final assignment breaks loop-carried WAW on 'tp'
}
