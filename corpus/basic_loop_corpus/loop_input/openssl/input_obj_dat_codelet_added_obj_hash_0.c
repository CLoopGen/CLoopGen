#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

struct asn1_object_st {
    const char *sn;
    const char *ln;
    int nid;
    int length;
    const unsigned char *data;
    int flags;
};

typedef struct asn1_object_st ASN1_OBJECT;

ASN1_OBJECT *a;
int i;
unsigned long ret;
unsigned char *p;

void init_vars() {
    a = malloc(sizeof(ASN1_OBJECT));
    if (!a) return;

    a->sn = "test_sn";
    a->ln = "test_long_name";
    a->nid = 123;
    a->length = 1024 * 512; // ~512KB of data to target ~0.01 sec runtime
    a->flags = 0;

    p = malloc(a->length);
    if (!p) {
        free(a);
        return;
    }

    for (int j = 0; j < a->length; j++) {
        p[j] = (unsigned char)(j & 0xFF);
    }

    a->data = p;

    ret = 0;
}