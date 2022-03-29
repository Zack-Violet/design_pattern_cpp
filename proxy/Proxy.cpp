#include <iostream>

class Subject
{
    public:
        virtual ~Subject() {}
        virtual void request() = 0;
};

class RealSubject : public Subject
{
    public:
        RealSubject() {}
        ~RealSubject() {}
        void request()
        {
            std::cout << "RealSubject request()" << std::endl;
        }
};

class Proxy : public Subject
{
    public:
        Proxy()
        {
            rsj = new RealSubject();
        }
        ~Proxy()
        {
            if (rsj)
                delete rsj;
        }
        void request()
        {
            preRequest();
            std::cout << "Proxy request() -> RealSubject request()" << std::endl;
            rsj->request();
            afterRequest();
        }

    private:
       RealSubject* rsj;
       void afterRequest()
       {
           std::cout << "Proxy afterRequest()" << std::endl;
       }
       void preRequest()
       {
           std::cout << "Proxy preRequest()" << std::endl;
       }
};

int main()
{
    Proxy* pxy = new Proxy();
    pxy->request();

    delete pxy;

    return 0;
}
