#include <iostream>
// #include <mutex>
#include <vector>
#include <winnt.h>

class Singleton {
public:
    // 获取实例的全局访问点
    //static Singleton& getInstance() {
    //    static Singleton instance; // C++11保证线程安全的局部静态变量初始化
    //    return instance;
    //}

    static Singleton& getInstance()
    {
        static Singleton instance;  // C++11保证线程安全的局部静态变量初始化
        return instance;
    }

    // 示例方法
    void showMessage() const {
        std::cout << "Hello from Singleton!" << std::endl;

        for (int i = 0; i < m_vec.size(); i++)
        {
            std::cout << "i = " << m_vec[i] << std::endl;
        }
    }

    void addNum(int i)
    {
        m_vec.push_back(i);
    }

    // 禁止复制和赋值
    Singleton(const Singleton&) = delete;              // C++11
    Singleton& operator=(const Singleton&) = delete;   // C++11

private:

    std::vector<int> m_vec;
    // 私有构造函数，确保只能通过 getInstance() 获取实例
    Singleton() {
        // 初始化操作（如果需要）
    }

    // 私有析构函数，确保只能通过 getInstance() 获取实例进行销毁
    ~Singleton() {
        // 清理操作（如果需要）
    }
};


void Init()
{
    Singleton& singletonInstance = Singleton::getInstance();
    singletonInstance.addNum(100);

    // 使用单例实例
    singletonInstance.showMessage();
}

int main() {
    // 获取单例实例
    Init();
    Init();
    Init();

    // 尝试复制或赋值将导致编译错误
    // Singleton anotherInstance = singletonInstance;  // Error: copy constructor is deleted
    // Singleton yetAnotherInstance;
    // yetAnotherInstance = singletonInstance;  // Error: copy assignment operator is deleted

    std::cout << "wchar_t size = " << sizeof(wchar_t) << std::endl;   // 输出是2个字节
    std::cout << "char size = " << sizeof(char) << std::endl;   // 输出是1个字节

    wchar_t xx;

    DWORD64 xxxxx;


    return 0;
}
