#include <iostream>
#include <memory>

class Implementor
{
    public:
        virtual ~Implementor() {}
        virtual void operationImp() = 0;
};

class ImplementorConcreteA : public Implementor
{
    public:
        virtual void operationImp()
        {
            std::cout << "ImplementorConcreteA operationImp() do something" << std::endl;
        }
};

class ImplementorConcreteB : public Implementor
{
    public:
        virtual void operationImp()
        {
            std::cout << "ImplementorConcreteB operationImp() do something" << std::endl;
        }
};

class Abstruction
{
    public:
        Abstruction(Implementor* pimp) : imp(pimp) {}
        virtual ~Abstruction() {}
        virtual void operation() = 0;

    protected:
        Implementor* imp;
};

class RefinedAbstruction : public Abstruction
{
    public:
        RefinedAbstruction(Implementor* tmp) : Abstruction(tmp) {}
        ~RefinedAbstruction() {}
        virtual void operation()
        {
            imp->operationImp();
        }

    private:
        //Implementor* imp;
};


int main()
{
    Abstruction* abspa = new RefinedAbstruction(new ImplementorConcreteA());

    abspa->operation();

    Abstruction* abspb = new RefinedAbstruction(new ImplementorConcreteB());

    abspb->operation();

    delete abspb;
    delete abspa;

    return 0;
}
