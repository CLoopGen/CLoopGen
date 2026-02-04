#include <string>
#include <sstream>
#include <set>
#include <vector>

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Lex/Lexer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/Stmt.h"

using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;


static const std::set<std::string> RESERVED_NAMES = {
    "index", "rindex", "bcopy", "bzero", "bcmp",
    "y0", "y1", "yn", "j0", "j1", "jn"
};

static std::string getSafeVarName(const std::string& name) {
    if (RESERVED_NAMES.count(name)) {
        return "_usr_" + name;
    }
    return name;
}

void removeStatic(std::string& str) {
    const std::string target = "static";
    size_t pos = 0;
    while ((pos = str.find(target, pos)) != std::string::npos) {
        str.erase(pos, target.length());
    }
}

void removeConst(std::string& str) {
    const std::string target = "const";
    size_t pos = 0;
    while ((pos = str.find(target, pos)) != std::string::npos) {
        str.erase(pos, target.length());
    }
}

static bool hasFunctionCall(const clang::Stmt *S) {
    if (!S) return false;

    struct CallExprFinder : public clang::RecursiveASTVisitor<CallExprFinder> {
        bool Found = false;
        bool VisitCallExpr(const clang::CallExpr *CE) {
            Found = true;
            return false; 
        }
    };

    CallExprFinder Finder;
    Finder.TraverseStmt(const_cast<clang::Stmt*>(S)); 
    return Finder.Found;
}

