#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum rtx_code {
    UNKNOWN,
    NIL,
    INCLUDE,
    EXPR_LIST,
    INSN_LIST,
    MATCH_OPERAND,
    MATCH_SCRATCH,
    MATCH_DUP,
    MATCH_OPERATOR,
    MATCH_PARALLEL,
    MATCH_OP_DUP,
    MATCH_PAR_DUP,
    MATCH_INSN,
    DEFINE_INSN,
    DEFINE_PEEPHOLE,
    DEFINE_SPLIT,
    DEFINE_INSN_AND_SPLIT,
    DEFINE_PEEPHOLE2,
    DEFINE_COMBINE,
    DEFINE_EXPAND,
    DEFINE_DELAY,
    DEFINE_FUNCTION_UNIT,
    DEFINE_ASM_ATTRIBUTES,
    DEFINE_COND_EXEC,
    SEQUENCE,
    ADDRESS,
    DEFINE_ATTR,
    ATTR,
    SET_ATTR,
    SET_ATTR_ALTERNATIVE,
    EQ_ATTR,
    ATTR_FLAG,
    INSN,
    JUMP_INSN,
    CALL_INSN,
    BARRIER,
    CODE_LABEL,
    NOTE,
    COND_EXEC,
    PARALLEL,
    ASM_INPUT,
    ASM_OPERANDS,
    UNSPEC,
    UNSPEC_VOLATILE,
    ADDR_VEC,
    ADDR_DIFF_VEC,
    PREFETCH,
    SET,
    USE,
    CLOBBER,
    CALL,
    RETURN,
    TRAP_IF,
    RESX,
    CONST_INT,
    CONST_DOUBLE,
    CONST_VECTOR,
    CONST_STRING,
    CONST,
    PC,
    VALUE,
    REG,
    SCRATCH,
    SUBREG,
    STRICT_LOW_PART,
    CONCAT,
    MEM,
    LABEL_REF,
    SYMBOL_REF,
    CC0,
    ADDRESSOF,
    QUEUED,
    IF_THEN_ELSE,
    COND,
    COMPARE,
    PLUS,
    MINUS,
    NEG,
    MULT,
    DIV,
    MOD,
    UDIV,
    UMOD,
    AND,
    IOR,
    XOR,
    NOT,
    ASHIFT,
    ROTATE,
    ASHIFTRT,
    LSHIFTRT,
    ROTATERT,
    SMIN,
    SMAX,
    UMIN,
    UMAX,
    PRE_DEC,
    PRE_INC,
    POST_DEC,
    POST_INC,
    PRE_MODIFY,
    POST_MODIFY,
    NE,
    EQ,
    GE,
    GT,
    LE,
    LT,
    GEU,
    GTU,
    LEU,
    LTU,
    UNORDERED,
    ORDERED,
    UNEQ,
    UNGE,
    UNGT,
    UNLE,
    UNLT,
    LTGT,
    SIGN_EXTEND,
    ZERO_EXTEND,
    TRUNCATE,
    FLOAT_EXTEND,
    FLOAT_TRUNCATE,
    FLOAT,
    FIX,
    UNSIGNED_FLOAT,
    UNSIGNED_FIX,
    ABS,
    SQRT,
    FFS,
    SIGN_EXTRACT,
    ZERO_EXTRACT,
    HIGH,
    LO_SUM,
    RANGE_INFO,
    RANGE_REG,
    RANGE_VAR,
    RANGE_LIVE,
    CONSTANT_P_RTX,
    CALL_PLACEHOLDER,
    VEC_MERGE,
    VEC_SELECT,
    VEC_CONCAT,
    VEC_DUPLICATE,
    SS_PLUS,
    US_PLUS,
    SS_MINUS,
    US_MINUS,
    SS_TRUNCATE,
    US_TRUNCATE,
    PHI,
    LAST_AND_UNUSED_RTX_CODE
};

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

typedef struct rtx_def *rtx;

struct rtvec_def {
    int num_elem;
    rtx elem[1];
};

typedef struct rtvec_def *rtvec;

typedef struct {
    unsigned int min_align : 8;
    unsigned int base_after_vec : 1;
    unsigned int min_after_vec : 1;
    unsigned int max_after_vec : 1;
    unsigned int min_after_base : 1;
    unsigned int max_after_base : 1;
    unsigned int offset_unsigned : 1;
    unsigned int : 2;
    unsigned int scale : 8;
} addr_diff_vec_flags;

typedef union tree_node *tree;

typedef struct {
    long alias;
    tree expr;
    rtx offset;
    rtx size;
    unsigned int align;
} mem_attrs;

typedef union rtunion_def {
    long rtwint;
    int rtint;
    unsigned int rtuint;
    const char *rtstr;
    rtx rtx;
    rtvec rtvec;
    enum machine_mode rttype;
    addr_diff_vec_flags rt_addr_diff_vec_flags;
    struct cselib_val_struct *rt_cselib;
    struct bitmap_head_def *rtbit;
    tree rttree;
    struct basic_block_def *bb;
    mem_attrs *rtmem;
} rtunion;

struct rtx_def {
    enum rtx_code code : 16;
    enum machine_mode mode : 8;
    unsigned int jump : 1;
    unsigned int call : 1;
    unsigned int unchanging : 1;
    unsigned int volatil : 1;
    unsigned int in_struct : 1;
    unsigned int used : 1;
    unsigned int integrated : 1;
    unsigned int frame_related : 1;
    rtunion fld[1];
};

int i;
rtx pat;
int len;
int has_use_labelref;

static struct rtx_def **inner_rtx_array;
static struct rtvec_def *vec_container;
static struct rtx_def *label_ref_rtx;
static struct rtx_def *use_rtx_template;

void init_vars() {
    const int target_size_mb = 64;
    len = (target_size_mb * 1024 * 1024) / sizeof(struct rtx_def *);
    if (len < 1) len = 1;

    inner_rtx_array = (struct rtx_def **)calloc(len, sizeof(struct rtx_def *));
    if (!inner_rtx_array) exit(1);

    vec_container = (struct rtvec_def *)malloc(sizeof(struct rtvec_def) + (len - 1) * sizeof(rtx));
    if (!vec_container) exit(1);
    vec_container->num_elem = len;

    label_ref_rtx = (struct rtx_def *)calloc(1, sizeof(struct rtx_def));
    if (!label_ref_rtx) exit(1);
    label_ref_rtx->code = LABEL_REF;
    label_ref_rtx->mode = SImode;

    use_rtx_template = (struct rtx_def *)calloc(1, sizeof(struct rtx_def));
    if (!use_rtx_template) exit(1);
    use_rtx_template->code = USE;
    use_rtx_template->mode = VOIDmode;

    for (int idx = 0; idx < len; idx++) {
        struct rtx_def *use_rtx = (struct rtx_def *)calloc(1, sizeof(struct rtx_def));
        if (!use_rtx) exit(1);
        use_rtx->code = USE;
        use_rtx->mode = VOIDmode;
        use_rtx->fld[0].rtx = label_ref_rtx;
        vec_container->elem[idx] = use_rtx;
    }

    pat = (struct rtx_def *)calloc(1, sizeof(struct rtx_def));
    if (!pat) exit(1);
    pat->code = PARALLEL;
    pat->mode = VOIDmode;
    pat->fld[0].rtvec = vec_container;

    has_use_labelref = 0;
    i = 0;
}