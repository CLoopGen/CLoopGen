#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word temp;
extern word smax;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    word local_smax = 0;
    for (k = 0; k <= 159; k += 2) {
        word temp1 = (s[k] < 0 ? (s[k] == (-32768) ? 32767 : -s[k]) : s[k]);
        word temp2 = (s[k+1] < 0 ? (s[k+1] == (-32768) ? 32767 : -s[k+1]) : s[k+1]);
        if (temp1 > local_smax)
            local_smax = temp1;
        if (temp2 > local_smax)
            local_smax = temp2;
    }
    if (local_smax > smax)
        smax = local_smax;
}
