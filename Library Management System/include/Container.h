#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <utility>
using namespace std;
template<typename T>
class Container
{
private:
    struct Node
    {
        T data;
        Node*next;
        Node*prev;
        Node(T val):data(val),next(nullptr),prev(nullptr) {}
    };

    Node*head;
    Node*tail;
    int size;
public:
    class Iterator
    {
    private:
        Node*current;
    public:
        Iterator(Node*node=nullptr):current(node) {}
        T&operator*()
        {
            return current->data;
        }
        Iterator&next()
        {
            if(current)current=current->next;
            return*this;
        }
        Iterator&prev()
        {
            if(current)current=current->prev;
            return*this;
        }
        bool operator!=(const Iterator&other)const
        {
            return current!=other.current;
        }
        Node*getNode()const
        {
            return current;
        }
    };
    Container():head(nullptr),tail(nullptr),size(0) {}
    ~Container()
    {
        Node*curr=head;
        while(curr!=nullptr)
        {
            Node*nextNode=curr->next;
            delete curr;
            curr=nextNode;
        }
    }
    template<typename Compare>
    void sort(Compare comp)
    {
        if(size<=1)return;

        for(Node*i=head; i!=nullptr; i=i->next)
        {
            for(Node*j=i->next; j!=nullptr; j=j->next)
            {
                if(comp(j->data,i->data))
                {
                    swap(i->data,j->data);
                }
            }
        }
    }

    int getSize()const
    {
        return size;
    }
    bool isEmpty()const
    {
        return size==0;
    }

    Iterator begin()const
    {
        return Iterator(head);
    }
    Iterator end()const
    {
        return Iterator(nullptr);
    }

    void insertAtBeginning(T val)
    {
        Node*newNode=new Node(val);
        if(isEmpty())
        {
            head=tail=newNode;
        }
        else
        {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        size++;
    }

    void insertAtEnd(T val)
    {
        Node*newNode=new Node(val);
        if(isEmpty())
        {
            head=tail=newNode;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        size++;
    }

    void insertAtPosition(int index,T val)
    {
        if(index<0 || index>size)
        {
            cout<<"Invalid Position!\n";
            return;
        }
        if(index==0)
        {
            insertAtBeginning(val);
            return;
        }
        if(index==size)
        {
            insertAtEnd(val);
            return;
        }

        Node*curr=head;
        for(int i=0; i<index -1; ++i)
        {
            curr=curr->next;
        }
        Node*newNode=new Node(val);
        newNode->next=curr->next;
        newNode->prev=curr;
        curr->next->prev=newNode;
        curr->next=newNode;
        size++;
    }
    void removeAtPosition(int index)
    {
        if(index<0 || index>=size || isEmpty())
        {
            cout<<"Invalid Position or Empty Container!\n";
            return;
        }
        Node*toDelete=head;
        if(index==0)
        {
            head=head->next;
            if(head)head->prev=nullptr;
            else tail=nullptr;
        }
        else if(index==size-1)
        {
            toDelete=tail;
            tail=tail->prev;
            tail->next=nullptr;
        }
        else
        {
            for(int i=0; i<index; ++i)
            {
                toDelete=toDelete->next;
            }
            toDelete->prev->next=toDelete->next;
            toDelete->next->prev=toDelete->prev;
        }
        delete toDelete;
        size--;
    }
    bool removeByValue(T val)
    {
        Node*curr=head;
        int index=0;
        while(curr!=nullptr)
        {
            if(curr->data==val)
            {
                removeAtPosition(index);
                return true;
            }
            curr=curr->next;
            index++;
        }
        return false;
    }

    Node*search(T val)const
    {
        Node*curr=head;
        while(curr!=nullptr)
        {
            if(curr->data==val)
                return curr;
            curr=curr->next;
        }
        return nullptr;
    }
    };


#endif // CONTAINER_H
