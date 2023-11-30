// PrototypePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>


// 首先定义一个抽象原型类
class Object
{
public:
    virtual Object* clone() const = 0;
};


// 邮件的附件
class Attachment
{
public:
    void  set_content(std::string content)
    {
        m_content = content;
    }
    std::string get_content()
    {
        return m_content;
    }

private:
    std::string m_content;
};


// 具体原型
class Email :public Object
{
public:
    Email(){}
    Email(std::string text, std::string attachment_content)
        :m_text(text), m_attachment(new Attachment()) 
    {
        m_attachment->set_content(attachment_content);
    }

    ~Email()
    {
        if (m_attachment)
        {
            delete m_attachment;
            m_attachment = nullptr;
        }
    }

    void display()
    {
        std::cout << "text = " << m_text << std::endl;
        std::cout << "content = " << m_attachment->get_content() << std::endl;
    }

    // deep copy
    Email* clone() const override
    {
        // 等价于深拷贝
        return new Email(this->m_text, this->m_attachment->get_content());
    }

    void changeText(std::string new_text) { m_text = new_text; }
    void changeAttachment(std::string content) { m_attachment->set_content(content); }

private:
    std::string m_text;
    Attachment* m_attachment = nullptr;
};

int main()
{
    std::cout << "Hello World!\n";


    // demo 
    Email* email = new Email("xxx", "xxxxx");
    email->display();

    for (int i = 0; i < 10; i++)
    {
        Email* email_copy = email->clone();
        email_copy->changeText("new text " + std::to_string(i));
        email_copy->changeAttachment("new Attachment " + std::to_string(i));
        
        email_copy->display();
        delete email_copy;
        email_copy = nullptr;
    }
    
}
