/*
24题，题目：两两交换链表中的节点

题目描述：
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。你不能只是单纯改变节点内部的值，而是需要实际进行节点交换。

示例：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
*/
// 添加链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    // 新建一个头结点，方便操作
    ListNode port(0);
    port.next = head;
    ListNode* curr = &port;
    
    while (curr->next && curr->next->next) {
        ListNode* first = curr->next;
        ListNode* second = first->next;
        
        // 交换相邻节点
        curr->next = second;
        first->next = second->next;
        second->next = first;
        
        curr = first;// 向后跳2个节点
    }
    return port.next;
}