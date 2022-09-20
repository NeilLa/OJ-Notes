#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

Head createEmptyList() {
    Head head = (struct ListNode*)malloc(sizeof(struct LinkNode*));
    head->next = NULL;
    return head;
}

Node createNode(int i) {
    Node new_node = (Node)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->val = i;
    return new_node;
}

Node getLastNode(Head head) {
    Node current_node;
    current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    return current_node;
}

Node findNodeByIndex(index n, Head head) {
    int current_index = 0;
    Node current_node = head;

    while (current_node->next != NULL) {
        if (current_index == n) {
            return current_node;
        }

        current_node = current_node->next;
        current_index++;
    }

    if (current_index == n) {
        return current_node;
    }

    return NULL;
}

Node findNodeByVal(int v, Head head) {
    Node current_node = head;

    while (current_node->next != NULL) {
        if (current_node->val == v) {
            return current_node;
        }

        current_node = current_node->next;
    }

    if (current_node->val == v) {
        return current_node;
    }
    return NULL;
}

Node findPreNode(Node node, Head head) {
    Node current_node = head;

    while (current_node->next != NULL) {
        if (current_node->next == node) {
            return current_node;
        }

        current_node = current_node->next;
    }

    return NULL;
}

void insertTail(int i, Head head) {
    Node new_node = createNode(i);
    Node last_node = getLastNode(head);
    last_node->next = new_node;
}

void insertHead(int i, Head head) {
    Node new_node = createNode(i);

    if (head->next != NULL) {
        Node second_node = head->next;
        head->next = new_node;
        new_node->next = second_node;
    } else {
        head->next = new_node;
    }
}

void insertIndex(int i, index n, Head head) {
    Node new_node = createNode(i);
    Node index_node = findNodeByIndex(n, head);

    if (index_node != NULL) {
        index_node->next = new_node;
    } else {
        printf("Invalid Index!\n");
    }
}

void deleteNode(Node node, Head head) {
    Node pre_node = findPreNode(node, head);
    Node next_node = node->next;

    pre_node->next = next_node;
    freeNode(node);
}

void freeNode(Node node) {
    free(node);
}

void printList(Head head) {
    Node current_node = head;
    while (current_node->next != NULL) {
        printf("%d->", current_node->val);
        current_node = current_node->next;
    }

    printf("%d\n", current_node->val);
}

//drive
int main () {
    Head head = createEmptyList();
    insertHead(5, head);
    insertTail(6, head);
    insertTail(7, head);

    printList(head);
    return 0;
}