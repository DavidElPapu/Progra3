#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <utility>

template <typename Object>
class Queue
{
private:
    struct Node
    {
        Object data;
        Node* previous;
        Node* next;

        Node(const Object& d = Object{}, Node* p = nullptr, Node* n = nullptr)
            : data{ d }, previous{ p }, next{ n } {}

        Node(Object&& d, Node* p = nullptr, Node* n = nullptr)
            : data{ std::move(d) }, previous{ p }, next{ n } {}
    };
public:
    class iterator {
    public:
        iterator() : current{ nullptr } {}

        Object& operator*() {
            if (current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator& operator--() {
            if (current)
                current = current->previous;
            else
                throw std::logic_error("Trying to go back past the start.");
            return *this;
        }

        iterator operator--(int) {
            iterator old = *this;
            --(*this);
            return old;
        }

        iterator& operator++() {
            if (current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const iterator& rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator& rhs) const {
            return !(*this == rhs);
        }

    private:
        Node* current;
        iterator(Node* p) : current{ p } {}
        friend class Queue<Object>;
    };

public:
    Queue() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
        tail->previous = head;
    }

    ~Queue() {
        clear();
        delete head;
        delete tail;
    }

    iterator begin() { return { head->next }; }
    iterator end() { return { tail }; }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void enqueue(const Object& x) { insert(end(), x); }
    void enqueue(Object&& x) { insert(end(), std::move(x)); }

    void dequeue() {
        if (empty())
            throw std::logic_error("The queue is empty.");
        erase(begin());
    }

    Object front() {
        return *begin();
    }

    void clear() { while (!empty()) pop(); }

    iterator insert(iterator itr, const Object& x) {
        Node* p = itr.current;
        p = new Node{ x, p->previous, p };
        theSize++;
        return iterator(p);
    }

    iterator insert(iterator itr, Object&& x) {
        Node* p = itr.current;
        p = new Node{ std::move(x), p->previous, p };
        theSize++;
        return iterator(p);
    }

    iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node* p = itr.current->previous;
        p->next = itr.current->next;
        p = p->next;
        p->previous = itr->previous;
        delete itr.current;
        theSize--;
        return iterator(p);
    }

    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
    Node* tail;
    int theSize;
    void init() {
        theSize = 0;
        head->next = tail;
        tail->previous = head;
    }
};

#endif // !QUEUE_H
