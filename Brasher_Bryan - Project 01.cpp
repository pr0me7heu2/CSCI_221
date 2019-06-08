// Brasher, Bryan R
// 08-JUN-2019
// Project 1

/* This program ...
 * */

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <limits>

using namespace std;

void reverse(char* str);
// Precondition: str is declared C-string
// Postcondition: The C-string is reversed

string* addEntry(string* dynamicArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line followed by its index

int main()
{

    cout << "Welcome to Project 01" << endl;
    cout << "\n";

    // test of reverse funciton
    cout << "First we will test the reverse function." << endl;

    char line_even[100];

    //validate user input to ensure even length
    do {
        cout << "Enter a line to reverse with an even length:" << endl;
        cin.getline(line_even,100);
    } while (strlen(line_even) % 2 != 0);

    reverse(line_even);

    cout << "The reverse of that is:" << line_even << endl;

    char line_odd[100];

    //validate user input to ensure odd length
    do {
        cout << "Enter a line to reverse with an odd length:" << endl;
        cin.getline(line_odd,100);
    } while (strlen(line_odd) % 2 == 0);

    reverse(line_odd);

    cout << "The reverse of that is:" << line_odd << endl;

    //testing of add and remove functions for dynamic arrays

    cout << "\n";
    cout << "Now we will test the add and delete functions for dynamic arrays." << endl;

    int size;

    cout << "How many names do you want to input?" << endl;
    cin >> size;

    while (cin.fail())  //validation to ensure only int entered
    {
        cout << "Invalid entry.  How many names do you want to input?" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), ' ');
        cin >> size;
    }

    string *names = new string[size];  //create new pointer to array size of size

    cout << "Enter in " << size << " names separated by spaces." << endl;

    for (int i=0; i < size; i++)  //fill each index with user input
    {
        cin >> names[i];
    }

    cout << "Initial list:" << endl;  //print out initial list
    print(names, size);

    string new_name; // temp

    cout << "Enter a name to add" << endl;

    cin >> new_name;

    names = addEntry(names, size, new_name); //adds name

    cout << "Enter another name to add" << endl;

    cin >> new_name;

    names = addEntry(names, size, new_name); //adds nane

    cout << "After adding names:" << endl;

    print(names, size);

    cout << "Pick a name to delete that is on the list" << endl;

    cin >> new_name;

    names = deleteEntry(names, size, new_name);

    cout << "Try and delete a name that is not on the list already." << endl;

    cin >> new_name;

    names = deleteEntry(names, size, new_name);

    cout << "After deletions, the list looks like this:" << endl;

    print(names, size);


    return 0;
}

void reverse(char* str)
{
    int length;
    char *front, *rear, temp;

    // Get the length of the string
    length = strlen(str);

    // Set the front and rear
    // initially to start of string
    front = str;
    rear = str;

    // Move the rear to the last character
    for (int i = 0; i < length - 1; i++)
        rear++;

    // Swap the char from start and end
    // index using front and rear
    for (int i = 0; i < length / 2; i++) {

        // swap character
        temp = *rear;
        *rear = *front;
        *front = temp;

        // update pointers positions
        front++;
        rear--;
    }
}

string* addEntry(string* dynamicArray, int& size, string newEntry)
{
   string *newArray = new string[size + 1];  //creates new array size+1 local to scope

   for (int i=0; i < size; i++)  //copy all entries from old array into new
   {
       newArray[i] = dynamicArray[i];
   }

   newArray[size] = newEntry;  //adds new entry
   size++; //increment size for consistency

   delete [] dynamicArray;

   return newArray;

}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    string *result = dynamicArray;  //point result to original array

    int index_of_entry_to_delete = -1; //index will be >=0 if value is found

    for (int i=0; i < size; i++)
    {
        if (dynamicArray[i] == entryToDelete)  //linear search for entry's index
        {
            index_of_entry_to_delete = i;
            break;
        }
    }

    if (index_of_entry_to_delete == -1)  //i.e. not found
    {
        return result;  //equal to original array
    }
    else
    {
        result = new string[size-1];  //point result to new array size n-1
        int index_new_array(0);   //create starting index

        for(int i=0; i < size; i++)
        {
            if (i!=index_of_entry_to_delete)
            {
                result[index_new_array] = dynamicArray[i];
                index_new_array++;
            }
            else
            {
                // i == index_of_entry_to_delete i.e. skip
            }
        }
        size--;
        delete [] dynamicArray;
    }
    return result;
}

void print(const string* dynamicArray, int size)
{
    for (int i=0; i < size; i++)
    {
        cout << i << ":" << dynamicArray[i] << endl;
    }
    cout << endl;
}