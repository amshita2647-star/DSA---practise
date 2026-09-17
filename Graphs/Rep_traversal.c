#include<stdio.h>
#include<malloc.h>
#define MAX 10
typedef struct node
{
    int vertex;
    int weight;
    struct node *next;
}node;
node* createnode(int v,int w)
{
   node* newNode = (node*)malloc(sizeof(node));
   newNode->vertex = v;
   newNode->weight = w;
   newNode->next = NULL;
   return newNode;
}
node* list[MAX];
void createadj_list(int n,int G[n][n])
{
    node* newnode;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(G[i][j]!=0)
            {
               newnode=createnode(j+1,G[i][j]);
               newnode->next = list[i+1];
               list[i+1] = newnode;
            }

        }
    }
}
void printlist(int n)
{
    for(int i=0;i<n;i++)
    {
        node* temp = list[i+1];
        printf("The adj vertices of %d ",i+1);
        while(temp != NULL)
        {
            printf("(%d,%d)",temp->vertex,temp->weight);
            temp=temp->next;
        }
        printf("\n\n");
    }
}
void BFS(int start)
{
    int visited[MAX]={0};
    int queue[MAX];
    int front =0;
    int rear =0;
    queue[rear++]=start;
    while(front < rear)
    {
        int u = queue[front++];
        printf("%d",u);
        visited[start]=1;
        node* temp = list[u];
        while(temp!= NULL)
        {
            if(visited[temp->vertex] != 1)
            {
                queue[rear++]=temp->vertex;
                visited[temp->vertex]=1;
            }
            temp=temp->next;
        }
    }
}

void DFS(int u,int visited[])
{
    visited[u]=1;
    printf("%d",u);
    node* temp = list[u];
    while(temp != NULL)
    {
        if(visited[temp->vertex] != 1)
        {
            DFS(temp->vertex,visited);
        }
        temp=temp->next;
    }
}
void print_atmost_k_distance(int start,int k)
{
    int visited[MAX]={0};
    int queue[MAX];
    int front =0;
    int rear =0;
    queue[rear++]=start;
    int level = 0;
    while(front < rear && level <= k)
    {
        int size = rear - front;
        printf("level %d :",level);
        for(int i=0;i<size;i++)
        {
            int u = queue[front++];
            node* temp = list[u];
            while(temp != NULL)
            {
                int v = temp->vertex;
                if(visited[v] != 1)
                {
                    printf("%2d",v);
                    queue[rear++]=v;
                    visited[v]=1;
                }
                temp = temp->next;
            }
        }
        level = level+1;
        printf("\n");
    }
}

int main()
{
    int G1[6][6]={{0,1,1,1,0,0},{1,0,0,0,0,1},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,0,1,1,0,1},{0,1,0,0,1,0}};
    int G2[6][6]={{0,5,6,9,0,0},{5,0,0,0,0,7},{6,0,0,0,11,0},{9,0,0,0,13,0},{0,0,11,13,0,3},{0,7,0,0,3,0}};
    int visited[MAX]={0};
    createadj_list(6,G1);
    printf("The BFS traversal :"); BFS(1);
    printf("\n");
    printf("The DFS traversal :"); DFS(1,visited);
    printf("\n\n\n");
    print_atmost_k_distance(1,2);
    printf("\n\n\n");
    printlist(6);

}
