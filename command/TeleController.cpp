#include <iostream>

class Televation
{
    public:
        Televation()
        {
            std::cout << "Televation now is off" << std::endl;
        }
        ~Televation() {}
        void turnOff()
        {
            std::cout << "Televation off" << std::endl;
        }
        void turnOn()
        {
            std::cout << "Televation on" << std::endl;
        }
        void volumeUp()
        {
            std::cout << "Televation volumeUp" << std::endl;
        }
        void volumeDown()
        {
            std::cout << "Televation volumeDown" << std::endl;
        }
        void nextChannel()
        {
            std::cout << "Televation nextChannel" << std::endl;
        }
        void preChannel()
        {
            std::cout << "Televation preChannel" << std::endl;
        }
};

class Command
{
    public:
        virtual ~Command() {}
        virtual void excute(bool) = 0;

    protected:
    //    Command(Televation* t) : tele(t) {}
        Command() {}

    //protected:
    //    Televation* tele;
};

class ConcreteCommandPower : public Command
{
    public:
        ConcreteCommandPower(Televation* t) : tele(t) {}
        ~ConcreteCommandPower()
        {
            if (tele)
                delete tele;
        }
        void excute(bool s)
        {
            if (s)
                tele->turnOn();
            else
                tele->turnOff();
        }

    private:
        Televation* tele;
};

class ConcreteCommandVolume : public Command
{
    public:
        ConcreteCommandVolume(Televation* t) : tele(t) {}
        ~ConcreteCommandVolume()
        {
            if (tele)
                delete tele;
        }
        void excute(bool s)
        {
            if (s)
                tele->volumeUp();
            else
                tele->volumeDown();
        }

    private:
        Televation* tele;
};

class ConcreteCommandChannel : public Command
{
    public:
        ConcreteCommandChannel(Televation* t) : tele(t) {}
        ~ConcreteCommandChannel()
        {
            if (tele)
                delete tele;
        }
        void excute(bool s)
        {
            if (s)
                tele->nextChannel();
            else
                tele->preChannel();
        }

    private:
        Televation* tele;
};

class Controller
{
    public:
        Controller() {}
        Controller(Command* c) : cmd(c) {}
        ~Controller()
        {
            if (cmd)
                delete cmd;
        }
        void setCtrl(Command* c)
        {
            if (cmd)
                delete cmd;
            cmd = c;
        }
        void excute(bool s)
        {
            cmd->excute(s);
        }

    private:
        Command* cmd;
};

int main()
{
    Televation* tel = new Televation();
    Controller* ctrl = new Controller(new ConcreteCommandPower(tel));

    ctrl->excute(1);

    ctrl->setCtrl(new ConcreteCommandVolume(tel));
    ctrl->excute(1);
    ctrl->excute(1);
    ctrl->excute(0);

    ctrl->setCtrl(new ConcreteCommandChannel(tel));
    ctrl->excute(1);
    ctrl->excute(0);

    ctrl->setCtrl(new ConcreteCommandPower(tel));
    ctrl->excute(0);

    delete ctrl;

    return 0;
}
