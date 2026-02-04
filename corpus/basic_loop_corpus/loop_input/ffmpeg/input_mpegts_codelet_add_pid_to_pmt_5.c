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

unsigned int pid = 42;
struct Program *p;
int i;

void init_vars() {
    p = (struct Program*)malloc(sizeof(struct Program));
    if (!p) exit(1);

    p->id = 1001;
    p->nb_pids = 64;  
    p->pmt_found = 0;

    for (int j = 0; j < 63; j++) {
        p->pids[j] = (j + 1) * 100; 
    }
    p->pids[63] = pid; 
}