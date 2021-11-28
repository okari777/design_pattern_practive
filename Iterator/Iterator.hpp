#include<iostream>
#include<string>
#include<vector>

using namespace std;

template <typename T, typename U>
class Iterator
{
    typedef typename vector<T>::iterator iter_type;
    private:
        U *m_p_data_;
        iter_type m_it_;
    public:
        Iterator(U *p_data, bool reverse=false): m_p_data_(p_data)
        {
            m_it_ = m_p_data_->m_data_.begin();
        }
        void First()
        {
            m_it_ = m_p_data_->m_data_.begin();
        }
        void Next()
        {
            m_it_++;
        }
        iter_type Current()
        {
            return m_it_;
        }
        bool IsDone()
        {
            return (m_it_ == m_p_data_->m_data_.end());
        }
    
};

template<class T>
class Container
{
    private:
        vector<T> m_data_;
    public:
        friend class Iterator<T, Container>;
        void Add(T a)
        {
            m_data_.push_back(a);
        }
        Iterator<T, Container>* CreateIterator()
        {
            return new Iterator<T, Container>(this);
        }
};

class Data
{
    private:
        int m_data_;
    public:
        Data(int a = 0):m_data_(a){}
        void set_data(int a)
        {
            m_data_ = a;
        }
        int data()
        {
            return m_data_;
        }
};