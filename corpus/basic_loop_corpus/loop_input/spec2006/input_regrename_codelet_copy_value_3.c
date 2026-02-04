#include <stdio.h>
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

struct value_data *vd;
unsigned int sr;
unsigned int i;

void init_vars() {
    static struct value_data local_vd;
    vd = &local_vd;
    vd->max_value_regs = 53;

    for (int idx = 0; idx < 52; ++idx) {
        vd->e[idx].mode = QImode;
        vd->e[idx].oldest_regno = idx;
        vd->e[idx].next_regno = idx + 1;
    }
    vd->e[52].mode = QImode;
    vd->e[52].oldest_regno = 52;
    vd->e[52].next_regno = ~(unsigned int)0;

    sr = 0;
}