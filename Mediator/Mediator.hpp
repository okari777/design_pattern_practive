#include<iostream>
#include<string>

class BaseComponent;

class Mediator
{
    public:
        virtual void Notify(BaseComponent *sender, std::string event) = 0;
};

class BaseComponent
{
    protected:
        Mediator *mediator_;
    
    public:
        BaseComponent(Mediator *mediator = nullptr): mediator_(mediator){}
        void set_mediator(Mediator *mediator)
        {
            this->mediator_ = mediator;
        }
};

class Component1: public BaseComponent
{
    public:
        void DoA()
        {
            std::cout << "Component1 does A.\n";
            this->mediator_->Notify(this, "A");
        }
        void DoB()
        {
            std::cout << "Component1 does B.\n";
            this->mediator_->Notify(this, "B");
        }
};

class Component2: public BaseComponent
{
    public:
        void DoC()
        {
            std::cout << "Component2 does C.\n";
            this->mediator_->Notify(this, "C");
        }
        void DoD()
        {
            std::cout << "Component2 does D.\n";
            this->mediator_->Notify(this, "D");
        }
};

class ConcreteMediator: public Mediator
{
    private:
        Component1 *component1_;
        Component2 *component2_;
    public:
        ConcreteMediator(Component1 *component1, Component2 *component2):component1_(component1), component2_(component2)
        {
            this->component1_->set_mediator(this);
            this->component2_->set_mediator(this);
        }
        void Notify(BaseComponent *sender, std::string event)
        {
            if(event == "A")
            {
                std::cout << "Mediator reacts on A and triggers following operations:\n";
                this->component2_->DoC();
            }
            if(event == "D")
            {
                std::cout << "Mediator reacts on D and triggers following operations:\n";
                this->component1_->DoB();
                this->component2_->DoC();
            }
        }
};