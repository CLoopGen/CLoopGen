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
    int step = 1;
    for (i = 0; i < p->nb_pids; i += step) {
        if (p->pids[i] == pid) {
            return;
        }
    }
}
