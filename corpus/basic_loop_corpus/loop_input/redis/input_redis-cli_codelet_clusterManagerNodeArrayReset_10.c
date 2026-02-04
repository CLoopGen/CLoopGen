#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef char *sds;

typedef struct listNode {
    struct listNode *prev;
    struct listNode *next;
    void *value;
} listNode;

typedef struct list {
    listNode *head;
    listNode *tail;
    void *(*dup)(void *);
    void (*free)(void *);
    int (*match)(void *, void *);
    unsigned long len;
} list;

typedef struct clusterManagerNode {
    int *context;
    sds name;
    char *ip;
    int port;
    int bus_port;
    uint64_t current_epoch;
    time_t ping_sent;
    time_t ping_recv;
    int flags;
    list *flags_str;
    sds replicate;
    int dirty;
    uint8_t slots[16384];
    int slots_count;
    int replicas_count;
    list *friends;
    sds *migrating;
    sds *importing;
    int migrating_count;
    int importing_count;
    float weight;
    int balance;
} clusterManagerNode;

typedef struct clusterManagerNodeArray {
    clusterManagerNode **nodes;
    clusterManagerNode **alloc;
    int len;
    int count;
} clusterManagerNodeArray;

clusterManagerNodeArray *array;
int i;

static clusterManagerNode **init_nodes(int size) {
    clusterManagerNode **nodes = malloc(size * sizeof(clusterManagerNode*));
    for (int j = 0; j < size; j++) {
        if (rand() % 2) {
            nodes[j] = calloc(1, sizeof(clusterManagerNode));
            nodes[j]->context = malloc(sizeof(int));
            *nodes[j]->context = j;
            nodes[j]->name = NULL;
            nodes[j]->ip = NULL;
            nodes[j]->port = 7000 + j;
            nodes[j]->bus_port = 17000 + j;
            nodes[j]->current_epoch = j;
            nodes[j]->ping_sent = time(NULL) - rand() % 100;
            nodes[j]->ping_recv = time(NULL) - rand() % 100;
            nodes[j]->flags = rand() % 4;
            nodes[j]->flags_str = NULL;
            nodes[j]->replicate = NULL;
            nodes[j]->dirty = rand() % 2;
            for (int k = 0; k < 16384; k++) {
                nodes[j]->slots[k] = rand() % 2;
            }
            nodes[j]->slots_count = rand() % 1000;
            nodes[j]->replicas_count = rand() % 10;
            nodes[j]->friends = NULL;
            nodes[j]->migrating = NULL;
            nodes[j]->importing = NULL;
            nodes[j]->migrating_count = 0;
            nodes[j]->importing_count = 0;
            nodes[j]->weight = 1.0f / (rand() % 10 + 1);
            nodes[j]->balance = rand() % 100;
        } else {
            nodes[j] = NULL;
        }
    }
    return nodes;
}

void init_vars() {
    const int size = 100000;
    array = malloc(sizeof(clusterManagerNodeArray));
    array->nodes = init_nodes(size);
    array->alloc = array->nodes;
    array->len = size;
    array->count = 0;
    i = 0;
}