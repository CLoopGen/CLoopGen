#include <stdio.h>

#include <inttypes.h>

typedef struct subscript {
    int position;
    int coefficient;
    int offset;
    const char *variable;
    struct subscript *next;
} subscript;

extern subscript icoefficients[13];
extern subscript ocoefficients[13];
extern int count;
extern  char *iiv_used[13];
extern  char *oiv_used[13];
extern int ocoeff[13];
extern int icoeff[13];
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 1; idx <= count; idx++) {
        if (icoefficients[idx].variable != 0) {
            if (!iiv_used[idx]) {
                iiv_used[idx] = icoefficients[idx].variable;
                icoeff[idx] = icoefficients[idx].coefficient;
            }
        }
        for (int j = 1; j <= idx; j++) {
            if (ocoefficients[j].variable != 0) {
                if (!oiv_used[j]) {
                    oiv_used[j] = ocoefficients[j].variable;
                    ocoeff[j] = ocoefficients[j].coefficient;
                }
            }
        }
    }
}
