#include <iostream>
#include <string>

class Prototype {
    public:
        virtual ~Prototype() {}
        virtual Prototype* clone() = 0;
        virtual std::string getType() = 0;
};

class ConcretePrototypeA : public Prototype {
    public:
        ~ConcretePrototypeA() {}
        Prototype* clone() {
            return new ConcretePrototypeA();
        }
        std::string getType() {
            return "A";
        }
};

class ConcretePrototypeB : public Prototype {
    public:
        ~ConcretePrototypeB() {}
        Prototype* clone() {
            return new ConcretePrototypeB();
        }
        std::string getType() {
            return "B";
        }
};

class Client {
    public:
        Client() {}
        ~Client() {}
        static void init() {
            types[0] = new ConcretePrototypeA;
            types[1] = new ConcretePrototypeB;
        }
        static void remove() {
            delete types[0];
            delete types[1];
        }
        static Prototype* getClone(int index) {
            if (index >= n_types)
                return nullptr;
            return types[index]->clone();
        }

    private:
        static Prototype* types[2];
        static int n_types;
};

Prototype* Client::types[2];
int Client::n_types = 2;

int main() {
    Client::init();

    Prototype* ptya = Client::getClone(0);
    std::cout << "Prototype : " << ptya->getType() << std::endl;
    delete ptya;

    Prototype* ptyb = Client::getClone(1);
    std::cout << "Prototype : " << ptyb->getType() << std::endl;
    delete ptyb;

    Client::remove();

    return 0;
}
