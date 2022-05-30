#include <iostream>
#include <string>
#include <vector>

class Mediator;
class Colleague {
    public:
        Colleague(Mediator* const md, unsigned int id) : media_C(md), Cid(id) {}
        virtual ~Colleague() {}
        virtual void sendmsg(const std::string&) = 0;
        virtual void receivemsg(const std::string&) = 0;
        virtual unsigned int getID() = 0;

    protected:
        Mediator* media_C;
        unsigned int Cid;
};

class ConcreteColleague : public Colleague {
    public:
        ConcreteColleague(Mediator* const m, unsigned int i) : Colleague(m, i) {}
        ~ConcreteColleague() {}
        void sendmsg(const std::string& msg_s);
        void receivemsg(const std::string& m) {
            std::cout << this->getID() <<" receivemsg : " << m << std::endl;
        }
        unsigned int getID() {
            return this->Cid;
        }
};

class Mediator {
    public:
        virtual ~Mediator() {}
        virtual void operation(Colleague* const, std::string) = 0;
        virtual void registerC(Colleague*) = 0;
};

class ConcreteMediator : public Mediator {
    public:
        ~ConcreteMediator() {
            for (int i = 0; i < cols.size(); ++i) {
                if (cols[i])
                    delete cols[i];
            }
            cols.clear();
        }
        void operation(Colleague* const sender, std::string msg) {
            std::cout << " forward msg" << std::endl;
            for (int i = 0; i < cols.size(); ++i) {
                if (cols[i] == sender)
                    continue;
                cols[i]->receivemsg(msg);
            }
        }
        void registerC(Colleague* col) {
            cols.push_back(col);
        }

    private:
        std::vector<Colleague*> cols;
};

void ConcreteColleague::sendmsg(const std::string& msg_s) {
    std::cout << this->getID() << " sendmsg : " << msg_s << std::endl;
    media_C->operation(this, msg_s);
}

int main() {
    Mediator* media = new ConcreteMediator();

    Colleague* a = new ConcreteColleague(media, 1);
    Colleague* b = new ConcreteColleague(media, 2);
    Colleague* c = new ConcreteColleague(media, 3);

    media->registerC(a);
    media->registerC(b);
    media->registerC(c);

    a->sendmsg("Hi~");
    c->sendmsg("Hello~");
    b->sendmsg("Hey~");

    delete media;

    return 0;
}
