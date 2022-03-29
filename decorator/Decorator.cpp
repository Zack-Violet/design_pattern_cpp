#include <iostream>

class Component
{
    public:
        virtual ~Component() {}
        virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
    public:
        virtual ~ConcreteComponent() {}
        virtual void operation()
        {
            std::cout << "normal ConcreteComponent operation()" << std::endl;
        }
};

class Decorator : public Component
{
    public:
        Decorator(Component* tcom) : comp(tcom) {}
        virtual ~Decorator() {}
        virtual void operation()
        {
            comp->operation();
        }

    private:
        Component* comp;
};

class ConcreteDecoratorA : public Decorator
{
    public:
        ConcreteDecoratorA(Component* m) : Decorator(m) {}
        virtual void operation()
        {
            Decorator::operation();
            addOperationA();
        }
        void addOperationA()
        {
            std::cout << "ConcreteDecoratorA addOperationA()" << std::endl;
        }
};

class ConcreteDecoratorB : public Decorator
{
    public:
        ConcreteDecoratorB(Component* m) : Decorator(m) {}
        virtual void operation()
        {
            Decorator::operation();
            addOperationB();
        }
        void addOperationB()
        {
            std::cout << "ConcreteDecoratorB addOperationB()" << std::endl;
        }
};

int main()
{
    ConcreteComponent* comp = new ConcreteComponent();
    ConcreteDecoratorA* decpa = new ConcreteDecoratorA(comp);
    ConcreteDecoratorB* decpb = new ConcreteDecoratorB(decpa);

    Component* cp = decpb;
    cp->operation();

    delete comp;
    delete decpa;
    delete decpb;

    return 0;
}
