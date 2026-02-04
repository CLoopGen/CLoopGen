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
for (idx = 1; idx <= count; idx++) {
    if (iiv_used[idx] == 0 && oiv_used[idx] == 0)
        complexity[idx] = ziv;
    else if (iiv_used[idx] == oiv_used[idx]) {
        if (icoeff[idx] == ocoeff[idx])
            complexity[idx] = strong_siv;
        else if (icoeff[idx] == -1 * ocoeff[idx])
            complexity[idx] = weak_crossing_siv;
        else
            complexity[idx] = weak_siv;
    } else if (icoeff[idx] == 0 || ocoeff[idx] == 0)
        complexity[idx] = weak_zero_siv;
    else
        complexity[idx] = miv;
}

}
