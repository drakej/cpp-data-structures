#include <iostream>
#include <iomanip>
using namespace std;

#include "Stack.h"

Stack::Stack() : myTop(0) {}

// Stack copy constructor
Stack::Stack(const Stack &original)
{
    myTop = 0;
    if (!original.empty())
    {
        myTop = new Stack::Node(original.top());

        Stack::NodePointer lastPtr = myTop, origPtr = original.myTop->next;

        while (origPtr != 0)
        {
            lastPtr->next = new Stack::Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}

// Stack deconstructor
Stack::~Stack()
{
    Stack::NodePointer currPtr = myTop, nextPtr;

    while (currPtr != 0)
    {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

// Return if the stack is empty
bool Stack::empty() const
{
    return (myTop == 0);
}

// Return the size of the stack
int Stack::size() const
{
    int size = 0;
    Stack::NodePointer currPtr = myTop, nextPtr;
    while (currPtr != 0)
    {
        size++;
        currPtr = currPtr->next;
    }

    return size;
}

// Push StackElement (string) to the Stack
void Stack::push(const StackElement &value)
{
    myTop = new Stack::Node(value, myTop);
}

// Display towers to ostream with a setwidth if specified
void Stack::display(ostream &out, int setwidth = 0) const
{
    Stack::NodePointer ptr;
    for (ptr = myTop; ptr != 0; ptr = ptr->next)
    {
        out << std::setw(setwidth) << ptr->data << endl;
    }
}

// Return the top element without popping it (aka peek)
StackElement Stack::top() const
{
    if (!empty())
    {
        return (myTop->data);
    }
    else
    {
        // cerr << "*** Stack is empty -- no top value, so returning garbage... BLAH! ***\n";
        StackElement garbage;
        return garbage;
    }
}

// Remove and return the top element from the Stack
StackElement Stack::pop()
{
    if (!empty())
    {
        Stack::NodePointer ptr = myTop;
        StackElement data = myTop->data;
        myTop = myTop->next;
        delete ptr;
        return data;
    }
    else
    {
        // cerr << "*** Stack is empty -- nothing to pop, even a cherry... not funny ok, ok. ***" << endl;
        StackElement garbage;
        return garbage;
    }
}
