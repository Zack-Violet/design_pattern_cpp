#include <iostream>
#include <new>
#include <string>
#include <memory>

class Product
{
    public:
        virtual ~Product() {}
        virtual void use() = 0;
        virtual std::string getName() = 0;
};

class ConcreteProductA : public Product
{
    public:
        ~ConcreteProductA() {}
        void use()
        {
            std::cout << "ConcreteProductA use()" << std::endl;
        }
        std::string getName()
        {
            return "ConcreteProductA";
        }
};

class ConcreteProductB : public Product
{
    public:
        ~ConcreteProductB() {}
        void use()
        {
            std::cout << "ConcreteProductB use()" << std::endl;
        }
        std::string getName()
        {
            return "ConcreteProductB";
        }
};

class Factory
{
    public:
        virtual ~Factory() {}
        virtual Product* createProduct() = 0;
};

class ConcreteProductAFactory : public Factory
{
    public:
        ~ConcreteProductAFactory() {}
        Product* createProduct()
        {
            std::cout << "create A" << std::endl;
            return new ConcreteProductA();
        }
};

class ConcreteProductBFactory : public Factory
{
    public:
        ~ConcreteProductBFactory() {}
        Product* createProduct()
        {
            std::cout << "create B" << std::endl;
            return new ConcreteProductB();
        }
};

int main()
{
    std::unique_ptr<Factory> fac1(new ConcreteProductAFactory());
    std::unique_ptr<Factory> fac2(new ConcreteProductBFactory());

    std::unique_ptr<Product> pro1(fac1->createProduct());
    std::unique_ptr<Product> pro2(fac2->createProduct());

    pro1->use();
    std::cout << pro1->getName() << std::endl;

    pro2->use();
    std::cout << pro2->getName() << std::endl;

    return 0;
}
