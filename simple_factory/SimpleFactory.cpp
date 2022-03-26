#include <iostream>
#include <memory>

// 抽象产品
class product
{
    public:
        product()
        {
            std::cout << "product construct" << std::endl;
        }
        virtual ~product() {}

        virtual void use() = 0;
};

// 具体产品A
class ConcreteProductA : public product
{
    public:
        ConcreteProductA() : product()
        {
            std::cout << "ConcreteProductA construct" << std::endl;
        }
        virtual ~ConcreteProductA() {}

        void use()
        {
            std::cout << "ConcreteProductA use()" << std::endl;
        }

        void useA()
        {
            std::cout << "ConcreteProductA useA()" << std::endl;
        }
};

// 具体产品B
class ConcreteProductB : public product
{
    public:
        ConcreteProductB() : product()
        {
            std::cout << "ConcreteProductB construct" << std::endl;
        }
        virtual ~ConcreteProductB() {}

        virtual void use()
        {
            std::cout << "ConcreteProductB use()" << std::endl;
        }

        void useB()
        {
            std::cout << "ConcreteProductB useB()" << std::endl;
        }
};

// 根据选项选择生产对应的产品
class factory
{
    public:
        product* creatProduct(std::string proName)
        {
            if (proName == "A")
            {
                std::cout << "create ConcreteProductA" << std::endl;
                return new ConcreteProductA();
            }
            else if (proName == "B")
            {
                std::cout << "create ConcreteProductB" << std::endl;
                return new ConcreteProductB();
            }

            return nullptr;
        }
};

int main()
{
    //factory* fac = new factory();
    //product* pro1 = fac->creatProduct("A");
    //product* pro2 = fac->creatProduct("B");
    std::unique_ptr<factory> fac(new factory());
    std::unique_ptr<product> pro1(fac->creatProduct("A"));
    std::unique_ptr<product> pro2(fac->creatProduct("B"));

    pro1->use();
    pro2->use();

    //delete fac;
    //delete pro1;
    //delete pro2;

    return 0;
}
