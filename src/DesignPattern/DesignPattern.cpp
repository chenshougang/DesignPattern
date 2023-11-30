// DesignPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "JudgeRole.h"

int main()
{
    std::cout << "Hello World!\n";

    std::string _roleName = "ROLE_ROOT_ADMIN";
    JudgeRole _JudgeRole;
    std::cout << _JudgeRole.Judge(_roleName) << std::endl;
}
