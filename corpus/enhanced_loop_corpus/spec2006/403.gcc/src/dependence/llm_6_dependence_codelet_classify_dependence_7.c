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
    int temp_icoeff[13] = {0};
    int temp_ocoeff[13] = {0};
    char *temp_iiv_used[13] = {0};
    char *temp_oiv_used[13] = {0};

    for (idx = 1; idx <= count; idx++) {
        if (icoefficients[idx].variable != 0) {
            if (!iiv_used[idx]) {
                temp_iiv_used[idx] = icoefficients[idx].variable;
                temp_icoeff[idx] = icoefficients[idx].coefficient;
            }
        }
        if (ocoefficients[idx].variable != 0) {
            if (!oiv_used[idx]) {
                temp_oiv_used[idx] = ocoefficients[idx].variable;
                temp_ocoeff[idx] = ocoefficients[idx].coefficient;
            }
        }
    }

    for (idx = 1; idx <= count; idx++) {
        if (!iiv_used[idx] && temp_iiv_used[idx]) {
            iiv_used[idx] = temp_iiv_used[idx];
            icoeff[idx] = temp_icoeff[idx];
        }
        if (!oiv_used[idx] && temp_oiv_used[idx]) {
            oiv_used[idx] = temp_oiv_used[idx];
            ocoeff[idx] = temp_ocoeff[idx];
        }
    }
}
