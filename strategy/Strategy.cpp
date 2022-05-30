#include <iostream>

class Strategy {
    public:
        virtual ~Strategy() {}
        virtual void algorithm() = 0;
};

class ConcreteStrategyA : public Strategy {
    public:
        ~ConcreteStrategyA() {}
        void algorithm() {
            std::cout << "ConcreteStrategyA algorithm()" << std::endl;
        }
};

class ConcreteStrategyB :public Strategy {
    public:
        ~ConcreteStrategyB() {}
        void algorithm() {
            std::cout << "ConcreteStrategyB algorithm()" << std::endl;
        }
};

class Context {
    public:
        Context() : stra() {}
        ~Context() {
            delete stra;
        }
        void algorithm() {
            stra->algorithm();
        }
        void setStrategy(Strategy* const s) {
            if (stra)
                delete stra;

            stra = s;
        }

    private:
        Strategy* stra;
};


int main() {
    Context* context = new Context();
    context->setStrategy(new ConcreteStrategyA());
    context->algorithm();

    context->setStrategy(new ConcreteStrategyB());
    context->algorithm();

    delete context;

    return 0;
}
