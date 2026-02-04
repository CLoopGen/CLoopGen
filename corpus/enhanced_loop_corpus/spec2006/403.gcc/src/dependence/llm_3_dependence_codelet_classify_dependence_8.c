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
    // Variant 2: Strided Memory Access Pattern
    // Access elements with a fixed stride (e.g., every 2nd element) to simulate non-unit stride access.
    // This changes memory access pattern and may affect cache performance.
    const int stride = 2;
    // Adjust loop bounds to ensure we don't exceed array limits when applying stride
    int upper_bound = (count / stride) * stride;

    for (idx = stride; idx <= upper_bound; idx += stride) {
        int s_idx = idx; // Strided index usage

        if (iiv_used[s_idx] == 0 && oiv_used[s_idx] == 0)
            complexity[s_idx] = ziv;
        else if (iiv_used[s_idx] == oiv_used[s_idx]) {
            if (icoeff[s_idx] == ocoeff[s_idx])
                complexity[s_idx] = strong_siv;
            else if (icoeff[s_idx] == -1 * ocoeff[s_idx])
                complexity[s_idx] = weak_crossing_siv;
            else
                complexity[s_idx] = weak_siv;
        } else if (icoeff[s_idx] == 0 || ocoeff[s_idx] == 0)
            complexity[s_idx] = weak_zero_siv;
        else
            complexity[s_idx] = miv;
    }

    // Handle remaining elements if count is not divisible by stride
    for (idx = upper_bound + 1; idx <= count; idx++) {
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
