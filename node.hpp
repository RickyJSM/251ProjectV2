#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class node {
    public:
        //constructors
        node() {
            next = nullptr;
        }
        node(T dataI) {
            data = dataI;
            next = nullptr;
        }

        //accessors
        T& getData() {
            return data;
        }
        const T& getData() const {
            return data;
        }
        
        node<T>* getNext() {
            return next;
        }

        void setData(T dataI) {
            data = dataI;
        }
        void setNext(node<T>* nextI) {
            next = nextI;
        }

    private:
        T data;
        node<T>* next;
};

#endif