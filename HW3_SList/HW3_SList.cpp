//
// This is the template for HW3. 
// We will implement a singly linked list (SLL) class and sort it. 
// 
// The node class is defined for you. 
// The singly linked list (SLL) class is partly defined. 
// Do not change the existing definitions. 
// 
// You have two major tasks: 
// 1. Complete five member functions of the SLL class. 
// 2. Complete merge sort based on the SLL data structure. 
// Detailed instructions are given below. 
// 
// Tip: to facilitate debugging, you may first implement a simple 
// add function (e.g., only add to head). This allows you to quickly 
// construct a list and test/debug other functions.
//
// 
#include <iostream>
using namespace std;
// -----------------------
// -----------------------
// Node Class Definition 
// -----------------------
// -----------------------
class Node {
private:
    int data;
    Node* link_next;
public:
    void SetData(int x);
    int GetData();
    void SetLink_Next(Node* ptr);
    Node* GetLink_Next();
    Node();
};
Node::Node() {
    data = 0;
    link_next = NULL;
}
void Node::SetData(int x) {
    data = x;
}
int Node::GetData() {
    return data;
}
void Node::SetLink_Next(Node* ptr) {
    link_next = ptr;
}
Node* Node::GetLink_Next() {
    return link_next;
}
// -------------------------------------
// -------------------------------------
// Singly Linked List Class Definition 
// -------------------------------------
// -------------------------------------
// The following is a partly defined singly linked class.  
// Its only private member is a head pointer -- you cannot add others. 
// It has multiple public member functions. 
// Four member functions are given to you. 
// Your job is to complete the following five member functions: 
// 
// *************
// 1. GetSize()
// *************
// This function returns the number of nodes in the list. 
// Below is an example. 
// 
// Example: 
// If list = 5, 7, 1, 3, 
// then GetSize() returns 4. 
//  
// 
// *************************
// 2. LinearSearch(int key)
// *************************
// This function performs linear search on the list with the given key.
// If key is not found or the list is empty, return -1. 
// If key is found, return location of the node holding that key. 
// Location will start from 0 and ends at n-1. 
// Below is an example. 
// 
// Example: 
// If list = 5, 7, 1, 3, then  
// LinearSearch(5) returns 0. 
// LinearSearch(1) returns 2. 
// LinearSearch(10) returns -1. 
// 
// 
// *************************
// 3. Add(int val, int idx)
// *************************
// This function adds a node with data "val" at location "idx". 
// Here, "idx" starts from 0 (head node) and ends at n-1 (tail node). 
// If the input "idx" is bigger than n-1, then add node to the tail. 
// Below are three examples. 
// 
// Example 1: 
// If list = 5, 7, 1, 2. 
// If we run Add(3,2), 
// then new list = 5, 7, 3, 1, 2. 
// 
// Example 2: 
// If list = 5, 7, 1, 2. 
// If we run Add(3,0), 
// then new list = 3, 5, 7, 1, 2. 
// 
// Example 3:  
// If list = 5, 7, 1, 2. 
// If we run Add(3,7) 
// then new list = 5, 7, 1, 2, 3. 
// (Here, "7" is bigger than n-1, so add "3" to the tail.)  
// 
// 
// *******************
// 4. Remove(int idx)
// *******************
// This function removes the node at location "idx". 
// Here, "idx" starts from 0 (head node) and ends at n-1 (tail node). 
// If the input "idx" is bigger than n-1, then remove the tail. 
// Below are three examples. 
// 
// Example 1: 
// If list = 5, 7, 1, 2. 
// If we run Remove(0), 
// then new list = 7, 1, 2. 
// 
// Example 2: 
// If list = 5, 7, 1, 2. 
// If we run Remove(2), 
// then new list = 5, 7, 2. 
// 
// Example 3: 
// If list = 5, 7, 1, 2. 
// If we run Remove(7), 
// then new list = 5, 7, 1. 
// (Here, "7" is bigger than n-1, so remove the tail. ) 
//
//
// *************
// 5. Reverse()
// *************
// This function reverses the current list. 
// If the list is empty or contains only one node, do nothing. 
// Below are three examples. 
// 
// Example 1: 
// If list is empty. 
// If we run Reverse(), 
// then new list is empty. 
// 
// Example 2: 
// If list = 5. 
// If we run Reverse(), 
// then new list = 5. 
// 
// Example 3: 
// If list = 5, 7, 1, 2. 
// If we run Reverse(), 
// then new list = 2, 1, 7, 5. 
//
// 
class SList {
private:
    Node* head;
public:
    // The following four functions are given to you. 
    // The SetHead and GetHead functions are only useful for merge sort.
    SList();
    void Print();
    void SetHead(Node* ptr);
    Node* GetHead();
    // You need to complete the following five functions.     
    int GetSize();
    int LinearSearch(int key);
    void Add(int val, int idx);
    void Remove(int idx);
    void Reverse();
};
SList::SList() {
    head = NULL;
}
void SList::Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->GetData() << endl;
        temp = temp->GetLink_Next();
    }
}
Node* SList::GetHead() {
    return head;
}
void SList::SetHead(Node* ptr) {
    head = ptr;
}
int SList::GetSize() {
    int count = 0;
    Node* ptr = head;
    while (ptr != NULL) {
        ++count;
        ptr = ptr->GetLink_Next();
    }
    return count;
}
int SList::LinearSearch(int key) {
    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->GetData() == key) {
            return 0;
        }
        ptr = ptr->GetLink_Next();
    }
    return -1;
}

