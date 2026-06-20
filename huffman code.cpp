#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq)
{
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));

    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;

    return node;
}

void printCodes(struct Node* root, int arr[], int top)
{
    if(root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if(root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if(!root->left && !root->right)
    {
        printf("%c : ", root->ch);

        for(int i = 0; i < top; i++)
            printf("%d", arr[i]);

        printf("\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    char ch[n];
    int freq[n];

    for(int i = 0; i < n; i++)
        scanf(" %c", &ch[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    struct Node* root = createNode('*', 0);

    root->left = createNode(ch[0], freq[0]);
    root->right = createNode(ch[1], freq[1]);

    int arr[100];

    printCodes(root, arr, 0);

    return 0;
}