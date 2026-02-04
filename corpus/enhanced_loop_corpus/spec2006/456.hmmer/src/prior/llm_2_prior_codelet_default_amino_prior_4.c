#include <stdio.h>

#include <inttypes.h>

struct p7prior_s {
    int strategy;
    int tnum;
    float tq[200];
    float t[200][7];
    int mnum;
    float mq[200];
    float m[200][20];
    int inum;
    float iq[200];
    float i[200][20];
};


extern struct p7prior_s *pri;
extern int q;
extern int x;
extern float defmq[9];
extern float defm[9][20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse iteration
    for (q = pri->mnum - 1; q >= 0; q--) {
        int idx = q * 20;
        pri->mq[q] = defmq[q];
        for (x = 0; x < 20; x++) {
            // Access m in a linear, consecutive pattern via flattened indexing
            ((float*)pri->m)[idx + x] = defm[q][x];
        }
    }
}
