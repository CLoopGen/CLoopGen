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
    for (idx = count; idx >= 1; idx--) {
        int temp_icoeff = icoeff[idx] + 1;
        int temp_ocoeff = ocoeff[idx] + 1;
        if (iiv_used[idx] == 0 && oiv_used[idx] == 0) {
            complexity[idx] = ziv;
        } else if (iiv_used[idx] == oiv_used[idx]) {
            if (temp_icoeff == temp_ocoeff)
                complexity[idx] = strong_siv;
            else if (temp_icoeff == -temp_ocoeff)
                complexity[idx] = weak_crossing_siv;
            else
                complexity[idx] = weak_siv;
        } else if (temp_icoeff == 1 || temp_ocoeff == 1)
            complexity[idx] = weak_zero_siv;
        else
            complexity[idx] = miv;
    }
}
