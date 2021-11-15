#include<string>
#include<iostream>
#include<list>
using namespace std;

class Abstract_Observer
{
    public:
        virtual ~Abstract_Observer(){}
        virtual void Update(string &message_from_subject) = 0;
};

class Abstract_Subject
{
    public:
        virtual ~Abstract_Subject(){}
        virtual void Attach(Abstract_Observer *obserber) = 0;
        virtual void Detach(Abstract_Observer *observer) = 0;
        virtual void Notify() = 0;
};

class Subject: public Abstract_Subject
{
    private:
        list<Abstract_Observer*> list_observer_;
        string message_;
    public:
        virtual ~Subject()
        {
            cout << "Goodbye, I was the Subject.\n";
        }

        void Attach(Abstract_Observer *observer)
        {
            list_observer_.push_back(observer);
        }
        void Detach(Abstract_Observer *observer)
        {
            list_observer_.remove(observer);
        }
        void Observer_count()
        {
            cout << "There are " << list_observer_.size() << " observers in the list.\n";
        }
        void Notify()
        {
            Observer_count();
            for(auto iterator = list_observer_.begin(); iterator != list_observer_.end(); iterator++)
            {
                (*iterator)->Update(message_);
            }
        }
        void CreateMessage(string message = "Empty")
        {
            this->message_ = message;
            Notify();
        }
};

class Observer: public Abstract_Observer
{
    private:
        string message_from_subject_;
        Subject *subject_;
        static int static_number_;
        int number_;
    public:
        Observer(Subject *subject): subject_(subject)
        {
            this->subject_->Attach(this);
            cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
            this->number_ = Observer::static_number_;
        }
        virtual ~Observer()
        {
            cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
        }
        void PrintInfo()
        {
            cout << "Observer \"" << number_ << "\": a new message is available -->" << this->message_from_subject_ << ".\n";
        }
        void Update(string &message_from_subject)
        {
            message_from_subject_ = message_from_subject;
            PrintInfo();
        }
        void RemoveMeFromList()
        {
            subject_->Detach(this);
            cout << "Observer \"" << number_ << "\" removed from the list.\n";
        }
};