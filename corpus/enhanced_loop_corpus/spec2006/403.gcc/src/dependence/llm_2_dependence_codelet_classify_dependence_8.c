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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of using idx directly as an index, simulate consecutive access by iterating through complexity arrays
    // in natural order with unit stride, enhancing cache locality.
    for (idx = 1; idx <= count; idx++) {
        int c_idx = idx; // Direct consecutive access

        if (iiv_used[c_idx] == 0 && oiv_used[c_idx] == 0)
            complexity[c_idx] = ziv;
        else if (iiv_used[c_idx] == oiv_used[c_idx]) {
            if (icoeff[c_idx] == ocoeff[c_idx])
                complexity[c_idx] = strong_siv;
            else if (icoeff[c_idx] == -1 * ocoeff[c_idx])
                complexity[c_idx] = weak_crossing_siv;
            else
                complexity[c_idx] = weak_siv;
        } else if (icoeff[c_idx] == 0 || ocoeff[c_idx] == 0)
            complexity[c_idx] = weak_zero_siv;
        else
            complexity[c_idx] = miv;
    }
}
