#include <iostream>
#include <vector>
#include <memory>

class Component {
    public:
        Component() {
            std::cout << "Component construct" << std::endl;
        }
        virtual ~Component() {
            std::cout << "Component destruct" << std::endl;
        }

        virtual void add(Component*) {
            std::cout << "add Component" << std::endl;
        }
        virtual void remove(const unsigned int) {
            std::cout << "remove Component" << std::endl;
        }
        virtual void operation() = 0;
};

class Composite : public Component {
    public:
        Composite() {
            std::cout << "Composite construct" << std::endl;
        }
        ~Composite() {
            std::cout << "Composite destruct" << std::endl;
        }

        Component* getChild(const unsigned int _index) {
            return _children[_index].get();
        }
        void add(Component* _com) {
            _children.push_back(std::unique_ptr<Component>(_com));
        }
        void remove(const unsigned int _index) {
            _children.erase(_children.begin() + _index);
        }
        void operation() {
            for (unsigned int i = 0; i < _children.size(); ++i) {
                _children[i]->operation();
            }
        }

    private:
        std::vector<std::unique_ptr<Component>> _children;
};

class Leaf : public Component {
    public:
        Leaf(const unsigned int _i) : _id(_i) {
            std::cout << "Leaf construct" << std::endl;
        }
        ~Leaf() {
            std::cout << "Leaf destruct" << std::endl;
        }

        void operation() {
            std::cout << "Leaf " << _id << " operation" << std::endl;
        }

    private:
        unsigned int _id;
};

int main() {
    std::unique_ptr<Composite> _composite(new Composite());

    for (int i = 0; i < 5; ++i) {
        _composite->add(new Leaf(i));
    }

    _composite->operation();
    _composite->remove(0);
    _composite->remove(3);
    _composite->operation();

    return 0;
}
