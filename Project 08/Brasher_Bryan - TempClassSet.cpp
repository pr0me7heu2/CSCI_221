// Brasher, Bryan R
// 19-JUL-19
// Project 08

// implementation file for template-based class that implements a set of items

#include <cstdlib>
#include "Brasher_Bryan - TempClassSet.h"


using namespace std;

namespace BRASHERTEMPCLASSSET {

    template<class ItemType>
    // default constructor
    set<ItemType>::set() : items(NULL), size(0) {
    }

    template<class ItemType>
    // copy constructor
    set<ItemType>::set(const set<ItemType> &other) {
        size = other.size;
        items = other.new_copy(); //items points to dynamic array holding copy of array values
    }

    template<class ItemType>
    // destructor
    set<ItemType>::~set() {
        if (items != NULL) // because trying to delete undefined pointer causes error
        {
            delete[] items;
        }
    }

    template<class ItemType>
    //add item to array pointed to by items
    void set<ItemType>::add(ItemType newItem) {
        if (!contains(newItem)) {
            ItemType *temp = new ItemType[size + 1];  // creates dynamic array size += 1
            for (int i = 0; i < size; i++) { //copy over old array
                temp[i] = items[i];
            }
            temp[size] = newItem;  //adds new item
            if (size > 0) {
                delete [] items;
            }
            items = temp; // items now points to new array
            size++;
        }
    }

    template<class ItemType>
    //removes item from array pointed to by items
    void set<ItemType>::remove(ItemType delItem) {
        if (contains(delItem)) {
            ItemType *temp = new ItemType[size - 1]; //creates array array size -+ 1
            for (int i = 0, j = 0; i < size; i++)  //iterate through old array
                if (items[i] != delItem) {
                    temp[j] = items[i];
                    j++; // ensures that no empty values exist in new array / run out of room
                }
            delete items;
            items = temp;
            size--;
        }
    }

    template<class ItemType>
    // returns size of array pointed to by items
    int set<ItemType>::get_size() {
        return size;
    }

    template<class ItemType>
    //returns True if item contained in array; else False
    bool set<ItemType>::contains(ItemType hasItem) {
        for (int i = 0; i < size; i++) {
            if (items[i] == hasItem) {
                return true;
            }
        }
        return false;
    }

    template<class ItemType>
    // returns pointer to array with each item in set and deallocate memory
    ItemType *set<ItemType>::new_copy() {
        ItemType *temp = new ItemType[size];
        if (size > 0) {
            for (int i = 0; i < size; i++) {
                temp[i] = items[i];
            }
        }
        return temp;
    }

    template<class ItemType>
    // copies over corresponding member variables
    void set<ItemType>::operator=(const set<ItemType> &right_side) {

        if (items != NULL) {
            delete[] items;  // deletes that items would otherwise be lost / avoids memory leak
        }
        size = right_side.size;
        items = right_side.new_copy();
    }

    template<class T>
    ostream &operator<<(ostream &outs, const set<T> &object) {

        if (object.items == NULL) {
            outs << "Set is empty" << endl;
        } else {
            for (int i = 0; i < object.size; i++) {
                outs << object.items[i] << endl;
            }
        }

        return outs;
    }
}
