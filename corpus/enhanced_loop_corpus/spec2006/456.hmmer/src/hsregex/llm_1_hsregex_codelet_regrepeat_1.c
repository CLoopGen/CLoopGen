#include <stdio.h>

#include <inttypes.h>

struct exec {
    char *reginput;
    char *regbol;
    char **regstartp;
    char **regendp;
};


extern struct exec *ep;
extern size_t count;
extern char *scan;
extern char ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop depth by unrolling the first iteration and then continuing with original loop
    if (*ep->reginput == ch) {
        count++;
        scan = ep->reginput + 1;
    } else {
        scan = ep->reginput;
        return;
    }
    for (; *scan == ch; scan++)
        count++;
}
