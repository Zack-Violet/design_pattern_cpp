#include <iostream>
#include <string>
#include <memory>

class ProductA
{
    public:
        virtual ~ProductA() {}
        virtual void use() = 0;
        virtual std::string getName() = 0;
};

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

class ProductB
{
    public:
        virtual ~ProductB() {}
        virtual void use() = 0;
        virtual std::string getName() = 0;
};

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

class Factory
{
    public:
        virtual ~Factory() {}
        virtual ProductA* CreateProductA() = 0;
        virtual ProductB* CreateProductB() = 0;
};

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
