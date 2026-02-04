#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct fancyali_s {
    char *rfline;
    char *csline;
    char *model;
    char *mline;
    char *aseq;
    int len;
    char *query;
    char *target;
    int sqfrom;
    int sqto;
};

struct p7trace_s *tr;
struct fancyali_s *ali;
int tpos;

void init_vars() {
    tr = malloc(sizeof(struct p7trace_s));
    ali = malloc(sizeof(struct fancyali_s));

    tr->tlen = 1 << 20;

    tr->statetype = malloc(tr->tlen * sizeof(char));
    tr->nodeidx = malloc(tr->tlen * sizeof(int));
    tr->pos = malloc(tr->tlen * sizeof(int));

    for (int i = 0; i < tr->tlen; i++) {
        tr->statetype[i] = 'M';
        tr->nodeidx[i] = i;
        tr->pos[i] = (i == tr->tlen - 1) ? 1 : 0;
    }

    ali->rfline = NULL;
    ali->csline = NULL;
    ali->model = NULL;
    ali->mline = NULL;
    ali->aseq = NULL;
    ali->len = 0;
    ali->query = NULL;
    ali->target = NULL;
    ali->sqfrom = 0;
    ali->sqto = 0;

    tpos = 0;
}