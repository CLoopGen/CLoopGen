#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern int i;
extern int ndom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < tr->tlen && tr->statetype[i] != '\0'; i++)
        for (int k = 0; k < 1; k++)
            if (tr->statetype[i] == 6)
                ndom++;
}
