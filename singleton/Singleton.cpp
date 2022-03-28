#include <iostream>
#include <string>
#include <memory>

class singleton
{
    public:
        ~singleton() {}
        static singleton* getInstance()
        {
            if (instance == nullptr)
                instance = new singleton();
            return instance;
        }
        void instanceOperation()
        {
            std::cout << "some operation" << std::endl;
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
    sg->instanceOperation();

    return 0;
}
