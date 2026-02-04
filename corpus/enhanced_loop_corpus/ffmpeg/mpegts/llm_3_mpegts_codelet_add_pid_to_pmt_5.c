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
    // Variant 2: Indirect memory access via an index remapping array (simulated static permutation)
    unsigned int indices[64];
    for (int j = 0; j < 64; j++) {
        indices[j] = (j * 3 + 1) % 64; // Simple deterministic permutation
    }
    for (i = 0; i < p->nb_pids; i++) {
        unsigned int idx = indices[i]; // Indirect access using remapped index
        if (idx < p->nb_pids && p->pids[idx] == pid)
            return;
    }
}