class LoopExtractor : public MatchFinder::MatchCallback {
public:
    explicit LoopExtractor(Rewriter &R, std::string s) : TheRewriter(R), outFileName(s), Counter(0) {}
    void run(const MatchFinder::MatchResult &Result) override {
        AddedDeclarations.clear();
        const ForStmt *FS = Result.Nodes.getNodeAs<ForStmt>("forLoop");
        if (!FS) return;

        if (hasFunctionCall(FS->getInit()) ||
            hasFunctionCall(FS->getCond()) ||
            hasFunctionCall(FS->getInc()) ||
            hasFunctionCall(FS->getBody())) {
            return; 
        }


        ASTContext *Ctx = Result.Context;
        if (!Ctx) return;

        SourceManager &SM = Ctx->getSourceManager();
        SourceLocation beginLoc = FS->getBeginLoc();
        if (beginLoc.isInvalid() || SM.isInSystemHeader(beginLoc)) return;

        std::string funcName = "anon";
        const Stmt *Cur = FS;
        while (Cur) {
            auto parents = Result.Context->getParents(*Cur);
            if (parents.empty()) break;

            Cur = parents[0].get<Stmt>();
            if (!Cur) {
                if (const auto *FD = parents[0].get<FunctionDecl>()) {
                    if (FD->getIdentifier())
                        funcName = FD->getNameAsString();
                    break;
                }
            }
        }

        std::set<std::string> LocalNames;
        collectLocalVarsFromFor(FS, *Ctx, LocalNames);

        std::set<const VarDecl*> ExternalVarDecls;
        collectReferencedVars(FS, *Ctx, LocalNames, ExternalVarDecls);

        std::set<const Decl*> TypeDecls; 
        std::vector<const Decl*> TypeDeclsOrdered; 

        std::set<const VarDecl*> UsedVars;
        collectUsedVars(FS, UsedVars, *Ctx);

        for (auto *VD : UsedVars) {
            collectTypeDeclsForVar(VD->getType(), *Ctx, TypeDecls, TypeDeclsOrdered);
        }

        collectCStyleCastTypes(FS, *Ctx, TypeDecls, TypeDeclsOrdered);
        std::vector<std::string> TypeTexts;

        for (auto *D : TypeDeclsOrdered) {
            if (const auto *RD = dyn_cast<RecordDecl>(D)) {
                bool isInlineInTypedef = false;
                SourceManager &SM = Ctx->getSourceManager();
                
                for (auto *OtherD : TypeDecls) {
                    if (const auto *TD = dyn_cast<TypedefNameDecl>(OtherD)) {
                        if (TD->getUnderlyingType()->getAsTagDecl() == RD) {
                            SourceLocation TDBegin = TD->getBeginLoc();
                            SourceLocation TDEnd = TD->getEndLoc();
                            SourceLocation RDBegin = RD->getBeginLoc();
                            SourceLocation RDEnd = RD->getEndLoc();

                            bool beginBefore = SM.isBeforeInTranslationUnit(TDBegin, RDBegin) || TDBegin == RDBegin;
                            bool endAfter = SM.isBeforeInTranslationUnit(RDEnd, TDEnd) || RDEnd == TDEnd;

                            if (beginBefore && endAfter) {
                                isInlineInTypedef = true;
                                break;
                            }
                        }
                    }
                }
                if (isInlineInTypedef) {
                    continue; 
                }
            }

            if (const auto *RD = dyn_cast<RecordDecl>(D)) {

                const RecordDecl *Def = RD->getDefinition();
                if (!Def) Def = RD;
                if (!RD->getIdentifier() && isTypedefedUnderlyingDecl(RD, *Ctx)) {
                    continue;
                }

                if (Def && Def->isCompleteDefinition()) {
                    maybeAddDeclText(Def, *Ctx, TypeTexts);
                }
                continue;
            }

            else if (const auto *ED = dyn_cast<EnumDecl>(D)) {

                if (!ED->getIdentifier() && isTypedefedUnderlyingDecl(ED, *Ctx))
                    continue;

                const EnumDecl *Def = ED->getDefinition();
                if (Def && Def->isCompleteDefinition()) {
                    maybeAddDeclText(Def, *Ctx, TypeTexts);
                }  
                continue;
            }

            if (const auto *TD = dyn_cast<TypedefNameDecl>(D)) {
                maybeAddDeclText(TD, *Ctx, TypeTexts);
                continue;
            }

            else {
                maybeAddDeclText(D, *Ctx, TypeTexts);
            }
        }

        for (auto &TT : TypeTexts) {
            std::string trimmed = llvm::StringRef(TT).trim().str();
            if (!trimmed.empty() && trimmed.find("typedef") == 0) {
                if (trimmed.back() != ';') {
                    TT += ";";
                }
            }
        }


        std::vector<std::string> VarDeclTexts;



        for (auto *VD : ExternalVarDecls) {
            if (!VD) continue;
            
            std::string varName = VD->getNameAsString();
            std::string safeVarName = getSafeVarName(varName);  
            
            std::string dec;
            llvm::raw_string_ostream os(dec);
            PrintingPolicy PP(Ctx->getLangOpts());
            PP.SuppressInitializers = true;
            VD->print(os, PP, 0);
            os.flush();
            
            if (varName != safeVarName) {
                size_t pos = dec.find(" " + varName);
                if (pos != std::string::npos) {
                    dec.replace(pos + 1, varName.length(), safeVarName);
                }
                pos = dec.find(varName + "[");
                if (pos != std::string::npos) {
                    dec.replace(pos, varName.length(), safeVarName);
                }
                pos = dec.find("*" + varName);
                if (pos != std::string::npos) {
                    dec.replace(pos + 1, varName.length(), safeVarName);
                }
            }
            
            size_t staticPos = dec.find("static ");
            if (staticPos != std::string::npos) {
                dec.replace(staticPos, 7, "");
            }
            size_t regPos = dec.find("register ");
            if (regPos != std::string::npos) {
                dec.replace(regPos, 9, "");
            }
            
            dec += ";";
            VarDeclTexts.push_back(dec);
        }

        std::string LoopText = getPrintedStmt(FS, *Ctx);
        if (LoopText.empty()) {
            llvm::errs() << "Warning: empty loop source for extraction.\n";
            return;
        }

        std::ostringstream fname;
        sanitizeFuncName(funcName);
        fname << outFileName << "_codelet_" << funcName << "_" << Counter++ << ".c";
        std::error_code EC;
        llvm::raw_fd_ostream OS(fname.str(), EC, llvm::sys::fs::OF_Text);
        if (EC) {
            llvm::errs() << "Cannot open codelet file: " << EC.message() << "\n";
            return;
        }

        OS << "#include <stdio.h>\n\n";
        OS << "#include <inttypes.h>\n\n";
        OS << "#include <stdlib.h>\n";
        OS << "#include <stddef.h>\n";

        for (auto &t : TypeTexts) {
            OS << t << "\n\n";
        }

        for (auto &vd : VarDeclTexts) {
            if (vd.find("extern") != std::string::npos) {
                OS << vd << "\n";
            } else {
                removeStatic(vd);
                removeConst(vd);
                OS << "extern " << vd << "\n";
            }
        }

        // OS << "\n// Variable name mappings to avoid conflicts with system symbols\n";
        for (auto *VD : ExternalVarDecls) {
            if (!VD) continue;
            std::string varName = VD->getNameAsString();
            std::string safeVarName = getSafeVarName(varName);
            if (varName != safeVarName) {
                OS << "#define " << varName << " " << safeVarName << "\n";
            }
        }
        OS << "\n";
        
        OS << "void loop(){\n";
        OS << LoopText << "\n}\n";
        OS.close();
        llvm::outs() << "- Wrote codelet: " << fname.str() << "\n";
    }

