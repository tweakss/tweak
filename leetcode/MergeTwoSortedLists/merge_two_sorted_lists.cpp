#include <iostream>
#include "LinkedList.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

int main()
{
    ListNode head_l1(1); //1->2->4
    ListNode node_l1(2);
    ListNode tail_l1(4);

    head_l1.next = &node_l1;
    node_l1.next = &tail_l1;

    ListNode head_l2(1); //1->3->4
    ListNode node_l2(3);
    ListNode tail_l2(4);

    head_l2.next = &node_l2;
    node_l2.next = &tail_l2;

    ListNode* currentPtr_l1 = &head_l1;
    while(currentPtr_l1 != nullptr)
    {
        cout << currentPtr_l1->val << "->";
        currentPtr_l1 = currentPtr_l1->next;
    }
    cout << endl;

    ListNode* currentPtr_l2 = &head_l2;
    while(currentPtr_l2 != nullptr)
    {
        cout << currentPtr_l2->val << "->";
        currentPtr_l2 = currentPtr_l2->next;
    }
    cout << endl;

    currentPtr_l1 = &head_l1;
    currentPtr_l2 = &head_l2;
    ListNode* currentPtr_fl = mergeTwoLists(currentPtr_l1, currentPtr_l2);
    while(currentPtr_fl != nullptr)
    {
        cout << currentPtr_fl->val << "->";
        currentPtr_fl = currentPtr_fl->next;
    }
    cout << endl;


    return 0;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* mergedList_head;
    ListNode* mergedList_tail = nullptr;

    if((l1 == nullptr) && (l2 == nullptr))
    {
        return nullptr;
    }
    else if(l1 == nullptr)
    {
        return l2;
    }
    else if(l2 == nullptr)
    {
        return l1;
    }
    else if(l1->val <= l2->val)
    {
        mergedList_head = l1;
    }
    else if(l2->val < l1->val)
    {
        mergedList_head = l2;
    }
    
    do
    {
        if(l1 == nullptr)
        {
            cout << "Merging the rest of l1 to l2" << endl;
            mergedList_tail->next = l2;
            break;

        }
        else if(l2 == nullptr)
        {
            cout << "Merging the rest of l1 to l2" << endl;
            mergedList_tail->next = l1;
            break; 
        }
        else if(l1->val <= l2->val)
        {
            if(mergedList_tail != nullptr)
            {
                mergedList_tail->next = l1;
                cout << "Merged tail: " << mergedList_tail->val << " to l1: " << l1->val << endl;
            }
            mergedList_tail = l1;
            l1 = l1->next;
        }
        else if(l2->val < l1->val)
        {
            if(mergedList_tail != nullptr)
            {
                mergedList_tail->next = l2;
                cout << "Merged tail: " << mergedList_tail->val << " to l2: " << l2->val << endl;
            }
            mergedList_tail = l2;
            l2 = l2->next;
        }

    } while (l1 != nullptr || l2 != nullptr);


    return mergedList_head;
    
    
}