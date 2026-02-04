#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_OCTET_STRING;

extern  unsigned char *opp;
extern ASN1_OCTET_STRING *os;
extern int i;
extern int printable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i;
    int found_nonprintable = 0;
    for (local_i = 0; local_i < os->length && !found_nonprintable; local_i++) {
        unsigned char val = opp[local_i];
        int is_control_except_common = (val < ' ') && (val != '\n') && (val != '\r') && (val != '\t');
        int is_above_tilde = (val > '~');
        if (is_control_except_common || is_above_tilde) {
            found_nonprintable = 1;
        }
        i = local_i + 1; // WAW on i, breaks original loop-carried dependency on exit value of i
    }
    printable = !found_nonprintable;
}