    static void registerMatcher(MatchFinder &Finder, LoopExtractor &Handler) {
        Finder.addMatcher(
            forStmt(
                unless(hasAncestor(forStmt())),   
                unless(hasDescendant(callExpr()))  
            ).bind("forLoop"), 
            &Handler);
    }

private:
    Rewriter &TheRewriter;
    std::string outFileName;
    unsigned Counter;
    std::set<std::string> AddedDeclarations;

    std::string getPrintedStmt(const Stmt *S, ASTContext &Ctx) {
        std::string out;
        llvm::raw_string_ostream os(out);

        PrintingPolicy PP(Ctx.getLangOpts());
        PP.SuppressUnwrittenScope = true;
        PP.Bool = true;
        

        S->printPretty(os, nullptr, PP);
        os.flush();
        return out;
    }

    std::string getSourceTextForNode(const Stmt *S, ASTContext &Ctx) {
        if (!S) return "";
        SourceManager &SM = Ctx.getSourceManager();
        LangOptions LO = Ctx.getLangOpts();
        CharSourceRange R = CharSourceRange::getTokenRange(S->getSourceRange());
        if (R.isValid()) {
            bool invalid = false;
            StringRef txt = Lexer::getSourceText(R, SM, LO, &invalid);
            if (!invalid) return txt.str();
        }
        std::string out;
        llvm::raw_string_ostream ros(out);
        S->printPretty(ros, nullptr, PrintingPolicy(LO));
        return ros.str();
    }

    void collectLocalVarsFromFor(const ForStmt *FS, ASTContext &Ctx, std::set<std::string> &LocalNames) {
        if (!FS) return;
        if (const Stmt *Init = FS->getInit()) {
            collectLocalVarDecls(Init, LocalNames, Ctx);
        }
        if (const Stmt *Body = FS->getBody()) {
            collectLocalVarDecls(Body, LocalNames, Ctx);
        }
        if (const Stmt *Inc = FS->getInc()) {
            collectLocalVarDecls(Inc, LocalNames, Ctx);
        }
    }

    void collectLocalVarDecls(const Stmt *S, std::set<std::string> &Out, ASTContext &Ctx) {
        if (!S) return;
        if (const DeclStmt *DS = dyn_cast<DeclStmt>(S)) {
            for (auto it = DS->decl_begin(); it != DS->decl_end(); ++it) {
                if (const VarDecl *VD = dyn_cast<VarDecl>(*it)) {
                    Out.insert(VD->getNameAsString());
                }
            }
        }
        for (const Stmt *Child : S->children()) {
            collectLocalVarDecls(Child, Out, Ctx);
        }
    }

