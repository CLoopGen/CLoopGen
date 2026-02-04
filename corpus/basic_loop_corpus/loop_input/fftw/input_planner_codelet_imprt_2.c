#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int md5uint;

typedef md5uint md5sig[4];

typedef struct {
    unsigned int l : 20;
    unsigned int hash_info : 3;
    unsigned int timelimit_impatience : 9;
    unsigned int u : 20;
    unsigned int slvndx : 12;
} flags_t;

struct solution_s {
    md5sig s;
    flags_t flags;
};

typedef struct solution_s solution;

typedef struct {
    solution *solutions;
    unsigned int hashsiz;
    unsigned int nelem;
    int lookup;
    int succ_lookup;
    int lookup_iter;
    int insert;
    int insert_iter;
    int insert_unknown;
    int nrehash;
} hashtab;

hashtab *ht;
hashtab old;
unsigned int h;
unsigned int hsiz;

void init_vars() {
    hsiz = (1 << 20); // ~4MB of data: 2^20 entries * sizeof(solution) ≈ 4-8 bytes per solution -> ~8MB total
    ht = (hashtab *)malloc(sizeof(hashtab));
    ht->solutions = (solution *)calloc(hsiz, sizeof(solution));
    ht->hashsiz = hsiz;
    ht->nelem = hsiz;

    old.solutions = (solution *)calloc(hsiz, sizeof(solution));
    old.hashsiz = hsiz;
    old.nelem = hsiz;
}