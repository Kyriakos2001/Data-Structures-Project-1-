typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *cursor; 
    int size;     
} CircularList;
