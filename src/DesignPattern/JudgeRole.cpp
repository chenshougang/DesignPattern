#include "JudgeRole.h"

std::string JudgeRole::Judge(std::string roleName)
{
	std::string result = "";
	if (roleName == "ROLE_ROOT_ADMIN")
	{
		result = roleName + " has A Permission";  // ϵͳ����Ա
	}
	else if (roleName == "ROLE_ORDER_ADMIN")
	{
		result = roleName + " has B Permission";  // ��������Ա
	}
	else if (roleName == "ROLE_NORMAL")
	{
		result = roleName + " has C Permission";  // ��ͨ�û�
	}
	return result;
}

// ���ַ�ʽд��if-else�ѿ���Ҫ����������ά�����г�ǧ�����ֿ��ܣ���������ʺ���ѿ�
