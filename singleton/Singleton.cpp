#include <iostream>
#include <string>

class singleton
{
    public:
        singleton(const singleton&) = delete;
        singleton& operator=(const singleton&) = delete;
        ~singleton() {}
        static singleton* getInstance()
        {
            if (instance == nullptr)
                instance = new singleton();
            return instance;
        }
        void instanceOperation(const std::string& str)
        {
            std::cout << "some operation : " << str << std::endl;
        }

    private:
        singleton() {}

    private:
        static singleton* instance;
};

singleton* singleton::instance = nullptr;

int main()
{
    singleton* sg = singleton::getInstance();
    sg->instanceOperation("do something");

    return 0;
}
