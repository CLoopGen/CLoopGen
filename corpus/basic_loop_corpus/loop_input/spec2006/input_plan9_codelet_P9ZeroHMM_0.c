#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct basic_state {
    float t[3];
    float p[20];
};

struct plan9_s {
    int M;
    struct basic_state *ins;
    struct basic_state *mat;
    struct basic_state *del;
    float null[20];
    char *name;
    char *ref;
    char *cs;
    float *xray;
    int flags;
};

int Alphabet_size = 20;
struct plan9_s *hmm;
int k;
int ts;
int idx;

void init_vars() {
    Alphabet_size = 20;
    
    hmm = (struct plan9_s*)calloc(1, sizeof(struct plan9_s));
    if (!hmm) return;
    
    hmm->M = 1000;
    
    size_t array_size = hmm->M + 2;
    
    hmm->ins = (struct basic_state*)calloc(array_size, sizeof(struct basic_state));
    hmm->mat = (struct basic_state*)calloc(array_size, sizeof(struct basic_state));
    hmm->del = (struct basic_state*)calloc(array_size, sizeof(struct basic_state));
    
    hmm->name = (char*)malloc(64);
    if (hmm->name) strcpy(hmm->name, "default");
    
    hmm->ref = (char*)malloc(64);
    if (hmm->ref) strcpy(hmm->ref, "reference");
    
    hmm->cs = (char*)malloc(64);
    if (hmm->cs) strcpy(hmm->cs, "cs_string");
    
    hmm->xray = (float*)calloc(Alphabet_size, sizeof(float));
    
    hmm->flags = 0;
}