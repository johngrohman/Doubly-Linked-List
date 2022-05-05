#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

template <typename T>
class Node
{
    public:
        T m_element;

        Node<T> *m_prev;
        Node<T> *m_next;

        Node(Node<T> *in_prev, Node<T> *in_next): 
            m_prev(in_prev), m_next(in_next){}

        Node(const T &x, Node<T> *in_prev, Node<T> *in_next): 
            m_element(x), m_prev(in_prev), m_next(in_next){}
};


template <typename T>
class MyList
{
    private:
        Node<T> *m_sentinel = nullptr;

        int m_size;

    public:
        // A list size of 0 will have 1 sentinel node.
        MyList();

        ~MyList();

        MyList<T> & operator=(const MyList<T> &source);

        MyList(const MyList<T> &source);

        T & front();

        T & back();

        void assign(int count, const T &value);

        void clear();

        void push_front(const T &x);

        void push_back(const T &x);

        void pop_back();

        void pop_front();

        void insert(int i, const T &x);

        void remove(T value);
        
        // Removes element at position i.
        void erase(int i);

        void reverse();

        bool empty();

        int size();
};

#include "MyList.hpp"

#endif

