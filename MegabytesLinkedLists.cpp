template<typename t>
class Node{
public:
    Node<t>* previous;
    Node<t>* next;
    t* data;

    Node(t* data, Node<t>* previous = nullptr): data(data), next(nullptr), previous(previous){}
};

template<typename t>
class LinkedList{
public:
    Node<t>* head;
    Node<t>* cursor;
    Node<t>* tail;
    int count;


    LinkedList():head(nullptr), cursor(nullptr), count(0){
        
    }

    LinkedList(t* data): head(Node(data)), count(1){

    }


    void resetCursor(bool resetToHead = true){
        if(!resetToHead){
            cursor = tail;
            return;
        }
        cursor = head;

    }

    void operator++(){
        cursor = cursor->next();
        if(cursor == nullptr){
            resetCursor();
        }
        return cursor->previous();
    }

    void prepend(t* data){
        ++count;
        Node<t>* newHead = new Node(data);
        newHead->previous = nullptr;
        newHead->next = head;
        head->previous = newHead;
        head = newHead;
        
    }


    void prepend(Node<t>* node){
        ++count;
        node->previous = nullptr;
        node->next = head;
        head->previous = node;
        head = node;
    }

    void append(t* data){
        ++count;
        Node<t>* newNode = new Node(data);
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void append(Node<t>* node){
        ++count;
        node->previous = tail;
        tail->next = node;
        tail = node;
    }
};



