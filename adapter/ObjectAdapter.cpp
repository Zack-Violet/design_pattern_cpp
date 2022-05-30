#include <iostream>
#include <memory>

class Target {
    public:
        virtual ~Target() {}
        virtual void request() = 0;
};

class Adaptee {
    public:
        void specificRequest() {
            std::cout << "do something specificRequest()" << std::endl;
        }
};

class Adapter : public Target {
    public:
        Adapter() : apt() {}
        ~Adapter() {
            if (apt)
                delete apt;
        }
        virtual void request() {
            apt->specificRequest();
        }

    private:
        Adaptee* apt;
};

int main() {
    std::unique_ptr<Target> ptr(new Adapter());
    ptr->request();

    return 0;
}
