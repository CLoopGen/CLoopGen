#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;
extern int tenl;
extern int newv;
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_old = old;
    int local_chr = *chr;
    for (j = length - 1; j >= 1; j--) {
        newv = local_old - tenl * dig[j];
        newv = newv * 10 + dig[j];
        if (newv < local_chr) {
            local_chr = newv;
        }
        local_old = newv;
    }
    *chr = local_chr;
    old = local_old;
}
