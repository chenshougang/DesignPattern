// #pragma once

#ifndef PRODUCT_CONTEXT_H
#define PRODUCT_CONTEXT_H

#include "RoleOperation.h"

template <class ProductType_t>
class ProductContext
{
public:
	ProductContext(std::unique_ptr<ProductType_t> operation)
		:m_pOperation(std::move(operation)) {}

	std::string execute()
	{
		return m_pOperation->Op();
	}

private:
	// 禁止外部拷贝和赋值操作
	ProductContext(const ProductContext&) = delete;
	const ProductContext& operator=(const ProductContext&) = delete;

	// ProductType_t* m_pOperation;
	std::unique_ptr<ProductType_t> m_pOperation;

};

class JudgeRole
{
public:
	std::string Judge(std::unique_ptr<RoleOperation> pOperation)
	{
		ProductContext<RoleOperation> roleContext(std::move(pOperation));
		return roleContext.execute();
	}
};

#endif // !PRODUCT_CONTEXT_H

