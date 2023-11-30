#pragma once

#ifndef  ROLE_CONTEXT_H
#define ROLE_CONTEXT_H

#include "RoleOperation.h"


/// <summary>
/// 
/// </summary>
class RoleContext
{
public:
	// ����operation���Ǳ�ʾ��ͬ�ġ����ԡ�
	RoleContext(RoleOperation* operation):m_pOperation(operation){}

	~RoleContext()
	{
		if (m_pOperation)
		{
			delete m_pOperation;
			m_pOperation = nullptr;
		}
	}

	std::string execute()
	{
		return m_pOperation->Op();
	}
private:
	// ��ֹ�ⲿ�����͸�ֵ����
	RoleContext(const RoleOperation&);
	const RoleContext& operator=(const RoleContext&);

	RoleOperation* m_pOperation;
};

class JudgeRole
{
public:
	std::string Judge(RoleOperation* pOperation)
	{
		RoleContext rolecontext(pOperation);
		return rolecontext.execute();
	}
};


#endif // ! ROLE_CONTEXT_H
