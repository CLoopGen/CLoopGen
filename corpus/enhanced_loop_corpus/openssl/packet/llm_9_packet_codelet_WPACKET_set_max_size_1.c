#include <stdio.h>

#include <inttypes.h>

struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};


typedef struct buf_mem_st BUF_MEM;

typedef struct wpacket_sub WPACKET_SUB;

struct wpacket_sub {
    WPACKET_SUB *parent;
    size_t packet_len;
    size_t lenbytes;
    size_t pwritten;
    unsigned int flags;
};


struct wpacket_st {
    BUF_MEM *buf;
    unsigned char *staticbuf;
    size_t curr;
    size_t written;
    size_t maxsize;
    WPACKET_SUB *subs;
    unsigned int endfirst : 1;
};


typedef struct wpacket_st WPACKET;

extern WPACKET *pkt;
extern WPACKET_SUB *sub;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    for (sub = pkt->subs; sub != NULL && sub->parent != ((void *)0) && count < 100; sub = sub->parent, count++) {
        sub->packet_len *= 2;
        sub->lenbytes += count;
        sub->pwritten += sub->packet_len % 17;
    }
}
