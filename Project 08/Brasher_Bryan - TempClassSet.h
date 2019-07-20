// Brasher, Bryan R
// 19-JUL-19
// Project 08

// interface file for template-based class that implements a set of items

#ifndef TEMPCLASSSET_H

#define TEMPCLASSSET_H

#include <cstdlib>
#include <fstream>

using namespace std;



namespace BRASHERTEMPCLASSSET {

    template<class ItemType>

    class set {
    public:
        set(); // default constructor
        set(const set<ItemType>& other); // copy constructor
        ~set(); //destructor
        void add(ItemType newItem); //add item to array pointed to by items
        void remove(ItemType delItem); //removes item from array pointed to by items
        int get_size(); // returns size of array pointed to by items
        bool contains(ItemType hasItem); //returns True if item contained in array; else False
        ItemType* new_copy(); // returns pointer to array with each item in set and deallocate memory
        void operator = (const set<ItemType>& right_side);  // overloaded operator
                                                // copies over corresponding member variables

        template<class T>  // not sure I understand WHY friends can't have the same template type
        friend ostream& operator <<(ostream& outs, const set<T>& object); // to facilitate printing of set

    private:
        ItemType *items;
        int size;
    };
}

#endif