void SList::Add(int val, int idx) {
    int size = GetSize();
    if (idx == 0) {
        Node* a = new Node();
        a->SetData(val);
        a->SetLink_Next(head);
        head = a;
        return;
    }
    if (idx >= size) {
        Node* a = new Node();
        a->SetData(val);
        a->SetLink_Next(NULL);

        Node* ptr = head;
        while (ptr->GetLink_Next() != NULL) {
            ptr = ptr->GetLink_Next();
        }

        ptr->SetLink_Next(a);
        return;
    }
    Node* temp = new Node();
    //set the data of the temp pointer equal
    //to the val.
    temp->SetData(val);
    Node* ptr = head;
    for (int i = 0; i < idx - 1; ++i) {
        ptr = ptr->GetLink_Next();
    }
    //set the link from the new node to the node 
    //after it. This makes sure that the list isn't 
    //cut off
    temp->SetLink_Next(ptr->GetLink_Next());
    //set the link from the previous ptr to the new 
    //node. 
    ptr->SetLink_Next(temp);


}
void SList::Remove(int idx) {
    int size = GetSize() - 1;
    Node* ptr = head;
    //removes the head node
    if (idx == 0) {
        head = ptr->GetLink_Next();
        return;
    }
    //remove the end node
    if (idx > size) {
        while (ptr->GetLink_Next()->GetLink_Next() != nullptr) {
            ptr = ptr->GetLink_Next();
        }
        delete ptr->GetLink_Next();
        ptr->SetLink_Next(nullptr);
        return;
    }
    //get to the right position to 
    //remove the ptr at idx
    for (int i = 0; i < idx - 1; ++i) {
        ptr = ptr->GetLink_Next();
    }
    //removes the link from mid pointer. ex. 1, 2, 3: in this 
    //case, 1 is the ptr, and ptr->GetLink_Next()->GetLink_Next()
    //is 3. By setting the link between these two, 2 becomes unlinked.
    ptr->SetLink_Next(ptr->GetLink_Next()->GetLink_Next());

}
void SList::Reverse() {
    Node* curr = head, * prev = NULL, * next = NULL;

    while (curr != NULL) {
        next = curr->GetLink_Next();
        curr->SetLink_Next(prev);
        prev = curr;
        curr = next;
    }
    head = prev;
}
//
// -----------
// Merge Sort  
// -----------
// The following is an incomplete merge sort function. 
// Its input is the head pointer of a singly linked list. 
// Its output is the head pointer of the sorted list. 
// We will test this function in the following way: 
// First, use your SList class to generate a singly linked list. 
// Then, retrive its head pointer and pass it to the merge sort function.
// Finally, get a new head pointer of the sorted list, pass it back to the list 
//class and print it.
// You can see the testing code in the main function (mode = 7)
// .........
// Your task is to design and implement this merge sort function 
// based on the singly linked list data structure. 
// No array or vector can be used. 
// Tip: it should be recursive. 
// 
// Helper function to find the middle of the list
Node* findMiddle(Node* head) {
    if (!head || !head->GetLink_Next()) return head;
    
    Node* slow = head;
    Node* fast = head->GetLink_Next();
    
    while (fast && fast->GetLink_Next()) {
        slow = slow->GetLink_Next();
        fast = fast->GetLink_Next()->GetLink_Next();
    }
    
    return slow;
}

// Helper function to merge two sorted lists
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    
    Node* result = nullptr;
    
    if (left->GetData() <= right->GetData()) {
        result = left;
        result->SetLink_Next(merge(left->GetLink_Next(), right));
    } else {
        result = right;
        result->SetLink_Next(merge(left, right->GetLink_Next()));
    }
    
    return result;
}

// Merge Sort function for linked list
Node* MergeSort(Node* head) {
    if (!head || !head->GetLink_Next()) {
        return head;  // Base case
    }
    
    // Find the middle point of the list
    Node* middle = findMiddle(head);
    Node* nextOfMiddle = middle->GetLink_Next();
    middle->SetLink_Next(nullptr);  // Split the list into two halves
    
    // Recursively sort both halves
    Node* left = MergeSort(head);
    Node* right = MergeSort(nextOfMiddle);
    
    // Merge the sorted halves
    return merge(left, right);
}

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->GetData() << " ";
        head = head->GetLink_Next();
    }
    cout << endl;
}

// Helper function to insert a new node at the beginning
void push(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetLink_Next(head);
    head = newNode;
}


int main()
{
    // 
    // The main function is given to you. 
    // It first constructs a singly linked list. 
    // It then tests your implemented member functions 
    // and the merge sort function. 
    // 
    SList x;
    int mode, value, idx, key, temp;
    cin >> mode >> value >> idx >> key;
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        x.Add(temp, 0);
    }
    switch (mode) {
    case 1: // check your add function with idx = 0
        x.Print();
        break;
    case 2: // check your GetSize function
        cout << x.GetSize();
        break;
    case 3: // check your LinearSearch function
        cout << x.LinearSearch(key);
        break;
    case 4: // check your add function with arbirary idx 
        x.Add(value, idx);
        x.Print();
        break;
    case 5: // check your remove function
        x.Remove(idx);
        x.Print();
        break;
    case 6: // check your reverse function 
        x.Reverse();
        x.Print();
        break;
    case 7: // check your merge sort function
        x.SetHead(MergeSort(x.GetHead()));
        x.Print();
        break;
    }
    return 0;
}