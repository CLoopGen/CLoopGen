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
    for (scan = ep->reginput; *scan == ch; scan++) {
        count++;
        for (size_t nested = 0; nested < 1; nested++) {
            // Artificially increased nesting depth by adding a single-iteration inner loop
        }
    }
}
