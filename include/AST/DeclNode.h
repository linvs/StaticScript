#pragma once

#include "AST/Node.h"
#include "AST/TypeNode.h"
#include "AST/StmtNode.h"
#include "AST/ExprNode.h"

enum class VarModifier {
    Let, Const, Param
};

/// 声明节点
class DeclNode : public Node {
public:
    ~DeclNode() override = default;
};

/// 变量声明节点
class VarDeclNode : public DeclNode {
public:
    explicit VarDeclNode();

    VarDeclNode(
            VarModifier modifier,
            String name,
            const SharedPtr<BuiltinTypeNode> &type
    );

    VarDeclNode(
            VarModifier modifier,
            String name,
            const SharedPtr<BuiltinTypeNode> &type,
            const SharedPtr<ExprNode> &initVal
    );

    ~VarDeclNode() override = default;

    void bindChildrenInversely() override;

    void accept(const SharedPtr<ASTVisitor> &visitor) override;

    bool isConstant() const;

    VarModifier modifier;
    String name;
    SharedPtr<BuiltinTypeNode> type = nullptr;
    SharedPtr<ExprNode> initVal = nullptr;

    // 当前变量声明的alloca/load ir
    LLVMValue *code = nullptr;
};

/// 函数参数声明节点
class ParmVarDeclNode : public VarDeclNode {
public:
    ParmVarDeclNode(const String &name, const SharedPtr<BuiltinTypeNode> &type);

    ~ParmVarDeclNode() override = default;

    void accept(const SharedPtr<ASTVisitor> &visitor) override;
};

/// 函数声明节点
class FunctionDeclNode : public DeclNode {
public:
    static SharedPtrMap<String, FunctionDeclNode> getBuiltinFunctions();

    FunctionDeclNode(
            String name,
            const SharedPtrVector<ParmVarDeclNode> &params,
            const SharedPtr<BuiltinTypeNode> &returnType,
            const SharedPtr<CompoundStmtNode> &body
    );

    ~FunctionDeclNode() override = default;

    void bindChildrenInversely() override;

    void accept(const SharedPtr<ASTVisitor> &visitor) override;

    String name;
    SharedPtrVector<ParmVarDeclNode> params;
    SharedPtr<BuiltinTypeNode> returnType = nullptr;
    SharedPtr<CompoundStmtNode> body = nullptr;

    SharedPtr<Scope> internalScope = nullptr;
    SharedPtr<ReturnStmtNode> refReturnStmt;
};
