#pragma once

#include <iostream>
#include <map>


/// <summary>
/// ��Ʒע����ģ��ӿ� 
/// </summary>
/// <typeparam name="ProductType_t">ģ����� ProductType_t ��ʾ���ǻ���</typeparam>
template<class ProductType_t>
class IProductRegistrar
{
public:
	// ��ȡ��Ʒ�������ӿ�
	virtual ProductType_t* CreateProduct(const std::string& name) = 0;

protected:
	// ��ֹ�ⲿ���������������ġ��ڲ����������������Ե���
	IProductRegistrar() {}
	virtual ~IProductRegistrar() {}
};


/// <summary>
/// ������ģ��
/// </summary>
/// <typeparam name="ProductType_t">ģ����� ProductType_t ��ʾ���ǻ���</typeparam>
template<class ProductType_t>
class ProductFactory
{
public:
	// ��ȡ����������������ʵ����Ψһ��
	static ProductFactory<ProductType_t>& Instance()
	{
		// TODO: �ڴ˴����� return ���

		static ProductFactory<ProductType_t> instance;
		return instance;
	}

	// ��Ʒע��
	void RegisterProduct(const std::string& name, IProductRegistrar<ProductType_t>* registrar)
	{
		m_ProductRegistry[name] = registrar;
	}

	// ��������name����ȡ��Ӧ����Ĳ�Ʒ����
	ProductType_t* GetProduct(const std::string& name)
	{
		// ��map�л�ȡ�Ѿ�ע����Ĳ�Ʒ�������ز�Ʒ����
		if (m_ProductRegistry.find(name) != m_ProductRegistry.end())
		{
			return m_ProductRegistry[name]->CreateProduct(name);
		}
		return NULL;
	}

private:
	// ��ֹ�ⲿ���������
	ProductFactory() {}
	~ProductFactory() {}

	// ��ֹ�ⲿ�����͸�ֵ����
	ProductFactory(const ProductFactory&);
	const ProductFactory& operator=(const ProductFactory&);

	// ����ע����Ĳ�Ʒ
	std::map<std::string, IProductRegistrar<ProductType_t>*> m_ProductRegistry;
};




/// <summary>
/// ��Ʒע����ģ��
/// </summary>
/// <typeparam name="ProductType_t">ģ����� ProductType_t ��ʾ���ǻ���</typeparam>
/// <typeparam name="ProductImpl_t">ProductImpl_t ��ʾ����������</typeparam>
template<class ProductType_t, class ProductImpl_t>
class ProductRegistrar :public IProductRegistrar<ProductType_t>
{
public:
	// ���캯����ֻ����ʽ����
	explicit ProductRegistrar(const std::string& name)
	{
		// ע��Ӳ�Ʒ������
		ProductFactory<ProductType_t>::Instance().RegisterProduct(name, this);
	}

	// ����ָ������������ָ��
	ProductType_t* CreateProduct(const std::string& name)
	{
		return new ProductImpl_t(name);
	}
};

