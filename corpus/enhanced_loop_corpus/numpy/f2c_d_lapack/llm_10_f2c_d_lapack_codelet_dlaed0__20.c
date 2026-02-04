#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer *iwork;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern integer smm1;
extern integer submat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        if (i__ + 1 > i__1) break;
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        doublereal abs_e_smm1 = (e[smm1] >= 0 ? e[smm1] : -e[smm1]);
        d__[smm1] -= abs_e_smm1;
        d__[submat] -= abs_e_smm1;

        integer submat_next = iwork[i__ + 1] + 1;
        integer smm1_next = submat_next - 1;
        doublereal abs_e_smm1_next = (e[smm1_next] >= 0 ? e[smm1_next] : -e[smm1_next]);
        d__[smm1_next] -= abs_e_smm1_next;
        d__[submat_next] -= abs_e_smm1_next;
    }
}
