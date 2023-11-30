// FactoryPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "RoleFactory.h"

void InitializeRole();

class JudgeRole
{
public:
    std::string Judge(const std::string& roleName)
    {
        return RoleFactory::Instance().GetRole(roleName)->Op();
    }
};



int main()
{
    std::cout << "Hello World!\n";
    InitializeRole();
    
    JudgeRole _JudgeRole;
    std::cout << _JudgeRole.Judge("ROLE_ROOT_ADMIN") << std::endl;
    std::cout << _JudgeRole.Judge("ROLE_ORDER_ADMIN") << std::endl;
    std::cout << _JudgeRole.Judge("ROLE_NORMAL") << std::endl;
}

void InitializeRole()
{
    static bool bInitialized = false;

    if (bInitialized == false)
    {
        RoleFactory::Instance().RegisterRole("ROLE_ROOT_ADMIN", new RootAdminRole("ROLE_ROOT_ADMIN"));
        RoleFactory::Instance().RegisterRole("ROLE_ORDER_ADMIN", new RootAdminRole("ROLE_ORDER_ADMIN"));
        RoleFactory::Instance().RegisterRole("ROLE_NORMAL", new RootAdminRole("ROLE_NORMAL"));
        bInitialized = true;
    }
}


