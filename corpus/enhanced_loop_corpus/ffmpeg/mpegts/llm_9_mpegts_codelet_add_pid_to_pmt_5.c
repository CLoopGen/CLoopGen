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
    for (i = 0; i < p->nb_pids && i < 64; i++) {
        unsigned int current_pid = p->pids[i];
        if (current_pid == pid) {
            return;
        }
    }
}
