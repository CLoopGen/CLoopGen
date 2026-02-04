#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  long m;
extern  long a;
extern  long q;
extern  long r;
extern unsigned long s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        long h = s / q;
        long t = a * (s - h * q) - h * r;
        if (t < 0)
            t += m;
        s = t;
        // Introduce artificial WAW and WAR dependency by reusing t in an independent auxiliary computation
        long t_aux = t * 2 + 1;  // WAR: t is read after last write in loop iteration
        s = t_aux;               // WAW: s is overwritten again, creating write-after-write with previous s = t
        t_aux = s + 1;           // RAW: t_aux depends on latest s
    }
}
