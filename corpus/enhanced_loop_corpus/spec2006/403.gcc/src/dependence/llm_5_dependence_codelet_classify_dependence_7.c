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
        int process_input = 0, process_output = 0;
        if (icoefficients[idx].variable != 0 && !iiv_used[idx]) {
            process_input = 1;
        }
        if (ocoefficients[idx].variable != 0 && !oiv_used[idx]) {
            process_output = 1;
        }

        if (process_input) {
            iiv_used[idx] = icoefficients[idx].variable;
            icoeff[idx] = icoefficients[idx].coefficient;
        }
        if (process_output) {
            oiv_used[idx] = ocoefficients[idx].variable;
            ocoeff[idx] = ocoefficients[idx].coefficient;
        }
    }
}
