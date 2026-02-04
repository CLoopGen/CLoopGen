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

char *all_slots;
int totslots;
int i;
clusterManagerNode *node;

void init_vars() {
    // Allocate and initialize all_slots as a byte array of size 16384
    all_slots = (char *)calloc(16384, sizeof(char));
    if (!all_slots) exit(1);

    // Reset global counters
    totslots = 0;
    i = 0;

    // Allocate node
    node = (clusterManagerNode *)malloc(sizeof(clusterManagerNode));
    if (!node) exit(1);

    // Initialize node fields
    node->context = NULL;
    node->name = NULL;
    node->ip = NULL;
    node->port = 0;
    node->bus_port = 0;
    node->current_epoch = 0;
    node->ping_sent = 0;
    node->ping_recv = 0;
    node->flags = 0;
    node->flags_str = NULL;
    node->replicate = NULL;
    node->dirty = 0;

    // Initialize slots: set approximately half to 1 to trigger condition
    for (int j = 0; j < 16384; j++) {
        node->slots[j] = (j % 2) ? 1 : 0;  // Every odd index has slot occupied
    }
    node->slots_count = 8192;

    node->replicas_count = 0;
    node->friends = NULL;
    node->migrating = NULL;
    node->importing = NULL;
    node->migrating_count = 0;
    node->importing_count = 0;
    node->weight = 1.0f;
    node->balance = 0;
}