#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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
    const int data_size = 64 * 1024 * 1024; // ~64MB of working data

    tr = malloc(sizeof(struct p7trace_s));
    ali = malloc(sizeof(struct fancyali_s));

    tr->tlen = data_size;
    tr->statetype = malloc(data_size * sizeof(char));
    tr->nodeidx = malloc(data_size * sizeof(int));
    tr->pos = malloc(data_size * sizeof(int));

    for (int i = 0; i < data_size; i++) {
        tr->statetype[i] = 'M';
        tr->nodeidx[i] = i;
        tr->pos[i] = (i % 1000) == 0 ? 0 : data_size - i; // ensure some positive values, last few are large
    }
    // Ensure at least one element > 0 near the end
    tr->pos[data_size - 1] = data_size;

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
}