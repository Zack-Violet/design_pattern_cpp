#include <iostream>
#include <map>

class Flyweight {
    public:
        virtual ~Flyweight() {}
        virtual void operation() = 0;
};

class ConcreteFlyweight : public Flyweight {
    public:
        ConcreteFlyweight(const int all_state) : state(all_state) {}
        ~ConcreteFlyweight() {}
        void operation() {
            std::cout << "ConcreteFlyweight with state " << state << std::endl;
        }

    private:
        int state;
};

class UnsharedConcreteFlyweight : public Flyweight {
    public:
        UnsharedConcreteFlyweight(const int intrinsic_state) : state(intrinsic_state) {}
        ~UnsharedConcreteFlyweight() {}
        void operation() {
            std::cout << "UnsharedConcreteFlyweight with state " << state << std::endl;
        }

    private:
        int state;
};

class FlyweightFactory {
    public:
        FlyweightFactory() {}
        ~FlyweightFactory() {
            for (auto it = fws.begin(); it != fws.end(); it++) {
                delete it->second;
            }
            fws.clear();
        }
        Flyweight* getFlyweight(const int key) {
            if (fws.find(key) != fws.end()) {
                std::cout << "There is already exit a Flyweight object. Return exit object." << std::endl;
                return fws[key];
            }
            std::cout << "There is no object requested here. So return a new object." << std::endl;
            Flyweight* fw = new ConcreteFlyweight(key);
            fws.emplace(std::pair<int, Flyweight*>(key, fw));
            return fw;
        }

    private:
        std::map<int, Flyweight*> fws;
};

int main() {
    FlyweightFactory* fwf = new FlyweightFactory;
    fwf->getFlyweight(1)->operation();
    fwf->getFlyweight(2)->operation();
    fwf->getFlyweight(1)->operation();

    delete fwf;

    return 0;
}