    void collectUsedVars(const Stmt *S,
                     std::set<const VarDecl*> &UsedVars,
                     ASTContext &Ctx) {
    if (!S) return;

    class UsedVarVisitor : public RecursiveASTVisitor<UsedVarVisitor> {
        public:
            std::set<const VarDecl*> &Vars;
            ASTContext &Ctx;
            UsedVarVisitor(std::set<const VarDecl*> &V, ASTContext &C)
                : Vars(V), Ctx(C) {}

            bool VisitDeclRefExpr(DeclRefExpr *DRE) {
                if (const VarDecl *VD = dyn_cast<VarDecl>(DRE->getDecl())) {
                    Vars.insert(VD->getCanonicalDecl());
                }
                return true;
            }
        } Visitor(UsedVars, Ctx);

        Visitor.TraverseStmt(const_cast<Stmt*>(S));
    }

    void collectReferencedVars(const ForStmt *FS, ASTContext &Ctx,
                               const std::set<std::string> &LocalNames,
                               std::set<const VarDecl*> &OutVars) {
        if (!FS) return;
        class RefVisitor : public RecursiveASTVisitor<RefVisitor> {
        public:
            RefVisitor(const std::set<std::string> &LocalNames, ASTContext &Ctx,
                       std::set<const VarDecl*> &OutVars)
                : LocalNames(LocalNames), Ctx(Ctx), OutVars(OutVars) {}
            bool VisitDeclRefExpr(DeclRefExpr *DRE) {
                if (const VarDecl *VD = dyn_cast<VarDecl>(DRE->getDecl())) {
                    std::string name = VD->getNameAsString();
                    if (LocalNames.count(name)) return true;
                    if (VD->isImplicit()) return true;
                    OutVars.insert(VD->getCanonicalDecl());
                }
                return true;
            }
        private:
            const std::set<std::string> &LocalNames;
            ASTContext &Ctx;
            std::set<const VarDecl*> &OutVars;
        };

        RefVisitor V(LocalNames, Ctx, OutVars);
        if (const Stmt *Init = FS->getInit()) V.TraverseStmt(const_cast<Stmt*>(Init));
        if (const Expr *Cond = FS->getCond()) V.TraverseStmt(const_cast<Expr*>(Cond));
        if (const Expr *Inc = FS->getInc()) V.TraverseStmt(const_cast<Expr*>(Inc));
        if (const Stmt *Body = FS->getBody()) V.TraverseStmt(const_cast<Stmt*>(Body));
    }

    void collectTypeDeclsForVar(QualType QT, ASTContext &Ctx, std::set<const Decl*> &Out, std::vector<const Decl*> &OutOrdered) {
        if (QT.isNull()) return;

        if (const TypedefType *TT = QT->getAs<TypedefType>()) {
            if (const TypedefNameDecl *TD = TT->getDecl()) {
                const Decl *canon = TD->getCanonicalDecl();
                if (!Out.count(canon)) {
                    collectTypeDeclsForVar(TD->getUnderlyingType(), Ctx, Out, OutOrdered);
                    Out.insert(canon);
                    OutOrdered.push_back(canon);
                }
            }
            return;
        }

        if (const RecordType *RT = QT->getAs<RecordType>()) {
            if (RecordDecl *RD = RT->getDecl()) {
                const Decl *canon = RD->getCanonicalDecl();
                if (!Out.count(canon)) {
                    Out.insert(canon);
                    if (RecordDecl *Def = RD->getDefinition()) {
                        for (auto *F : Def->fields()) {
                            collectTypeDeclsForVar(F->getType(), Ctx, Out, OutOrdered);
                        }
                    }
                    Out.insert(canon);
                    OutOrdered.push_back(canon);
                }
            }
            return;
        }

        if (const EnumType *ET = QT->getAs<EnumType>()) {
            if (EnumDecl *ED = ET->getDecl()) {
                const Decl *canon = ED->getCanonicalDecl();
                if (!Out.count(canon)) {
                    Out.insert(canon);
                    OutOrdered.push_back(canon);
                }
            }
            return;
        }

        if (const PointerType *PT = QT->getAs<PointerType>()) {
            collectTypeDeclsForVar(PT->getPointeeType(), Ctx, Out, OutOrdered);
            return;
        }

        if (const ArrayType *AT = dyn_cast<ArrayType>(QT.getTypePtr())) {
            collectTypeDeclsForVar(AT->getElementType(), Ctx, Out, OutOrdered);
            return;
        }
    }

