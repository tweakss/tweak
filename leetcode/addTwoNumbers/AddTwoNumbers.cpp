#include <iostream>
#include <cmath>
#include "LinkedList.h"
//#include <stdio.h>

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main()
{
    //[2,4,3]

    ListNode head_l1(5); 
    // ListNode node_l1(4);
    // ListNode tail_l1(3);
    
    //[5,6,4]
    ListNode head_l2(5); 
    // ListNode node_l2(6);
    // ListNode tail_l2(4);

    // head_l1.next = &node_l1;
    // node_l1.next = &tail_l1;
    
    // head_l2.next = &node_l2;
    // node_l2.next = &tail_l2;

    ListNode* head_l1_ptr = &head_l1;
    ListNode* current_l1 = &head_l1;
    ListNode* head_l2_ptr = &head_l2;
    ListNode* current_l2 = &head_l2;
    cout << "l1: ";
    while(current_l1 != nullptr)
    {
        cout << current_l1->val << " ";
        current_l1 = current_l1->next;
    }
    cout << endl;
    
    cout << "l2: ";
    while(current_l2 != nullptr)
    {
        cout << current_l2->val << " ";
        current_l2 = current_l2->next;
    }
    cout << endl;
    

    ListNode* result = nullptr;
    result = addTwoNumbers(head_l1_ptr, head_l2_ptr);
    //cout << result->val << " " << result->next->val << " " << result->next->next->val;

    cout << "result->next: " << result->next << endl;
    cout << "result = " << result << endl;
    while(result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
        // if(result->next == nullptr)
        //     cout << result->val; 
    }
    cout << endl;
    
    
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int addOne = 0;
    
    ListNode* newNode = nullptr;
    ListNode* currentNode = nullptr;
    ListNode* headNode = nullptr;


    while((l1 != nullptr) || (l2 != nullptr))
    {
        //Getting l1, l2 value and adding
        
        newNode = new ListNode(0);
        if(l1 != nullptr)
        {
            newNode->val += l1->val;
            
        }

        if(l2 != nullptr)
        {
            newNode->val += l2->val;
        }
        
        //Carrying
        //If > 9 then addOne
        if(addOne)
        {
            newNode->val += 1;
        }
        addOne = 0; //reset
        
        if(newNode->val > 9)
        {
            addOne = 1;
            newNode->val = newNode->val -10;   
        }

        //Linking
        
        if(headNode == nullptr)
        {
            headNode = newNode;
            currentNode = newNode;
        }

        if(newNode != headNode)
        {
            currentNode->next = newNode; //point currentNode to the newly created node
            currentNode = newNode; //assign currentNode to the just created newNode
        }
        
        //Point l1, l2 to next node
        cout << "Pointing l1,l2 to next nodes" << endl;
        if(l1 != nullptr)
            l1 = l1->next;
        cout << "l1: " << l1 << endl;
        if(l2 != nullptr)
            l2 = l2->next;
        cout << "l2: " << l2 << endl;
    }

    //When l1,l2 = null and carry is present
    if(addOne)
    {
        newNode = new ListNode(0);
        newNode->val += 1;
        currentNode->next = newNode;
        currentNode = newNode;
    }

    return headNode;
    


}