#include "JudgeRole.h"

std::string JudgeRole::Judge(std::string roleName)
{
	std::string result = "";
	if (roleName == "ROLE_ROOT_ADMIN")
	{
		result = roleName + " has A Permission";  // 系统管理员
	}
	else if (roleName == "ROLE_ORDER_ADMIN")
	{
		result = roleName + " has B Permission";  // 订单管理员
	}
	else if (roleName == "ROLE_NORMAL")
	{
		result = roleName + " has C Permission";  // 普通用户
	}
	return result;
}

// 这种方式写，if-else难看的要命，不便于维护，有成千上万种可能，那这代码比屎还难看
