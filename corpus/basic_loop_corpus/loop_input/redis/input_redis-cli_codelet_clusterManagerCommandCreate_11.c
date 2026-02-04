#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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

int i;
int interleaved_len;
clusterManagerNode **interleaved;

void init_vars() {
    interleaved_len = 131072; // ~131k elements to achieve ~0.01 sec runtime

    interleaved = (clusterManagerNode**)calloc(interleaved_len, sizeof(clusterManagerNode*));
    if (!interleaved) exit(1);

    for (int idx = 0; idx < interleaved_len; idx++) {
        clusterManagerNode *node = (clusterManagerNode*)malloc(sizeof(clusterManagerNode));
        if (!node) exit(1);

        node->context = (int*)calloc(1, sizeof(int));
        *node->context = idx;

        node->name = (sds)strdup("default_name");
        node->ip = strdup("127.0.0.1");
        node->port = 7000 + (idx % 1000);
        node->bus_port = node->port + 10000;
        node->current_epoch = idx * 1000ULL;
        node->ping_sent = time(NULL) - (idx % 100);
        node->ping_recv = time(NULL) - (idx % 50);
        node->flags = (idx % 2) ? 1 : 0;
        node->flags_str = NULL;
        node->replicate = (sds)strdup("replicate_target");
        node->dirty = 0;
        memset(node->slots, 0, sizeof(node->slots));
        node->slots_count = 0;
        node->replicas_count = idx % 10;
        node->friends = NULL;
        node->migrating = NULL;
        node->importing = NULL;
        node->migrating_count = 0;
        node->importing_count = 0;
        node->weight = 1.0f / (1 + idx % 10);
        node->balance = idx % 100;

        interleaved[idx] = node;
    }
}