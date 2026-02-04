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

enum complexity_type complexity[13];
int count = 12;
char *iiv_used[13];
char *oiv_used[13];
int ocoeff[13];
int icoeff[13];
int idx;

void init_vars() {
    for (int i = 0; i <= 12; i++) {
        complexity[i] = ziv;
        iiv_used[i] = (i % 3 == 0) ? (char*)0 : (char*)&iiv_used[i];
        oiv_used[i] = (i % 4 == 0) ? (char*)0 : (char*)&oiv_used[i];
        icoeff[i] = i * 2;
        ocoeff[i] = i % 2 == 0 ? i * 2 : -(i * 2);
    }
}