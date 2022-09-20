struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode *Head;
typedef struct ListNode *Node;
typedef int index;

// basic method
Head createEmptyList();
Node createNode(int); //生成新节点
Node getLastNode(Head); 

Node findNodeByIndex(index, Head); //根据index找Node
Node findNodeByVal(int, Head); //找到val对应的节点
Node findPreNode(Node, Head); //找到前一个节点

void insertTail(int, Head); //尾插
void insertHead(int, Head); //头插
void insertIndex(int, index, Head); //插入index位置

void deleteNode(Node, Head);
void freeNode(Node);

void printList(Head); //打印整个list

//advanced method
Head reverseList(Head);