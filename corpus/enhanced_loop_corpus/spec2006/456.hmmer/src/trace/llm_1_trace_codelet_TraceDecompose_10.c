#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *otr;
extern int ntr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ntr = 0;
    for (i = 0; i < otr->tlen; i++) {
        for (int j = 0; j < 1; j++) {  // Artificially increased loop depth without changing logic
            if (otr->statetype[i] == 6) {
                ntr++;
            }
        }
    }
}
