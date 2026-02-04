#include <stdio.h>

#include <inttypes.h>

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


struct expr_status {
    int x_pending_stack_adjust;
    int x_inhibit_defer_pop;
    int x_stack_pointer_delta;
    rtx x_saveregs_value;
    rtx x_apply_args_value;
    rtx x_forced_labels;
    rtx x_pending_chain;
};


struct sequence_stack {
    rtx first;
    rtx last;
    tree sequence_rtl_expr;
    struct sequence_stack *next;
};


struct emit_status {
    int x_reg_rtx_no;
    int x_first_label_num;
    rtx x_first_insn;
    rtx x_last_insn;
    tree sequence_rtl_expr;
    struct sequence_stack *sequence_stack;
    int x_cur_insn_uid;
    int x_last_linenum;
    const char *x_last_filename;
    int regno_pointer_align_length;
    unsigned char *regno_pointer_align;
    tree *regno_decl;
    rtx *x_regno_reg_rtx;
};


typedef struct ix86_args {
    int words;
    int nregs;
    int regno;
    int sse_words;
    int sse_nregs;
    int sse_regno;
    int maybe_vaarg;
} CUMULATIVE_ARGS;

struct var_refs_queue {
    rtx modified;
    enum machine_mode promoted_mode;
    int unsignedp;
    struct var_refs_queue *next;
};


struct function {
    struct eh_status *eh;
    struct stmt_status *stmt;
    struct expr_status *expr;
    struct emit_status *emit;
    struct varasm_status *varasm;
    const char *name;
    tree decl;
    struct function *outer;
    int pops_args;
    int args_size;
    int pretend_args_size;
    int outgoing_args_size;
    rtx arg_offset_rtx;
    CUMULATIVE_ARGS args_info;
    rtx return_rtx;
    rtx internal_arg_pointer;
    const char *cannot_inline;
    struct initial_value_struct *hard_reg_initial_vals;
    int x_function_call_count;
    tree x_nonlocal_labels;
    rtx x_nonlocal_goto_handler_slots;
    rtx x_nonlocal_goto_handler_labels;
    rtx x_nonlocal_goto_stack_level;
    rtx x_cleanup_label;
    rtx x_return_label;
    rtx x_save_expr_regs;
    rtx x_stack_slot_list;
    tree x_rtl_expr_chain;
    rtx x_tail_recursion_label;
    rtx x_tail_recursion_reentry;
    rtx x_arg_pointer_save_area;
    rtx x_clobber_return_insn;
    long x_frame_offset;
    tree x_context_display;
    tree x_trampoline_list;
    rtx x_parm_birth_insn;
    rtx x_last_parm_insn;
    unsigned int x_max_parm_reg;
    rtx *x_parm_reg_stack_loc;
    struct temp_slot *x_temp_slots;
    int x_temp_slot_level;
    int x_var_temp_slot_level;
    int x_target_temp_slot_level;
    struct var_refs_queue *fixup_var_refs_queue;
    int inlinable;
    int no_debugging_symbols;
    void *original_arg_vector;
    tree original_decl_initial;
    rtx inl_last_parm_insn;
    int inl_max_label_num;
    int profile_label_no;
    struct machine_function *machine;
    int stack_alignment_needed;
    int preferred_stack_boundary;
    struct language_function *language;
    rtx epilogue_delay_list;
    unsigned int returns_struct : 1;
    unsigned int returns_pcc_struct : 1;
    unsigned int returns_pointer : 1;
    unsigned int needs_context : 1;
    unsigned int calls_setjmp : 1;
    unsigned int calls_longjmp : 1;
    unsigned int calls_alloca : 1;
    unsigned int calls_eh_return : 1;
    unsigned int has_nonlocal_label : 1;
    unsigned int has_nonlocal_goto : 1;
    unsigned int contains_functions : 1;
    unsigned int has_computed_jump : 1;
    unsigned int is_thunk : 1;
    unsigned int instrument_entry_exit : 1;
    unsigned int profile : 1;
    unsigned int limit_stack : 1;
    unsigned int varargs : 1;
    unsigned int stdarg : 1;
    unsigned int x_whole_function_mode_p : 1;
    unsigned int x_dont_save_pending_sizes_p : 1;
    unsigned int uses_const_pool : 1;
    unsigned int uses_pic_offset_table : 1;
    unsigned int uses_eh_lsda : 1;
    unsigned int arg_pointer_save_area_init : 1;
};


extern struct function *cfun;
extern rtx insn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (insn = (cfun->expr->x_forced_labels); insn; insn = (((insn)->fld[1]).rtx)) {
        rtx label_rtx = ((insn)->fld[0]).rtx;
        if (((enum rtx_code)(label_rtx->code) == CODE_LABEL)) {
            (label_rtx->fld[3].rtint)++;
        } else {
            goto next_iteration;
        }
next_iteration:;
    }
}
