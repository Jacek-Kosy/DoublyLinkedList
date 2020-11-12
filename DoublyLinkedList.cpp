// LittleProject2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <utility>

template <typename T>
class DLL {
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node* sent;
public:
    DLL() :sent(new Node{ T(), nullptr, nullptr }) {
        sent->next = sent->prev = sent;
    }
    bool empty() const;
    void push_front(const T& t) const;
    void push_back(const T& t) const;
    void print_fwd(std::ostream& str = std::cout) const;
    void print_rev(std::ostream& str = std::cout) const;
    Node* find_first(const T& e) const {
        Node* trav;
        trav = new Node;
        trav = sent->next;
        while (trav != sent) {
            if (trav->data == e) {
                trav = trav->next;
                return trav->prev;
            }
            trav = trav->next;
        }
        return nullptr;
    }
    Node* find_last(const T& e) const {
        Node* trav;
        trav = new Node;
        trav = sent->prev;
        while (trav != sent) {
            if (trav->data == e) {
                trav = trav->prev;
                return trav->next;
            }
            trav = trav->prev;
        }
    }
    void insert_after(Node* a, const T& t) const;
    void insert_before(Node* b, const T& t) const;
    void delete_node(const Node* d) const;
    void reverse() const;
    void clear() const;
    ~DLL();
};

int main()
{
    using std::cout; using std::endl; using std::string;
    DLL<std::string>* listStr = new DLL<std::string>();
    listStr->push_back("X");
    listStr->push_back("E");
    listStr->push_front("C");
    listStr->push_front("X");
    listStr->push_front("A");
    cout << "List printed in both directions: " << endl;
    listStr->print_fwd();
    listStr->print_rev();

    listStr->delete_node(listStr->find_first("X"));
    listStr->delete_node(listStr->find_last("X"));
    cout << "\nList after deleting X's: " << endl;
    listStr->print_fwd();

    listStr->insert_after(listStr->find_first("A"), "B");
    listStr->insert_before(listStr->find_last("E"), "D");
    cout << "List after inserting B and D:" << endl;
    listStr->print_fwd();

    cout << "Is list empty? " << std::boolalpha << listStr->empty() << endl;
    cout << "Clearing the list" << endl;
    listStr->clear();

    cout << "\nAdding one element(Z)" << endl;
    listStr->push_front("Z");

    cout << "Deleting the list" << endl;
    delete listStr;
    
}
template<typename T>
bool DLL<T>::empty() const
{
    if (sent->next == sent && sent->prev == sent)
        return true;
    else
        return false;
}
template<typename T>
    void DLL<T>::push_front(const T & t) const
    {
        Node* temp;
        temp = new Node;
        temp->data = t;
        temp->next = sent->next;
        temp->prev = sent;
        sent->next->prev = temp;
        sent->next = temp;
    }

    template<typename T>
    void DLL<T>::push_back(const T& t) const
    {
        Node* temp;
        temp = new Node;
        temp->data = t;
        temp->next = sent;
        temp->prev = sent->prev;
        sent->prev->next = temp;
        sent->prev = temp;
    }


    template<typename T>
    void DLL<T>::print_fwd(std::ostream& str) const
    {
        Node* trav;
        trav = new Node;
        trav = sent->next;
        while (trav != sent) {
            str << trav->data << " ";
            trav = trav->next;
        }
        str << std::endl;
    }

    template<typename T>
    void DLL<T>::print_rev(std::ostream& str) const
    {
        Node* trav;
        trav = new Node;
        trav = sent->prev;
        while (trav != sent) {
            str << trav->data << " ";
            trav = trav->prev;
        }
        str << std::endl;
    }

    template<typename T>
    void DLL<T>::insert_after(Node* a, const T& t) const
    {   
        Node* temp;
        temp = new Node;
        temp->data = t;
        temp->next = a->next;
        a->next = temp;
        temp->prev = a;
        temp->next->prev = temp;
    }

    template<typename T>
    void DLL<T>::insert_before(Node* b, const T& t) const
    {
        Node* temp;
        temp = new Node;
        temp->data = t;
        temp->prev = b->prev;
        b->prev = temp;
        temp->next = b;
        temp->prev->next = temp;
    }

    template<typename T>
    void DLL<T>::delete_node(const Node* d) const
    {
        std::cout << "Deleting: " << d->data << " ";
        d->prev->next = d->next;
        d->next->prev = d->prev;
        free((Node*)d);
    }

    template<typename T>
    void DLL<T>::reverse() const
    {
        Node* temp;
        Node* trav;
        temp = new Node;
        trav = new Node;
        trav = sent->next;
        while (trav != sent) {
            if (trav->prev != sent) {
                temp = trav->prev;
                temp->prev = trav->next;
                trav->next = temp;
                trav = trav->next;
            }
        }
    }

    template<typename T>
    void DLL<T>::clear() const
    {   
        Node* trav;
        Node* nextnode;
        trav = new Node;
        nextnode = new Node;
        trav = sent->next;
        while (trav != sent) {
            std::cout << "Deleting: " << trav->data << " ";
            nextnode = trav->next;
            free(trav);
            trav = nextnode;
        }
        sent->next = sent->prev = sent;

    }

    template<typename T>
    DLL<T>::~DLL()
    {
        this->clear();
        free(sent);
    }

