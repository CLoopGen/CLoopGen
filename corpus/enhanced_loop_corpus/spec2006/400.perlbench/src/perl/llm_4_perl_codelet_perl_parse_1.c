#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern char **PL_origenviron;
extern char *s;
extern int i;
extern UV mask;
extern UV aligned;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; PL_origenviron[i]; i++) {
        if (!(PL_origenviron[i] == s + 1 || (aligned && (PL_origenviron[i] > s && PL_origenviron[i] <= (char *)((UV)(s + 8) & mask))))) {
            break;
        }
        s = PL_origenviron[i];
        for (; *s; s++);
    }
}
