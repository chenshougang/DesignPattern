#pragma once

#include <iostream>

// 基类 纯虚函数
class RoleOperation
{
public:
	virtual std::string Op() = 0;	// 纯虚函数
	virtual ~RoleOperation() {}  
};


// 针对不同的角色类，继承基类，并实现Op函数

// 系统管理员，有A权限
class RootAdminRole :public RoleOperation
{
public:
	RootAdminRole(const std::string& roleName)
		:m_RoleName(roleName) {}

	std::string Op()
	{
		return m_RoleName + " has A Permission";
	}

private:
	std::string m_RoleName;
};

// 订单管理员，有B权限
class OrderAdminRole :public RoleOperation
{
public:
	OrderAdminRole(const std::string& roleName)
		:m_RoleName(roleName) {}

	std::string Op()
	{
		return m_RoleName + " has B Permission";
	}

private:
	std::string m_RoleName;
};


// 普通管理员，有C权限
class NormalAdminRole :public RoleOperation
{
public:
	NormalAdminRole(const std::string& roleName)
		:m_RoleName(roleName) {}

	std::string Op()
	{
		return m_RoleName + " has C Permission";
	}

private:
	std::string m_RoleName;
};