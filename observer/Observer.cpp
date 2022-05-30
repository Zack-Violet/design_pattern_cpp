#include <iostream>
#include <vector>

class Observer;
class Subject {
    public:
        Subject() {}
        virtual ~Subject() {}
        virtual void attach(Observer* ob) {
            obs_vec.push_back(ob);
        }
        virtual void detach(const int index) {
            obs_vec.erase(obs_vec.begin() + index);
        }
        virtual void notify();
        virtual int getState() = 0;
        virtual void setState(int s) = 0;

    private:
        std::vector<Observer*> obs_vec;
};

class ConcreteSubject : public Subject {
    public:
        ConcreteSubject() {}
        ~ConcreteSubject() {}
        int getState() {
            return state;
        }
        void setState(int s) {
            state = s;
            notify();
        }

    private:
        int state;
};

class Observer {
    public:
        Observer() {}
        virtual ~Observer() {}
        virtual void update(Subject*) = 0;
};

class ConcreteObserver : public Observer {
    public:
        ConcreteObserver(const int stat) : observerState(stat) {}
        ~ConcreteObserver() {}
        void update(Subject* csub) {
            std::cout << "Before update, observerState is " << observerState << std::endl;
            observerState = csub->getState();
            std::cout << "observerState update to " << observerState << std::endl;
        }

    private:
        int observerState;
};

void Subject::notify() {
    for (int i = 0; i < obs_vec.size(); ++i) {
        obs_vec[i]->update(this);
    }
}

int main() {
    Observer* obs1 = new ConcreteObserver(1);
    Observer* obs2 = new ConcreteObserver(2);

    Subject* subj = new ConcreteSubject();
    subj->attach(obs1);
    subj->attach(obs2);

    subj->setState(10);

    delete subj;

    return 0;
}
