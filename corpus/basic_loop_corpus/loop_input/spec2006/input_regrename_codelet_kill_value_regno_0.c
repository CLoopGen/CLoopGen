#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

enum machine_mode {
    VOIDmode,
    BImode,
    QImode,
    HImode,
    SImode,
    DImode,
    TImode,
    OImode,
    PQImode,
    PHImode,
    PSImode,
    PDImode,
    QFmode,
    HFmode,
    TQFmode,
    SFmode,
    DFmode,
    XFmode,
    TFmode,
    QCmode,
    HCmode,
    SCmode,
    DCmode,
    XCmode,
    TCmode,
    CQImode,
    CHImode,
    CSImode,
    CDImode,
    CTImode,
    COImode,
    V2QImode,
    V2HImode,
    V2SImode,
    V2DImode,
    V4QImode,
    V4HImode,
    V4SImode,
    V4DImode,
    V8QImode,
    V8HImode,
    V8SImode,
    V8DImode,
    V16QImode,
    V2SFmode,
    V2DFmode,
    V4SFmode,
    V4DFmode,
    V8SFmode,
    V8DFmode,
    V16SFmode,
    BLKmode,
    CCmode,
    CCGCmode,
    CCGOCmode,
    CCNOmode,
    CCZmode,
    CCFPmode,
    CCFPUmode,
    MAX_MACHINE_MODE
};

struct value_data_entry {
    enum machine_mode mode;
    unsigned int oldest_regno;
    unsigned int next_regno;
};

struct value_data {
    struct value_data_entry e[53];
    unsigned int max_value_regs;
};

unsigned int regno = 0;
struct value_data *vd;
unsigned int i;

void init_vars() {
    vd = (struct value_data*)malloc(sizeof(struct value_data));
    if (!vd) return;

    vd->max_value_regs = 53;

    for (int idx = 0; idx < 53; idx++) {
        vd->e[idx].mode = QImode;
        vd->e[idx].oldest_regno = (idx + 1) % 53;
        vd->e[idx].next_regno = (idx + 1) % 53;
    }

    regno = 0;

    vd->e[regno].oldest_regno = 1;
    i = vd->e[regno].oldest_regno;

    int current = i;
    for (int step = 0; step < 50; step++) {
        vd->e[current].next_regno = (current + 1) % 53;
        current = (current + 1) % 53;
    }
    vd->e[current].next_regno = regno;
}