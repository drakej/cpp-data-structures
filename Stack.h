#ifndef STACK
#define STACK

typedef string StackElement;

class Stack
{
public:
    Stack();

    Stack(const Stack &original);

    ~Stack();

    bool empty() const;

    int size() const;

    void push(const StackElement &value);

    void display(ostream &out, int setwidth) const;

    StackElement top() const;

    StackElement pop();

private:
    class Node
    {
    public:
        StackElement data;
        Node *next;
        Node(StackElement value, Node *link = 0) : data(value), next(link) {}
    };
    typedef Node *NodePointer;
    NodePointer myTop;
};

#endif
