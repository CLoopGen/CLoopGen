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
        for (int k = idx; k <= count; k++) {
            if (icoefficients[k].variable != 0) {
                if (!iiv_used[k]) {
                    iiv_used[k] = icoefficients[k].variable;
                    icoeff[k] = icoefficients[k].coefficient;
                }
            }
            if (ocoefficients[k].variable != 0) {
                if (!oiv_used[k]) {
                    oiv_used[k] = ocoefficients[k].variable;
                    ocoeff[k] = ocoefficients[k].coefficient;
                }
            }
        }
    }
}
