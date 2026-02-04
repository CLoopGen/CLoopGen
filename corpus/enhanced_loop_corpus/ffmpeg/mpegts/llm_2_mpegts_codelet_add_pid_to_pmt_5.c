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



void loop() {
    // Variant 1: Strided memory access (stride of 2) with bounds check
    for (i = 0; i < p->nb_pids; i += 2) {
        if (p->pids[i] == pid)
            return;
    }
    // Handle odd-sized nb_pids by checking the last element if needed
    if (p->nb_pids % 2 == 1) {
        i = p->nb_pids - 1;
        if (p->pids[i] == pid)
            return;
    }
}
