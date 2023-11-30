#pragma once

#include <iostream>
#include <map>
#include "RoleOperation.h"


// ��ɫ����
class RoleFactory
{
public:
	// ��ȡ����������������ʵ����Ψһ��
	static RoleFactory& Instance()
	{
		static RoleFactory instance;  // C++11 �������̰߳�ȫ��
		return instance;
	}

	// ��ָ�����ע�ᵽ����
	void RegisterRole(const std::string& name, RoleOperation* registrar)
	{
		m_RoleRegistry[name] = registrar;
	}

	// ��������name����ȡ��Ӧ�Ľ�ɫָ�����
	RoleOperation* GetRole(const std::string& name)
	{
		std::map<std::string, RoleOperation*>::iterator it;
		it = m_RoleRegistry.find(name);
		if (it != m_RoleRegistry.end())
		{
			return it->second;
		}
		return nullptr;
	}

private:
	// ��ֹ�ⲿ������鹹
	RoleFactory() {}
	~RoleFactory() {}

	// ��ֹ�ⲿ�����͸��Ʋ���
	RoleFactory(const RoleFactory&);
	const RoleFactory& operator=(const RoleFactory &);

	// ����ע����Ľ�ɫ��key����ɫ����value����ɫָ�����
	std::map<std::string, RoleOperation*> m_RoleRegistry;
};
