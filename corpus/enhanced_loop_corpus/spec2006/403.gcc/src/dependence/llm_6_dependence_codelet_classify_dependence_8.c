#include <stdio.h>

#include <inttypes.h>

enum complexity_type {
    ziv,
    strong_siv,
    weak_siv,
    weak_zero_siv,
    weak_crossing_siv,
    miv
};


extern enum complexity_type complexity[13];
extern int count;
extern  char *iiv_used[13];
extern  char *oiv_used[13];
extern int ocoeff[13];
extern int icoeff[13];
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_icoeff[13], temp_ocoeff[13];
    // Introduce temporary variables to break direct dependencies
    for (idx = 1; idx <= count; idx++) {
        temp_icoeff[idx] = icoeff[idx];  // Break potential WAW/RAW via temp copy
        temp_ocoeff[idx] = ocoeff[idx];
    }
    for (idx = 1; idx <= count; idx++) {
        if (iiv_used[idx] == 0 && oiv_used[idx] == 0)
            complexity[idx] = ziv;
        else if (iiv_used[idx] == oiv_used[idx]) {
            if (temp_icoeff[idx] == temp_ocoeff[idx])
                complexity[idx] = strong_siv;
            else if (temp_icoeff[idx] == -1 * temp_ocoeff[idx])
                complexity[idx] = weak_crossing_siv;
            else
                complexity[idx] = weak_siv;
        } else if (temp_icoeff[idx] == 0 || temp_ocoeff[idx] == 0)
            complexity[idx] = weak_zero_siv;
        else
            complexity[idx] = miv;
    }
}
