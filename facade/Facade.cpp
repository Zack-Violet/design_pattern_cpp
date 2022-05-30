#include <iostream>

class systemA {
    public:
        virtual ~systemA() {}
        void operationA() {
            std::cout << "systemA operationA()" << std::endl;
        }
};

class systemB {
    public:
        virtual ~systemB() {}
        void operationB() {
            std::cout << "systemB operationB()" << std::endl;
        }
};

class systemC {
    public:
        virtual ~systemC() {}
        void operationC() {
            std::cout << "systemC operationC()" << std::endl;
        }
};

class Facade {
    public:
        Facade() : sysA(), sysB(), sysC() {}

        void operation() {
            sysA->operationA();
            sysB->operationB();
            sysC->operationC();
        }
        void operation1() {
            sysC->operationC();
            sysB->operationB();
        }

    private:
        systemA* sysA;
        systemB* sysB;
        systemC* sysC;
};

int main() {
    Facade* fd = new Facade();

    fd->operation();
    fd->operation1();

    delete fd;

    return 0;
}
