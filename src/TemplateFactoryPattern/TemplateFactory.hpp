#pragma once

#include <iostream>
#include <map>


/// <summary>
/// 产品注册类模板接口 
/// </summary>
/// <typeparam name="ProductType_t">模板参数 ProductType_t 表示的是基类</typeparam>
template<class ProductType_t>
class IProductRegistrar
{
public:
	// 获取产品对象抽象接口
	virtual ProductType_t* CreateProduct(const std::string& name) = 0;

protected:
	// 禁止外部构造和析构，子类的“内部”的其他函数可以调用
	IProductRegistrar() {}
	virtual ~IProductRegistrar() {}
};


/// <summary>
/// 工厂类模板
/// </summary>
/// <typeparam name="ProductType_t">模板参数 ProductType_t 表示的是基类</typeparam>
template<class ProductType_t>
class ProductFactory
{
public:
	// 获取工厂单例，工厂的实例是唯一的
	static ProductFactory<ProductType_t>& Instance()
	{
		// TODO: 在此处插入 return 语句

		static ProductFactory<ProductType_t> instance;
		return instance;
	}

	// 产品注册
	void RegisterProduct(const std::string& name, IProductRegistrar<ProductType_t>* registrar)
	{
		m_ProductRegistry[name] = registrar;
	}

	// 根据名字name，获取对应具体的产品对象
	ProductType_t* GetProduct(const std::string& name)
	{
		// 从map中获取已经注册过的产品，并返回产品对象
		if (m_ProductRegistry.find(name) != m_ProductRegistry.end())
		{
			return m_ProductRegistry[name]->CreateProduct(name);
		}
		return NULL;
	}

private:
	// 禁止外部构造和析构
	ProductFactory() {}
	~ProductFactory() {}

	// 禁止外部拷贝和赋值操作
	ProductFactory(const ProductFactory&);
	const ProductFactory& operator=(const ProductFactory&);

	// 保存注册过的产品
	std::map<std::string, IProductRegistrar<ProductType_t>*> m_ProductRegistry;
};




/// <summary>
/// 产品注册类模板
/// </summary>
/// <typeparam name="ProductType_t">模板参数 ProductType_t 表示的是基类</typeparam>
/// <typeparam name="ProductImpl_t">ProductImpl_t 表示的是派生类</typeparam>
template<class ProductType_t, class ProductImpl_t>
class ProductRegistrar :public IProductRegistrar<ProductType_t>
{
public:
	// 构造函数，只能显式调用
	explicit ProductRegistrar(const std::string& name)
	{
		// 注册从产品到工厂
		ProductFactory<ProductType_t>::Instance().RegisterProduct(name, this);
	}

	// 创建指向派生类对象的指针
	ProductType_t* CreateProduct(const std::string& name)
	{
		return new ProductImpl_t(name);
	}
};

