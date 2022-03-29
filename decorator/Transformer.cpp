#include <cwchar>
#include <iostream>
#include <string>

class AbstractTransformer
{
    public:
        virtual ~AbstractTransformer() {}
        virtual void move() = 0;
        virtual void talk() = 0;
        virtual void TransformTo() = 0;
        virtual void others() = 0;
};

class Transformer : public AbstractTransformer
{
    public:
        ~Transformer() {}
        virtual void move()
        {
            std::cout << "\033[32mTransformer  : We can walk and run, also, we can move by wheels or other ways.\033[0m" << std::endl;
        }
        virtual void talk()
        {
            std::cout << "\033[32mTransformer  : We can talk with someone by English.\033[0m" << std::endl;
        }
        virtual void TransformTo()
        {
            std::cout << "\033[32mTransformer  : We can transform to some cool vehicle.\033[0m" << std::endl;
        }
        virtual void others()
        {
            std::cout << "\033[32mTransformer  : This is what we have in common, but there are two camps, Autobots and Decepticons.\033[0m" << std::endl;
        }
};

class Autobots : public AbstractTransformer
{
    public:
        Autobots(AbstractTransformer* t) : ts(t) {}
        virtual ~Autobots() {}
        virtual void move()
        {
            ts->move();
        }
        virtual void talk()
        {
            ts->talk();
        }
        virtual void TransformTo()
        {
            ts->TransformTo();
        }
        virtual void others()
        {
            ts->others();
        }

    private:
        AbstractTransformer* ts;
};

class Decepticons : public AbstractTransformer
{
    public:
        Decepticons(AbstractTransformer* t) : ts(t) {}
        virtual void move()
        {
            ts->move();
        }
        virtual void talk()
        {
            ts->talk();
        }
        virtual void TransformTo()
        {
            ts->TransformTo();
        }
        virtual void others()
        {
            ts->others();
        }

    private:
        AbstractTransformer* ts;
};

class OptimusPrime : public Autobots
{
    public:
        OptimusPrime(AbstractTransformer* t) : Autobots(t) {}
        ~OptimusPrime() {}
        void move()
        {
            Autobots::move();
            std::cout << "\033[34mOptimusPrime : I, Optimus Prime, can move like a truck.\033[0m" << std::endl;
        }
        void talk()
        {
            Autobots::talk();
            std::cout << "\033[34mOptimusPrime : I, Optimus Prime, always give a speech at the end of the film.\033[0m" << std::endl;
        }
        void TransformTo()
        {
            Autobots::TransformTo();
            std::cout << "\033[34mOptimusPrime : I, Optimus Prime, can transform to a cool truck.\033[0m" << std::endl;
        }
        void others()
        {
            Autobots::others();
            std::cout << "\033[34mOptimusPrime : I, Optimus Prime, am the leader of the Autobots.\033[0m" << std::endl;
        }
};

class Bumblebee : public Autobots
{
    public:
        Bumblebee(AbstractTransformer* t) : Autobots(t) {}
        ~Bumblebee() {}
        void move()
        {
            Autobots::move();
            std::cout << "\033[33mBumblebee    : I, Bumblebee, can move like a roadster.\033[0m" << std::endl;
        }
        void talk()
        {
            Autobots::talk();
            std::cout << "\033[33mBumblebee    : Bumblebee's vocal parts were damaged in the battle with Decepticons, so I can`t talk to someone now.\033[0m" << std::endl;
        }
        void TransformTo()
        {
            Autobots::TransformTo();
            std::cout << "\033[33mBumblebee    : I, Bumblebee, can tranform to a cool Camaro.\033[0m" << std::endl;
        }
        void others()
        {
            Autobots::others();
            std::cout << "\033[33mBumblebee    : I, Bumblebee, am guardian of the Earthlings.\033[0m" << std::endl;
            std::cout << "\033[33mBumblebee    : I, Bumblebee, have been on Earth for a long time.\033[0m" << std::endl;
        }
};

class Megatron : public Decepticons
{
    public:
        Megatron(AbstractTransformer* t) : Decepticons(t) {}
        ~Megatron() {}
        void move()
        {
            Decepticons::move();
            std::cout << "\033[34mMegatron     : I, Megatron, can move in many ways.\033[0m" << std::endl;
        }
        void talk()
        {
            Decepticons::talk();
            std::cout << "\033[34mMegatron     : I, Megatron, have a very sexy voice, and is very majestic.\033[0m" << std::endl;
        }
        void TransformTo()
        {
            Decepticons::TransformTo();
            std::cout << "\033[34mMegatron     : I, Megatron, can transform to many military vehicles, like armored vehicles, or fighter plane with more cooler things.\033[0m" << std::endl;
        }
        void others()
        {
            Decepticons::others();
            std::cout << "\033[34mMegatron     : I, Megatron, am the leader of the Decepticons, but after the failed invasion of Earth, almost all the Decepticons were brutally killed By the Autobots.\033[0m" << std::endl;
            std::cout << "\033[34mMegatron     : But it is indeed our fault that we have killed countless innocent earthlings." << std::endl;
            std::cout << "\033[34mMegatron     : I, Megatron, am now working at Universal Studios Beijing, and I find it strange that people on Earth are not afraid of me now.\033[0m" << std::endl;
            std::cout << "\033[34mMegatron     : Hey! I am Megatron! The leader of the great Decepticons!\033[0m" << std::endl;
        }
};

class Starscream : public Decepticons
{
    public:
        Starscream(AbstractTransformer* t) : Decepticons(t) {}
        ~Starscream() {}
        void move()
        {
            Decepticons::move();
            std::cout << "\033[33mStarscream   : I, Starscream, can fly.\033[0m" << std::endl;
        }
        void talk()
        {
            Decepticons::talk();
            std::cout << "\033[33mStarscream   : Starscream's voice sounds like a sinister and cunning villain, though that is the way it is.\033[0m" << std::endl;
        }
        void TransformTo()
        {
            Decepticons::TransformTo();
            std::cout << "\033[33mStarscream   : I, Starscream, can tranform to a F-22, which is cool!\033[0m" << std::endl;
        }
        void others()
        {
            Decepticons::others();
            std::cout << "\033[33mStarscream   : Starscream:\"Megatron is so stupid that he was defeated by Optimus Prime.\"\033[0m" << std::endl;
        }
};

void processAutobots()
{
    Transformer* tsf = new Transformer();
    OptimusPrime* opp = new OptimusPrime(tsf);
    Bumblebee* bbp = new Bumblebee(opp);

    AbstractTransformer* abtp = bbp;
    abtp->move();
    abtp->talk();
    abtp->TransformTo();
    abtp->others();

    delete tsf;
    delete opp;
    delete bbp;
}

void processDecepticons()
{
    Transformer* tsf = new Transformer();
    Megatron* mgt = new Megatron(tsf);
    Starscream* ssm = new Starscream(mgt);

    AbstractTransformer* abtp = ssm;
    abtp->move();
    abtp->talk();
    abtp->TransformTo();
    abtp->others();

    delete tsf;
    delete mgt;
    delete ssm;
}

int main()
{
    std::cout << "\033[31m\033[1m---------------------------Autobots---------------------------------\033[0m" << std::endl;
    processAutobots();
    std::cout << "\033[31m\033[1m--------------------------------------------------------------------\033[0m" << std::endl;

    std::cout << "\033[31m\033[1m---------------------------Decepticons------------------------------\033[0m" << std::endl;
    processDecepticons();
    std::cout << "\033[31m\033[1m--------------------------------------------------------------------\033[0m" << std::endl;

    return 0;
}
