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
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled inner loop
    for (q = 0; q < pri->mnum; q++) {
        float base_mq = defmq[q] * 1.5f + 0.1f;
        pri->mq[q] = base_mq;

        // Unroll the inner loop by a factor of 4 (20 / 4 = 5 iterations)
        int x = 0;
        for (; x < 20; x += 4) {
            pri->m[q][x]     = defm[q][x]     * base_mq + 0.01f;
            pri->m[q][x + 1] = defm[q][x + 1] * base_mq + 0.01f;
            pri->m[q][x + 2] = defm[q][x + 2] * base_mq + 0.01f;
            pri->m[q][x + 3] = defm[q][x + 3] * base_mq + 0.01f;
        }
    }
}
