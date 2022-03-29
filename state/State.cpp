#include <iostream>

class State
{
    public:
        virtual ~State() {}
        virtual void handle() = 0;
};

class ConcreteStateA : public State
{
    public:
        ConcreteStateA() {}
        ~ConcreteStateA() {}
        void handle()
        {
            std::cout << "ConcreteStateA handle()" << std::endl;
        }
};

class ConcreteStateB : public State
{
    public:
        ConcreteStateB() {}
        ~ConcreteStateB() {}
        void handle()
        {
            std::cout << "ConcreteStateB handle()" << std::endl;
        }
};

class Context
{
    public:
        Context() : stat() {}
        ~Context()
        {
            delete stat;
        }
        void changeState(State* const s)
        {
            if (stat)
                delete stat;
            stat = s;
        }
        void request()
        {
            std::cout << "Context request()" << std::endl;
            stat->handle();
        }

    private:
        State* stat;
};

int main()
{
    Context* context = new Context();
    context->changeState(new ConcreteStateA());
    context->request();

    context->changeState(new ConcreteStateB());
    context->request();

    delete context;

    return 0;
}
