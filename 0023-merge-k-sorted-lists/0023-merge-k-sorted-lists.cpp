/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& list) {
        ListNode* cur = new ListNode;
        ListNode* ans = cur;
        int sz = list.size();
        while(1) {
            int mn = INT_MAX;
            int idx = -1;
            for(int i = 0; i < sz; i++) {
                if(list[i] == NULL) continue;
                if(list[i]->val <= mn) {
                    mn = list[i]->val;
                    idx = i;
                }
            }
            if(idx == -1) break;
            cur->next = list[idx];
            cur = cur -> next;
                
            list[idx] = list[idx] -> next;
            
        }
        ans = ans -> next;
        return ans;
    } 
};