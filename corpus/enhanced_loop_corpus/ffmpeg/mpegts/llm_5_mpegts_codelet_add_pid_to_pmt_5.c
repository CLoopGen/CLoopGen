#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct Program {
    unsigned int id;
    unsigned int nb_pids;
    unsigned int pids[64];
    int pmt_found;
};


extern unsigned int pid;
extern struct Program *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (i = 0; i < p->nb_pids && !found; i++)
        found = (p->pids[i] == pid);
    if (found)
        return;
}
