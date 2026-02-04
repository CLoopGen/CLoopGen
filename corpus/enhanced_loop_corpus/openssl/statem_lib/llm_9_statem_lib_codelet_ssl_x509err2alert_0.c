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
    // Variant 2: Reduced effective trip count by skipping every other element initially, then correcting if needed
    // Introduces stride-based traversal to alter loop characteristics while preserving correctness
    X509ERR2ALERT *next_tp;
    for (tp = x509table; tp->x509err != 0; tp = next_tp) {
        if (tp->x509err == x509err)
            break;
        next_tp = tp + 1;
        // Skip next element unless it's the last valid one
        if (next_tp->x509err != 0) {
            next_tp = tp + 2;  // Stride of 2 to reduce iterations
            // If we skipped over a potential match, step back to linear scan
            if (next_tp > x509table && (next_tp - 1)->x509err == x509err) {
                tp = next_tp - 1;
                break;
            }
        }
        // Ensure progress even if double advance skips null terminator
        if (next_tp->x509err == 0 && (next_tp - 1)->x509err != 0)
            next_tp = tp + 1;
    }
}
