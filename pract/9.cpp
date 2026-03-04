#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

void append(ListNode*& head, int val) {
    if(!head) { head = new ListNode{val, nullptr}; return; }
    ListNode* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = new ListNode{val, nullptr};
}

struct PolyTerm {
    double coef;
    int exp;
    PolyTerm* next;
};

void addTerm(PolyTerm*& poly, double c, int e) {
    if(!poly || poly->exp < e) { poly = new PolyTerm{c, e, poly}; return; }
    PolyTerm* temp = poly;
    while(temp->next && temp->next->exp > e) temp = temp->next;
    temp->next = new PolyTerm{c, e, temp->next};
}

void printPoly(PolyTerm* p) {
    while(p) {
        cout << p->coef << "x^" << p->exp << (p->next ? " + " : "");
        p = p->next;
    }
    cout << endl;
}

int main() {
    ListNode* myList = nullptr;
    append(myList, 10); append(myList, 20);
    
    PolyTerm* P1 = nullptr;
    addTerm(P1, 3.0, 2); 
    addTerm(P1, 2.0, 1); 
    addTerm(P1, 1.0, 0); 
    
    cout << "Polinom P1: ";
    printPoly(P1);
    while(P1) { PolyTerm* t = P1; P1 = P1->next; delete t; }
    while(myList) { ListNode* t = myList; myList = myList->next; delete t; }

    return 0;
}