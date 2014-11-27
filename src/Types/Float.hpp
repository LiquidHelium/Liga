#pragma once

#include <llvm/IR/Type.h>
#include "LLVM.hpp"

#include "GenericValue.hpp"
#include "GenericType.hpp"
#include "Enviroment.hpp"
#include "Function.hpp"

class FloatType : public GenericType {
public:
	virtual DataType data_type() const { return DataType::Float; }
	virtual bool operator==(const GenericType &other) const {
		return other.data_type() == data_type();
	}
	virtual llvm::Type *llvm_type() const {
		return llvm::Type::getFloatTy(llvm::getGlobalContext());
	}
	virtual GenericValue create(llvm::Value *val) const {
		return GenericValue(std::make_shared<FloatType>(), val);
	}
};