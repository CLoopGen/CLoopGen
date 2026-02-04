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
    X509ERR2ALERT *temp_ptr = x509table;
    int found = 0;
    for (; temp_ptr->x509err != 0 && !found; ++temp_ptr) {
        if (temp_ptr->x509err == x509err) {
            tp = temp_ptr;
            found = 1;
        }
    }
    if (!found) {
        tp = temp_ptr; // Point to the entry with x509err == 0 (terminator)
    }
}
