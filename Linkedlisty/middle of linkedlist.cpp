class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
    

    }
};



or 


class Solution {
public:
    int length(ListNode* head)
    {
        int len =0 ;
        while(head != NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int lambai = length(head);
        int ans = lambai/2;
        int count = 0;
        ListNode* temp = head;
        while(count < ans)
        {
            temp = temp ->next;
            count++;
        }
        return temp;
    }
};
