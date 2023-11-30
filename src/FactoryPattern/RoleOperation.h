#pragma once

#include <iostream>

// ���� ���麯��
class RoleOperation
{
public:
	virtual std::string Op() = 0;	// ���麯��
	virtual ~RoleOperation() {}  
};


// ��Բ�ͬ�Ľ�ɫ�࣬�̳л��࣬��ʵ��Op����

// ϵͳ����Ա����AȨ��
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

// ��������Ա����BȨ��
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


// ��ͨ����Ա����CȨ��
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