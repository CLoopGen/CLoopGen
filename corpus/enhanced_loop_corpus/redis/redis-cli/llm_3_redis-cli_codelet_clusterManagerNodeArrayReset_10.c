#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern clusterManagerNodeArray *array;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(array->len * sizeof(int));
    for (int j = 0; j < array->len; j++) {
        indices[j] = j;
    }
    for (int j = 0; j < array->len; j++) {
        int idx = indices[j];
        if (array->nodes[idx] != ((void *)0))
            array->count++;
    }
    free(indices);
}
