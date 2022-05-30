#include <iostream>
#include <string>
#include <memory>

class Product {
    public:
        Product() {}
        ~Product() {}
        void makePartA() {
            this->A = "A";
        }
        void makePartA(const std::string& sa) {
            this->A = sa;
        }
        void makePartB() {
            this->B = "B";
        }
        void makePartB(const std::string& sb) {
            this->B = sb;
        }
        void makePartC() {
            this->C = "C";
        }
        void makePartC(const std::string& sc) {
            this->C = sc;
        }
        std::string get() {
            return this->A + "->" + this->B + "->" + this->C;
        }

    private:
        std::string A;
        std::string B;
        std::string C;
};

class Builder {
    public:
        virtual ~Builder() {}
        virtual void buildA() = 0;
        virtual void buildB() = 0;
        virtual void buildC() = 0;
        virtual Product getResult() {
            return pro;
        }

    protected:
        Product pro;
};

class ConcreteBuilderX : public Builder {
    public:
        ~ConcreteBuilderX() {}
        void buildA() {
            pro.makePartA("A-X");
        }
        void buildB() {
            pro.makePartB("B-X");
        }
        void buildC() {
            pro.makePartC("C-X");
        }
};

class ConcreteBuilderY : public Builder {
    public:
        ~ConcreteBuilderY() {}
        void buildA() {
            pro.makePartA("A-Y");
        }
        void buildB() {
            pro.makePartB("B-Y");
        }
        void buildC() {
            pro.makePartC("C-Y");
        }
};

class Director {
    public:
        Director() : builder(nullptr) {}
        ~Director() {
            if (this->builder)
                delete builder;
        }
        void setBuilder(Builder* b) {
            if (this->builder)
                delete this->builder;

            this->builder = b;
        }
        void construct() {
            builder->buildA();
            builder->buildB();
            builder->buildC();
        }
        Product getProduct() {
            return builder->getResult();
        }

    private:
        Builder* builder;
};

int main() {
    std::unique_ptr<Director> dir(new Director());
    dir->setBuilder(new ConcreteBuilderX());
    dir->construct();
    Product pro0 = dir->getProduct();
    std::cout << "ConcreteBuilderX : " << pro0.get() << std::endl;

    dir->setBuilder(new ConcreteBuilderY());
    dir->construct();
    Product pro1 = dir->getProduct();
    std::cout << "ConcreteBuilderY : " << pro1.get() << std::endl;

    return 0;
}
