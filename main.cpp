#include <iostream>
using std::string;
class Person
{
    public:
        Person(){
            std::cout << "Default" << std::endl;}
        Person(int age, string name, string address){
            m_age = age;
            m_name = name;
            m_address = address;
            std::cout << "With parameters" << std::endl;
        }
        Person(const Person& other){
            m_age = other.m_age;
            std::cout << "Copy" << std::endl;}
        Person& operator=(const Person& other){std::cout << "Operator=" << std::endl;return *this;}
        Person operator+(const Person& other){
            Person tmp;
            tmp.m_age = m_age + other.m_age;
            std::cout << "Operator+" << tmp.m_age << std::endl;  
            return tmp;
        }
        ~Person(){ std::cout << "Destructor" << std::endl;}; 
    private:
        int m_age;
        string m_name;
        string m_address;
    public:
        int get_age()const{return m_age;}
};
int main()
{
    Person ob(11,"a","b");
    std::cout << ob.get_age() << std::endl;
    Person ob1(ob);
    std::cout << ob1.get_age() << std::endl;
    Person ob3;
    std::cout << ob3.get_age() << std::endl;
    ob3 = ob + ob1;
    std::cout << ob3.get_age() << "Esa";
    std::cout << ob3.get_age() << std::endl;
    return 0;
}
