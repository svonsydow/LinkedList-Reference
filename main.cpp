#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

Node* newNode(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//adding node at the head of the list
void pushFront(Node** head, int new_data)
{
    auto* newNode = new Node;
    newNode->data = new_data;
    newNode->next = (*head);
    newNode->prev = NULL;


    if ((*head) != NULL)
        (*head)->prev = newNode;
    (*head) = newNode;
}
//adding a node that is neither the head or tail
void pushBetween(struct Node* prev_node, int new_data)
{
    //check if prev node is null
    if (prev_node == NULL) {
        cout<<"Previous node is required , it cannot be NULL";
        return;
    }

    struct Node* newNode = new Node;

    newNode->data = new_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

//insert a new node at the end of the list
void pushEnd(struct Node** head, int new_data)
{

    struct Node* newNode = new Node;
    struct Node* last = *head;

    newNode->data = new_data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return;
}

//deleting a node from a doubly linked list
void deleteNode(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    //delete head node.
    if (*head_ref == del)
        *head_ref = del->next;

    //delete if node is not the tail
    if (del->next != NULL)
        del->next->prev = del->prev;

    //delete if node is not the head.
    if (del->prev != NULL)
        del->prev->next = del->next;

    //reallocate memory
    free(del);
    return;
}

//Adds 2 linked lists via a vector
Node* addTwoLists(Node* first, Node* second)
{
        Node* res;
        vector<int>v;
        while(first!=NULL) {
            v.push_back(first->data);
            first = first->next;
        }
        while(second!=NULL)
        {
            v.push_back(second->data);
            second = second->next;
        }

    // Print the vector
    cout << "Elements from both lists: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // Find the sum of the vector
    cout << "Sum of both lists = " << accumulate(v.begin(), v.end(), 0) << endl;

    return 0;
    }

//Print list
void printList(Node* node)
{
    struct Node* last;

    while (node != NULL) {
        cout<<node->data << ", ";
        last = node;
        node = node->next;
    }
    if(node == NULL);

}

int main(void)
{


    Node* firstSum = NULL;
    Node* secondSum = NULL;

    //head of first list
    cout << "First doubly list: " << endl;
    pushFront(&firstSum, 10000);
    pushBetween(firstSum, 500);
    pushEnd(&firstSum, 500);
    cout << "First List: ";
    printList(firstSum);
    cout << endl;
    cout << endl;


    //head of second list
    cout << "Second doubly list: " << endl;
    pushFront(&secondSum, 800);
    pushEnd(&secondSum, 200);
    cout << "Second List: ";
    printList(secondSum);
    cout << endl;
    cout << endl;

    // Add the two lists
    addTwoLists(firstSum, secondSum);
    cout << endl;
    cout << "Deleted head node from first list: ";
    deleteNode(&firstSum, firstSum);
    cout << endl;
    addTwoLists(firstSum, secondSum);


    return 0;
}