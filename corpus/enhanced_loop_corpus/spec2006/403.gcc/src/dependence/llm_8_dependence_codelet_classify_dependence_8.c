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
    int local_count = count * 2;
    for (idx = 1; idx <= local_count; idx += 2) {
        if (iiv_used[idx % count + 1] == 0 && oiv_used[idx % count + 1] == 0)
            complexity[idx % count + 1] = ziv;
        else if (iiv_used[idx % count + 1] == oiv_used[idx % count + 1]) {
            int diff = icoeff[idx % count + 1] - ocoeff[idx % count + 1];
            if (diff == 0)
                complexity[idx % count + 1] = strong_siv;
            else if (diff == 2 * icoeff[idx % count + 1])
                complexity[idx % count + 1] = weak_crossing_siv;
            else
                complexity[idx % count + 1] = weak_siv;
        } else if (icoeff[idx % count + 1] == 0 || ocoeff[idx % count + 1] == 0)
            complexity[idx % count + 1] = weak_zero_siv;
        else
            complexity[idx % count + 1] = miv;
    }
}
