#ifndef _BEVERAGE_H_
#define _BEVERAGE_H_

#include <iostream>
#include <string>
#include <memory>

class Beverage {
    public:
        Beverage() : _description("Unknown Beverage") {
            std::cout << "Beverage construct" << std::endl;
        }
        virtual ~Beverage() {
            std::cout << "Beverage destruct" << std::endl;
        }

        virtual std::string getDescription();
        virtual double cost() = 0;

    protected:
        std::string _description;
};

class HouseBlend : public Beverage {
    public:
        HouseBlend() {
            std::cout << "HouseBlend construct" << std::endl;
            _description = "HouseBlend";
        }
        ~HouseBlend() {
            std::cout << "HouseBlend destruct" << std::endl;
        }

        double cost();
};

class Espresso : public Beverage {
    public:
        Espresso() {
            std::cout << "Espresso construct" << std::endl;
            _description = "Espresso";
        }
        ~Espresso() {
            std::cout << "Espresso destruct" << std::endl;
        }

        double cost();
};

class Decaf : public Beverage {
    public:
        Decaf() {
            std::cout << "Decaf construct" << std::endl;
            _description = "Decaf";
        }
        ~Decaf() {
            std::cout << "Decaf destruct" << std::endl;
        }

        double cost();
};

class DarkRoast : public Beverage {
    public:
        DarkRoast() {
            std::cout << "DarkRoast construct" << std::endl;
            _description = "DarkRoast";
        }
        ~DarkRoast() {
            std::cout << "DarkRoast destruct" << std::endl;
        }

        double cost();
};

class CondimentDecorator : public Beverage {
    public:
        CondimentDecorator() {
            std::cout << "CondimentDecorator construct" << std::endl;
        }
        CondimentDecorator(CondimentDecorator*);
        virtual ~CondimentDecorator() {
            std::cout << "CondimentDecorator destruct" << std::endl;
        }

        virtual std::string getDescription() = 0;
};

class Soy : public CondimentDecorator {
    public:
        Soy() {
            std::cout << "Soy construct" << std::endl;
        }
        Soy(std::unique_ptr<Beverage>);
        ~Soy() {
            std::cout << "Soy destruct" << std::endl;
        }

        std::string getDescription();
        double cost();

    private:
        std::unique_ptr<Beverage> _beverage;
};

class Milk : public CondimentDecorator {
    public:
        Milk() {
            std::cout << "Milk construct" << std::endl;
        }
        Milk(std::unique_ptr<Beverage>);
        ~Milk() {
            std::cout << "Milk destruct" << std::endl;
        }

        std::string getDescription();
        double cost();

    private:
        std::unique_ptr<Beverage> _beverage;
};

class Mocha : public CondimentDecorator {
    public:
        Mocha() {
            std::cout << "Mocha construct" << std::endl;
        }
        Mocha(std::unique_ptr<Beverage>);
        ~Mocha() {
            std::cout << "Mocha destruct" << std::endl;
        }

        std::string getDescription();
        double cost();

    private:
        std::unique_ptr<Beverage> _beverage;
};

class Whip : public CondimentDecorator {
    public:
        Whip() {
            std::cout << "Whip construct" << std::endl;
        }
        Whip(std::unique_ptr<Beverage>);
        ~Whip() {
            std::cout << "Whip destruct" << std::endl;
        }

        std::string getDescription();
        double cost();

    private:
        std::unique_ptr<Beverage> _beverage;
};

#endif
