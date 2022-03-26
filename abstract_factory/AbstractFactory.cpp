#include <iostream>
#include <string>
#include <memory>

// A公司
class ProductA
{
    public:
        virtual ~ProductA() {}
        virtual void use() = 0;
        virtual std::string getName() = 0;
};

// A公司的产品X
class ConcreteProductAX : public ProductA
{
    public:
        ~ConcreteProductAX() {}
        void use()
        {
            std::cout << "ConcreteProductAX use()" << std::endl;
        }
        std::string getName()
        {
            return "ConcreteProductAX";
        }
};

// A公司的产品Y
class ConcreteProductAY : public ProductA
{
    public:
        ~ConcreteProductAY() {}
        void use()
        {
            std::cout << "ConcreteProductAY use()" << std::endl;
        }
        std::string getName()
        {
            return "ConcreteProductAY";
        }
};

// B公司
class ProductB
{
    public:
        virtual ~ProductB() {}
        virtual void use() = 0;
        virtual std::string getName() = 0;
};

// B公司的产品X
class ConcreteProductBX : public ProductB
{
    public:
        ~ConcreteProductBX() {}
        void use()
        {
            std::cout << "ConcreteProductBX use()" << std::endl;
        }
        std::string getName()
        {
            return "ConcreteProductBX";
        }
};

// B公司的产品Y
class ConcreteProductBY : public ProductB
{
    public:
        ~ConcreteProductBY() {}
        void use()
        {
            std::cout << "ConcreteProductBY use()" << std::endl;
        }
        std::string getName()
        {
            return "ConcreteProductBY";
        }
};

// 工厂
class Factory
{
    public:
        virtual ~Factory() {}
        virtual ProductA* CreateProductA() = 0;
        virtual ProductB* CreateProductB() = 0;
};
// 生产X产品的工厂
class ConcreteFactoryX : public Factory
{
    public:
        ~ConcreteFactoryX() {}
        ProductA* CreateProductA()
        {
            std::cout << "create ConcreteProductAX" << std::endl;
            return new ConcreteProductAX();
        }
        ProductB* CreateProductB()
        {
            std::cout << "create ConcreteProductBX" << std::endl;
            return new ConcreteProductBX();
        }
};

// 生产Y产品的工厂
class ConcreteFactoryY : public Factory
{
    public:
        ~ConcreteFactoryY() {}
        ProductA* CreateProductA()
        {
            std::cout << "create ConcreteProductAY" << std::endl;
            return new ConcreteProductAY();
        }
        ProductB* CreateProductB()
        {
            std::cout << "create ConcreteProductBY" << std::endl;
            return new ConcreteProductBY();
        }
};

int main()
{
    std::unique_ptr<Factory> facX(new ConcreteFactoryX());
    std::unique_ptr<Factory> facY(new ConcreteFactoryY());

    std::unique_ptr<ProductA> proAX(facX->CreateProductA());
    std::unique_ptr<ProductA> proAY(facY->CreateProductA());

    std::unique_ptr<ProductB> proBX(facX->CreateProductB());
    std::unique_ptr<ProductB> proBY(facY->CreateProductB());

    proAX->use();
    std::cout << proAX->getName() << std::endl;
    proAY->use();
    std::cout << proAY->getName() << std::endl;

    proBX->use();
    std::cout << proBX->getName() << std::endl;
    proBY->use();
    std::cout << proBY->getName() << std::endl;

    return 0;
}
