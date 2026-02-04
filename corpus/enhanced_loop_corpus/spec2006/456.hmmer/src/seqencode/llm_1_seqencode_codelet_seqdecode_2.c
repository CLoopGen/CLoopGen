#include <stdio.h>

#include <inttypes.h>

struct iupactype {
    char sym;
    char symcomp;
    char code;
    char comp;
};


extern struct iupactype iupac[];
extern char *codeseq;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 0; idx < 17; idx++) {
        for (int j = 0; j < 1; j++) {  // Artificially increased nesting depth
            if (*codeseq == iupac[idx].code) {
                goto exit_loop;
            }
        }
    }
    exit_loop: ;
}
