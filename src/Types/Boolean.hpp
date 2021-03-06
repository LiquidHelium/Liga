#pragma once
#include "LLVM.hpp"

#include "GenericValue.hpp"
#include "GenericType.hpp"
#include "ASTNode.hpp"

class BooleanType : public GenericType {
public:
  virtual DataType data_type() const;
  virtual bool operator==(const GenericType &other) const;
  virtual llvm::Type *llvm_type() const;
  virtual GenericValue create(llvm::Value *val) const;
  virtual ASTPtr create_ast(llvm::GenericValue gv) const;
};