    void collectTypeDefAndRecord(ASTContext *Ctx, QualType QT,
                             std::set<std::string> &TypeDecls) {
        const Type *T = QT.getTypePtr();

        if (auto *TT = dyn_cast<TypedefType>(T)) {
            TypedefNameDecl *TD = TT->getDecl();
            if (!TD) return;

            SourceManager &SM = Ctx->getSourceManager();
            SourceRange SR = TD->getSourceRange();

            std::string Code = Lexer::getSourceText(
                CharSourceRange::getTokenRange(SR),
                SM, Ctx->getLangOpts()).str();

            TypeDecls.insert(Code + ";");
            return;
        }

        if (auto *RT = dyn_cast<RecordType>(T)) {
            RecordDecl *RD = RT->getDecl();
            if (!RD || !RD->isCompleteDefinition()) return;

            SourceManager &SM = Ctx->getSourceManager();
            SourceRange SR = RD->getSourceRange();

            std::string Code = Lexer::getSourceText(
                CharSourceRange::getTokenRange(SR),
                SM, Ctx->getLangOpts()).str();

            TypeDecls.insert(Code + ";");
        }
    }

    static bool isTypedefedUnderlyingDecl(const TagDecl *TD, ASTContext &Ctx) {
        if (!TD) return false;
        const TranslationUnitDecl *TU = Ctx.getTranslationUnitDecl();
        for (auto *D : TU->decls()) {
            if (const TypedefNameDecl *TDef = dyn_cast<TypedefNameDecl>(D)) {
                QualType Underlying = TDef->getUnderlyingType().getCanonicalType();
                if (const TagType *TT = Underlying->getAs<TagType>()) {
                    if (TT->getDecl()->getCanonicalDecl() == TD->getCanonicalDecl()) {
                        return true; 
                    }
                }
            }
        }
        return false;
    }

    void collectCStyleCastTypes(const Stmt *S, ASTContext &Ctx, std::set<const Decl*> &Out, std::vector<const Decl*> &OutOrdered) {
        if (!S) return;
        class CastVisitor : public RecursiveASTVisitor<CastVisitor> {
        public:
            ASTContext &Ctx;
            std::set<const Decl*> &Out;
            std::vector<const Decl*> &OutOrdered;
            LoopExtractor *Parent;
            CastVisitor(ASTContext &Ctx, std::set<const Decl*> &Out, std::vector<const Decl*> &OutOrdered, LoopExtractor *Parent)
                : Ctx(Ctx), Out(Out), OutOrdered(OutOrdered), Parent(Parent) {}

            bool VisitCStyleCastExpr(CStyleCastExpr *C) {
                QualType targetType = C->getTypeAsWritten();
                Parent->collectTypeDeclsForVar(targetType, Ctx, Out, OutOrdered);
                return true;
            }
        } visitor(Ctx, Out, OutOrdered, this);

        visitor.TraverseStmt(const_cast<Stmt*>(S));
    }

