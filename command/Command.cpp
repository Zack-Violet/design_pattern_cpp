#include <iostream>

class Receive
{
    public:
        Receive() {}
        ~Receive() {}
        void action()
        {
            std::cout << "Receive action()" << std::endl;
        }
};

class Command
{
    public:
        Command(Receive* r) : rcv(r) {}
        virtual ~Command() {}
        virtual void execute() = 0;

    protected:
        Receive* rcv;
};

class ConcreteCommand : public Command
{
    public:
        ConcreteCommand(Receive* i) : Command(i) {}
        ~ConcreteCommand() {}
        void execute()
        {
            std::cout << "ConcreteCommand execute() -> Receive action()" << std::endl;
            rcv->action();
        }
};

class Invoker
{
    public:
        Invoker(Command* c) : cmd(c) {}
        ~Invoker() {}
        void call()
        {
            std::cout << "Invoker call() -> ConcreteCommand execute()" << std::endl;
            cmd->execute();
        }

    private:
        Command* cmd;
};

int main()
{
    Receive* rcv = new Receive();
    Command* cmd = new ConcreteCommand(rcv);
    Invoker* ivk = new Invoker(cmd);

    ivk->call();

    delete rcv;
    delete cmd;
    delete ivk;

    return 0;
}
