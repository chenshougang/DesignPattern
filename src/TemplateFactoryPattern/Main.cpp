// Main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
// #include "TemplateFactory.h"  // 如果在头文件中，使用了模板方法，最好将头文件以.hpp结尾。.h头文件会导致报错
#include "TemplateFactory.hpp"   
#include "RoleOperation.h"

//// 显式实例化
//template class ProductRegistrar<RoleOperation, RootAdminRole>;
//template class ProductRegistrar<RoleOperation, OrderAdminRole>;
//template class ProductRegistrar<RoleOperation, NormalAdminRole>;


void InitializeRole()
{
    static bool bInitialized = false;
    if (bInitialized == false)
    {
        // 这里一直报错
        static ProductRegistrar<RoleOperation, RootAdminRole> rootRegistrar("ROLE_ROOT_ADMIN");
        static ProductRegistrar<RoleOperation, OrderAdminRole> orderRegistrar("ROLE_ORDER_ADMIN");
        static ProductRegistrar<RoleOperation, NormalAdminRole> normalRegistrar("ROLE_NORMAL");

        bInitialized = true;
    }
}

class JudgeRole
{
public:
    std::string Judge(const std::string& roleName)
    {
        ProductFactory<RoleOperation>& factory = ProductFactory<RoleOperation>::Instance();

#if 0  // 传统指针
        // 从工厂获取对应的指针对象
        RoleOperation* pRoleOperation = factory.GetProduct(roleName);
        // 调用角色对应的操作权限
        std::string strResult = pRoleOperation->Op();
        // 手动释放资源
        delete pRoleOperation;
        pRoleOperation = nullptr;

        return strResult;
#endif

#if 1   // 智能指针
        // std::shared_ptr<RoleOperation> pRoleOperation = std::make_shared<RoleOperation>(roleName);   // ==>> new
        std::shared_ptr<RoleOperation> pRoleOperation(factory.GetProduct(roleName));
        return pRoleOperation->Op();
#endif
    }
};

int main()
{
    
    std::cout << "Hello World!\n";
    
    // 产品注册
    InitializeRole();

    // 开始调用
    JudgeRole _JudgeRole;
    std::cout << _JudgeRole.Judge("ROLE_ROOT_ADMIN") << std::endl;
    std::cout << _JudgeRole.Judge("ROLE_ORDER_ADMIN") << std::endl;
    std::cout << _JudgeRole.Judge("ROLE_NORMAL") << std::endl;

	return 0;
}

