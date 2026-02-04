#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

WPACKET *pkt;
WPACKET_SUB *sub;

static BUF_MEM g_buf_mem;
static unsigned char g_staticbuf[1024 * 128]; // 128KB buffer
static WPACKET_SUB g_subs[1024];
static WPACKET g_wpacket;

void init_vars() {
    g_buf_mem.length = 0;
    g_buf_mem.data = NULL;
    g_buf_mem.max = 0;
    g_buf_mem.flags = 0;

    for (int i = 0; i < 1023; i++) {
        g_subs[i].parent = &g_subs[i + 1];
        g_subs[i].packet_len = 0;
        g_subs[i].lenbytes = 0;
        g_subs[i].pwritten = 0;
        g_subs[i].flags = 0;
    }
    g_subs[1023].parent = NULL;
    g_subs[1023].packet_len = 0;
    g_subs[1023].lenbytes = 0;
    g_subs[1023].pwritten = 0;
    g_subs[1023].flags = 0;

    g_wpacket.buf = &g_buf_mem;
    g_wpacket.staticbuf = g_staticbuf;
    g_wpacket.curr = 0;
    g_wpacket.written = 0;
    g_wpacket.maxsize = sizeof(g_staticbuf);
    g_wpacket.subs = &g_subs[0];
    g_wpacket.endfirst = 0;

    pkt = &g_wpacket;
    sub = &g_subs[0];
}