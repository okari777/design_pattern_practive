#include <string>
#include <list>

using namespace std;

class Component
{
    protected:
        Component* _root;
    public:
        virtual ~Component(){}
        void Setroot(Component* root)
        {
            this->_root = root;
        }
        Component* Getroot()
        {
            return this->_root;
        }
        virtual void Add(Component*){}
        virtual void Remove(Component*){}
        virtual string Operation() = 0;
        virtual bool IsBranch()
        {
            return false;
        }
};

class Leaf: public Component
{
    public:
        string Operation()
        {
            return "leaf item";
        }
};

class Branch: public Component
{
    protected:
        list<Component*> _children;
    public:
        void Add(Component* component)
        {
            _children.push_back(component);
            component->Setroot(this);
        }
        void Remove(Component* component)
        {
            _children.remove(component);
            component->Setroot(nullptr);
        }
        bool IsBranch()
        {
            return true;
        }
        string Operation()
        {
            string result;
            for(Component *component:_children)
            {
                if(component == _children.back())
                    result += component->Operation();
                else
                    result += component->Operation() + " + ";
            }
            result = "Branch: ( " + result + " )";
            return result;
        }
};