    void maybeAddDeclText(const Decl *D, ASTContext &Ctx, std::vector<std::string> &OutTexts) {
        if (!D) return;
        
        const SourceManager &SM = Ctx.getSourceManager();
        if (D->getLocation().isValid() && SM.isInSystemHeader(D->getLocation())) {
            return;
        }
        
        const Decl *CanonicalD = D->getCanonicalDecl();
        if (!CanonicalD) CanonicalD = D;
        
        std::string declText;
        LangOptions LO = Ctx.getLangOpts();

        if (isa<RecordDecl>(D) || isa<EnumDecl>(D) || isa<TypedefNameDecl>(D)) {
            llvm::raw_string_ostream ros(declText);
            PrintingPolicy PP(LO);
            PP.adjustForCPlusPlus();
            PP.Bool = true;
            PP.SuppressTagKeyword = false;
            PP.SuppressScope = false;
            PP.SuppressUnwrittenScope = true;
            PP.IncludeTagDefinition = true;

            if (const RecordDecl *RD = dyn_cast<RecordDecl>(D)) {
                RD->print(ros, PP);
            } else if (const EnumDecl *ED = dyn_cast<EnumDecl>(D)) {
                ED->print(ros, PP);
            } else if (const TypedefNameDecl *TD = dyn_cast<TypedefNameDecl>(D)) {
                TD->print(ros, PP);
            }
            ros.flush();
        } 
        else {

            llvm::raw_string_ostream ros(declText);
            PrintingPolicy PP(LO);
            PP.SuppressInitializers = true; 
            
            D->print(ros, PP);
            ros.flush();
            
            std::string::size_type pos = declText.find("static ");
            if (pos != std::string::npos) {
                declText.replace(pos, 7, ""); 
            }
            
        }
    
        std::string Trimmed = llvm::StringRef(declText).trim().str();
        if (Trimmed.empty()) return;
        
        while (!Trimmed.empty() && isspace(Trimmed.back()))
            Trimmed.pop_back();

        if (isa<RecordDecl>(D) || isa<EnumDecl>(D) || isa<TypedefNameDecl>(D)) {
            if (!Trimmed.empty() && Trimmed.back() == '}') {
                if (Trimmed.size() < 2 || Trimmed.substr(Trimmed.size() - 2) != "};") {
                    Trimmed += ";\n";
                }
            }
        }
        
        if (AddedDeclarations.count(Trimmed) == 0) {
            OutTexts.push_back(Trimmed);
            AddedDeclarations.insert(Trimmed);
        }
    }

    void sanitizeFuncName(std::string &s) {
        for (char &c : s) if (!isalnum((unsigned char)c)) c = '_';
        if (s.empty()) s = "anon";
    }
};




class InstrumentFrontendAction : public ASTFrontendAction {
public:
    explicit InstrumentFrontendAction(std::string OutFile = "")
        : OutFilename(std::move(OutFile)) {}

    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef) override {
        TheRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());

        auto &F = CI.getASTContext();

        LoopExtractor::registerMatcher(Finder, LE);

        return Finder.newASTConsumer();
    }

private:
    std::string OutFilename;
    Rewriter TheRewriter;

    LoopExtractor LE{TheRewriter, OutFilename};

    MatchFinder Finder;
};


int main(int argc, const char **argv) {
    llvm::cl::OptionCategory Category("loop codelet extractor options");

    llvm::cl::opt<std::string> OutputFile(
        "out",
        llvm::cl::desc("Output file name"),
        llvm::cl::value_desc("filename"),
        llvm::cl::init("")
    );

    auto ExpectedParser = CommonOptionsParser::create(argc, argv, Category);
    if (!ExpectedParser) {
        llvm::errs() << llvm::toString(ExpectedParser.takeError()) << "\n";
        return 1;
    }
    CommonOptionsParser &OP = ExpectedParser.get();

    ClangTool Tool(OP.getCompilations(), OP.getSourcePathList());

    class MyFactory : public FrontendActionFactory {
    public:
        MyFactory(std::string OF) : Out(OF) {}
        std::unique_ptr<FrontendAction> create() override {
            return std::make_unique<InstrumentFrontendAction>(Out);
        }
    private:
        std::string Out;
    };

    MyFactory Factory(OutputFile.getValue());
    return Tool.run(&Factory);
}

