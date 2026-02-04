#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct p7prior_s *pri;
int q;
int x;
float defmq[9];
float defm[9][20];

void init_vars() {
    pri = (struct p7prior_s *)malloc(sizeof(struct p7prior_s));
    if (!pri) return;

    pri->mnum = 9;
    for (int i = 0; i < 9; i++) {
        defmq[i] = 1.0f + i;
        for (int j = 0; j < 20; j++) {
            defm[i][j] = 2.0f + j;
        }
    }

    for (int i = 0; i < 200; i++) {
        pri->tq[i] = 0.0f;
        pri->iq[i] = 0.0f;
        for (int j = 0; j < 7; j++) {
            pri->t[i][j] = 0.0f;
        }
        for (int j = 0; j < 20; j++) {
            pri->m[i][j] = 0.0f;
            pri->i[i][j] = 0.0f;
        }
    }
}