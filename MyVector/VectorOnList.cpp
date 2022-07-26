#pragma once
#include <iostream>

namespace VectorOnList
{
    template<class T>
    class Node
    {
        public:
            Node()
            {
                this->next = NULL;
                this->prev = NULL;
            }

            Node(T newData) : Node()
            {
                this->data = newData;
            }

            Node(const Node &other)
            {
                this->data = other.data;
                this->next = other.next;
                this->prev = other.prev;
            }

            ~Node()
            {
                this->prev = NULL;
                this->next = NULL;
            }

            T GetData()
            {
                return this->data;
            }

            void SetData(T newData)
            {
                this->data = newData;
            }

            Node* next;
            Node* prev;

        private:
            T data;
    };

    template<class T>
    class VectorOnList
    {
        public:
            VectorOnList()
            {
                this->first = NULL;
                this->last = NULL;
                this->that = NULL;
            }

            VectorOnList(T newData) : VectorOnList()
            {
                this->push_back(newData);
            }

            VectorOnList(const VectorOnList &other)
            {
                this->first = other.first;
                this->last = other.last;
                this->that = other.that;
            }

            ~VectorOnList()
            {
                this->first = NULL;
                this->last = NULL;
                this->that = NULL;
            }

            Node<T>* createNode(T newData)
            {
                Node<T>* temp = new Node<T>();
                temp->SetData(newData);
                temp->next = NULL;
                temp->prev = NULL;
                return temp;
            }

            void pushBack(T newData)
            {
                Node<T>* temp = createNode(newData);
                this->that = this->last;
                if (this->first == NULL)
                {
                    this->first = temp;
                    this->last = temp;
                    this->that = temp;
                }
                else
                {
                    this->last = temp;
                    this->that->next = temp;
                    this->last->prev = this->that;
                    this->that = temp;
                }
                counter++;
            }

            void popBack()
            {
                this->that = this->last;
                if (this->first != NULL)
                {
                    this->last = this->last->prev;
                    this->that = this->last;
                    this->last->next = NULL;
                }
                counter--;
            }

            void pushFirst(T newData)
            {
                Node<T>* temp = createNode(newData);
                this->first->prev = temp;
                temp->next = this->first;
                this->first = temp;
                counter++;
            }

            void popFirst()
            {
                this->first = this->first->next;
                this->first->prev = NULL;
                counter--;
            }

            T front()
            {
                return this->first->GetData();
            }

            T back()
            {
                return this->last->GetData();
            }

            void showAll()
            {
                if(this->first != NULL)
                {
                    show(this->first);
                }
            }

            void show(Node<T>* temp)
            {
                std::cout << temp->GetData() << " ";
                if (temp->next != NULL)
                {
                    show(temp->next);
                }
            }

            T size()
            {
                return counter;
            }

            VectorOnList<T> &operator=(const VectorOnList<T> &other)
            {
                this->first = other.first;
                this->last = other.last;
                this->that = other.that;
                this->counter = other.counter;
                return *this;
            }

            VectorOnList<T> &operator[] (int index)
            {
                this->that = this->first;
                if (index > this->counter)
                {
                    exit(1);
                }
                showForOperator(0, index);
                return this->that->GetData();
            }

        private:
            Node<T>* first;
            Node<T>* last;
            Node<T>* that;
            long long counter = 0;

            void showForOperator(int count, int index)
            {
                if (index == count)
                {
                    return;
                }
                this->that = this->that->next;
                count++;
                showForOperator(count);
            }
    };
}