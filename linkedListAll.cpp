
#include <iostream>
#include <cstdlib>


using namespace std;

typedef int ElementType;


class Node {
private:
    ElementType data;
    Node* next;
public:

    // Constructor, can call with 0, 1, or 2 params.
    Node(int d = 0, Node* n = NULL) : data(d), next(n)  {}

    // display with address for class illustration purposeds
    void display_wadd(ostream& out) {
        out << dec << data << "{" << hex << this << "}";
    }

// Make Llist a friend so that we can access all Node objects info.
friend class LList;
};

class LList {
private:
    Node* first;
    int   mySize;
public:
    
    // Constructor.
    LList(): first(NULL), mySize(0) {}
    
    // Destructor
    ~LList();
    
    void insert(ElementType val, int pos);
    
    // erase the node at position pos.
    void erase(int pos); 
    
    // cout all the elements in the list
    void display(ostream &out) const;

    // insert at the end
    void push(ElementType e);

    // verify equality
    bool operator==(const LList& L) const;

    // assignment operator
    LList & operator= (const LList &L);

    // copy constructor 
    LList(const LList &L);

    // Given e, insert it in the list to keep its ascending order.
    // Assumes that the list is already in ascending order.
    void insertInOrder(ElementType e);
    
    // Returns true if the list is in ascending order
    bool isSorted() const;

    // This function assumes that both the invoking list and the
    // parameter list are sorted in ascending order. It will create
    // a third list that contains the elements of both in sorted order.
    LList merge(const LList & b) const;

};

ostream & operator<< (ostream &, const LList &);



LList::~LList() {
  while(mySize > 0) {erase(0);}
}

void LList::insert(ElementType val, int pos) {
    
    // Validate position
    if ( (pos < 0) || (pos > mySize) ) { 
        cerr << "Attempting insert at illegal position " << pos << endl;
        exit(1);
    }
    
    // create the new node to insert
    Node *n = new Node(val);
    
    if (pos == 0) { 
        // inserting at the first position
        n->next = first;
        first = n;
    } else {
        Node *curr = first;
        // move to the position
        for (int i=1; i<pos; i++) curr = curr->next;  
        n->next = curr->next;
        curr->next = n;
    }
    mySize++;    
}
    
void LList::erase(int pos) {

    // Validate position
    if ( (pos < 0) || (pos > mySize - 1) ) { 
        cerr << "Attempting delete at illegal position " << pos << endl;
        exit(1);
    }
    
    Node* tmp;
    if (pos == 0) { 
        // erasing the node at the first position
        tmp = first;
        first = first->next;
    } else {
        Node *curr = first;
        // move to the position before the node to be erased
        for (int i=1; i<pos; i++)   curr = curr->next;  
        tmp = curr->next;
        curr->next = curr->next->next;
    }
    delete tmp;

    mySize--; 
}
    
void LList::display(ostream &out) const {
    Node *curr = first;
    while (curr != NULL) {
        out << curr->data << " ";
        curr = curr->next;
    }
}



bool LList::operator==(const LList& L) const {
    if (mySize != L.mySize) return false; 
    Node *p = first;
    Node *q = L.first;
    while (p != NULL) {
        if (p->data != q->data) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}



void LList::push(ElementType e) {
    insert(e,mySize);
}

ostream & operator<< (ostream &out, const LList & L) {
    L.display(out);
    return out;
}

LList & LList::operator= (const LList &L) {
    if (this != &L) {                    //verify left!=right
        while(first != NULL) erase(0);    //erase left object

        Node *ptr = L.first;
        Node *rptr = this->first;      
        while(ptr != NULL) {             //traverse right obj
            Node *n = new Node(ptr->data,NULL);

            if (rptr == NULL) { this->first = n; }
            else              { rptr->next = n; }
            rptr = n;
            ptr = ptr->next;
        } 
        mySize = L.mySize;
    }
    return *this;
}

LList::LList(const LList &L) {
   Node *ptr = L.first;
   Node *rptr = this->first = NULL;

   while(ptr!=NULL) { //traverse the argument obj
      Node *n = new Node(ptr->data,NULL);

      if (rptr == NULL)  this->first = n; 
      else               rptr->next  = n; 
      rptr = n;
      ptr = ptr->next;
   } 
   mySize = L.mySize;
}


// Implement this one..
bool LList::isSorted() const {

} 

// Implement this one..
void LList::insertInOrder(ElementType val) {

}

// Implement this one..
LList LList::merge(const LList & b) const {

}



int main() {

  int position, element;
  LList L;
  string inst;
  
  cout << "$ ";
  while (cin >> inst && inst != "q") {
    if (inst == "i") {
      cin >> element >> position;
      cout << "Inserting " << element << " in position " << position << endl; 
      L.insert(element,position);
    }
    else if (inst == "e") {
      cin >> position; 
      cout << "Erasing element from position " << position << endl;
      L.erase(position);
    }
    else if (inst == "d")  cout << L << endl;
    else if (inst == "is") { 
      if (L.isSorted()) 
        cout << "List is sorted"<< endl;
      else
        cout << "List is NOT sorted"<< endl;
    }
    else if (inst == "io")  { 
      cin >> element; 
      cout << "Inserting " << element << " in order." << endl;
      L.insertInOrder(element);
    }
    else if (inst == "m")  { 
      LList M;
      M.insert(10, 0);
      M.insert(4, 0);
      M.insert(2, 0);
      cout << "Merging with the list " << M << endl;

      cout << "Resulting list is " << L.merge(M) << endl;
    }
    cout << "$ ";
  }
  return 0;
}

