// Brasher, Bryan R
// 01-JUL-2019
// Project 5
// implementation file

#include <iostream>
#include "Brasher_Bryan - Project05.h"

using namespace std;

namespace FHSULINKEDLIST {
    size_t list_length(const Node *head_ptr) {

        NodePtr here;
        here = const_cast<NodePtr>(head_ptr);

        size_t count(0);

        while(here != NULL)
        {
            count++;
            here = here->link;
        }

        return count;
    }

    void list_head_insert(Node *&head_ptr, const Node::Item &entry) {
        NodePtr temp_ptr;
        temp_ptr = new Node;

        temp_ptr->data = entry;

        temp_ptr->link = head_ptr;
        head_ptr = temp_ptr;
    }

    void list_insert(Node *previous_ptr, const Node::Item &entry) {
        NodePtr temp_ptr;

        temp_ptr = new Node;

        temp_ptr->data = entry;

        temp_ptr->link = previous_ptr->link;

        previous_ptr->link = temp_ptr;
    }

    Node* list_search(Node* head_ptr, const Node::Item& target) {
        NodePtr temp_ptr;

        if (head_ptr == NULL) {
            return NULL;
        }

        for(temp_ptr = head_ptr; temp_ptr != NULL; temp_ptr = temp_ptr->link) {
            if (temp_ptr->data == target) {
                return temp_ptr;
            }
        }
        return NULL;
    }

    Node* list_locate(Node* head_ptr, size_t position) {
        NodePtr temp_ptr;

        temp_ptr = head_ptr;

        size_t count(1);

        while(temp_ptr != NULL) {
            if (count == position) {
                return temp_ptr;
            }
            else {
                temp_ptr = temp_ptr->link;
                count++;
            }
        }

        return NULL;

    }

    void list_head_remove(Node *&head_ptr) {
        NodePtr temp_ptr;

        temp_ptr = head_ptr;

        head_ptr = temp_ptr->link;

        delete temp_ptr;
    }

    void list_remove(Node *previous_ptr) {
        NodePtr temp_ptr;

        temp_ptr = previous_ptr->link;

        previous_ptr->link = temp_ptr->link;

        delete temp_ptr;
    }

    void list_clear(Node *&head_ptr) {
        NodePtr current = head_ptr;
        NodePtr next;

        while (current != NULL) {
            next = current->link;
            delete current;
            current = next;
        }

     head_ptr = NULL;

    }

    void list_copy(Node* source_ptr, Node*& head_ptr) {
        NodePtr next, current;

        next = new Node;
        head_ptr = next;
        current = head_ptr;

        if (source_ptr == NULL) {
            head_ptr = NULL;
        }

        head_ptr->data = source_ptr->data;

        while(source_ptr->link != NULL) {
            source_ptr = source_ptr->link;
            next = new Node;
            current->link = next;
            next->data = source_ptr->data;
            current = next;
        }

        next->link = NULL;
    }

    size_t list_occurrences(Node* head_ptr, const Node::Item& target) {
        NodePtr temp_ptr;
        size_t count(0);

        if (head_ptr == NULL) {
            return 0;
        }

        for(temp_ptr = head_ptr; temp_ptr != NULL; temp_ptr = temp_ptr->link) {
            if (temp_ptr->data == target) {
                count++;
            }
        }
        return count;
    }

    void list_tail_attach(Node*& head_ptr, const Node::Item& entry) {
        NodePtr temp_ptr, new_ptr;

        new_ptr = new Node;

        new_ptr->data = entry;

        new_ptr->link = NULL;

        if (head_ptr == NULL)
        {
            head_ptr = new_ptr;
        }

        else {

            temp_ptr = head_ptr;

            while (temp_ptr->link != NULL) {
                temp_ptr = temp_ptr->link;
            }

            temp_ptr->link = new_ptr;

        }

    }

    void list_tail_remove(Node*& head_ptr) {
        NodePtr temp_ptr, lag_ptr;

        if (head_ptr->link == NULL) {
            delete head_ptr;
            head_ptr = NULL;  //empty list
            return;
        }

        temp_ptr = head_ptr;
        lag_ptr = head_ptr;

        while(temp_ptr->link != NULL) {
            temp_ptr = temp_ptr->link;
                if (temp_ptr->link == NULL) {
                    lag_ptr->link = NULL;
                }
                else {
                    lag_ptr = lag_ptr->link;
                }
        }

        delete temp_ptr;
    }

    Node* list_copy_front(Node* source_ptr, size_t n) {
        NodePtr head, next, current;
        size_t count(1);

        if (source_ptr == NULL) {
            head = NULL;
            return head;
        }

        if (list_length(source_ptr) < n) {
            n = list_length(source_ptr);
        }

        next = new Node;
        head = next;
        current = head;

        head->data = source_ptr->data;

        while(count < (n-1)) {
            source_ptr = source_ptr->link;
            next = new Node;
            current->link = next;
            next->data = source_ptr->data;
            current = next;
            count++;
        }

        source_ptr = source_ptr->link;
        next = new Node;
        current->link = next;
        next->data = source_ptr->data;
        next->link = NULL;

        return head;
    }
}
