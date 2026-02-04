#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct gki_elem {
    char *key;
    int idx;
    struct gki_elem *nxt;
};

typedef struct {
    struct gki_elem **table;
    int primelevel;
    int nhash;
    int nkeys;
    int nempty;
} GKI;

GKI *hash;
struct gki_elem *ptr;
int i;
int nkeys;
int nempty;
int maxkeys;
int minkeys;

#define TABLE_SIZE 10000
#define CHAIN_LENGTH 100

void init_vars() {
    hash = (GKI *)calloc(1, sizeof(GKI));
    hash->nhash = TABLE_SIZE;
    hash->table = (struct gki_elem **)calloc(TABLE_SIZE, sizeof(struct gki_elem *));

    for (int idx = 0; idx < TABLE_SIZE; idx++) {
        int length = rand() % (CHAIN_LENGTH + 1);
        if (length == 0) {
            hash->table[idx] = NULL;
        } else {
            struct gki_elem *head = NULL;
            for (int j = 0; j < length; j++) {
                struct gki_elem *elem = (struct gki_elem *)malloc(sizeof(struct gki_elem));
                elem->key = (char *)malloc(16);
                sprintf(elem->key, "key_%d_%d", idx, j);
                elem->idx = j;
                elem->nxt = head;
                head = elem;
            }
            hash->table[idx] = head;
        }
    }

    ptr = NULL;
    i = 0;
    nkeys = 0;
    nempty = 0;
    maxkeys = 0;
    minkeys = CHAIN_LENGTH + 1;
}