#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>

struct ListNode 
{

    int val;
    ListNode *next;
    
    //ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {} 
     
};

#endif