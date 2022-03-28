#include <iostream>
#include <memory>

class Target
{
    public:
        virtual ~Target() {}
        virtual void request() = 0;
};

class Adaptee
{
    public:
        virtual ~Adaptee() {}
        void specificRequest()
        {
            std::cout << "do something" << std::endl;
        }
};

class Adapter : public Target, public Adaptee
{
    public:
        virtual void request()
        {
            specificRequest();
        }
};

int main()
{
    std::unique_ptr<Target> ptr(new Adapter());
    ptr->request();

    return 0;
}
