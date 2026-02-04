#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};

typedef struct asn1_string_st ASN1_UNIVERSALSTRING;

ASN1_UNIVERSALSTRING *s;
int i;
unsigned char *p;

void init_vars() {
    s = (ASN1_UNIVERSALSTRING *)malloc(sizeof(ASN1_UNIVERSALSTRING));
    s->length = 262144; // 256KB of data ensures loop runs ~0.01 sec on modern CPU
    s->type = 0;
    s->flags = 0;
    s->data = (unsigned char *)malloc(s->length * sizeof(unsigned char));

    for (int j = 0; j < s->length; j++) {
        s->data[j] = '\x00';
    }

    p = s->data;
}