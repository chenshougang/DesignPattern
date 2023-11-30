#pragma once

#include <iostream>
#include <map>
#include "RoleOperation.h"


// 角色工厂
class RoleFactory
{
public:
	// 获取工厂单例，工厂的实例是唯一的
	static RoleFactory& Instance()
	{
		static RoleFactory instance;  // C++11 以上是线程安全的
		return instance;
	}

	// 把指针对象注册到工厂
	void RegisterRole(const std::string& name, RoleOperation* registrar)
	{
		m_RoleRegistry[name] = registrar;
	}

	// 根据名字name，获取对应的角色指针对象
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
	// 禁止外部构造和虚构
	RoleFactory() {}
	~RoleFactory() {}

	// 禁止外部拷贝和复制操作
	RoleFactory(const RoleFactory&);
	const RoleFactory& operator=(const RoleFactory &);

	// 保存注册过的角色，key：角色名，value：角色指针对象
	std::map<std::string, RoleOperation*> m_RoleRegistry;
};
