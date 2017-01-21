#include  <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
#define size1 3
struct DataItem{
int key;
int data;};

struct DataItem* hashArray[size1];//this is the table as an array
    int hash1(int key)
    {
    return key%size1;
    }
    struct DataItem *search1(int key)//a program that returns a pointer of type DataItem
    {
        int index=hash1(key);//gets the index with the has1 function
        while(hashArray[index]!=NULL)
        {
            if(hashArray[index]->key==key)
                return hashArray[index];
            //if not foound
            index++;
            index=index%size1;//look from 0
        }
        return NULL;
    }
    void insertInTable(struct DataItem *item)
    {

        int index=hash1(item->key);
        int i=0;
        while(i<size1&&hashArray[index]!=NULL)
        {
            index++;
            index%=size1;
            i++;
        }
        if(hashArray[index]==NULL)hashArray[index]=item;
        else
            {
                cout<<"table is full\n";
                return;
            }
    }
    void Delete(struct DataItem *item)
    {
        int index=hash1(item->key);

        while(hashArray[index]->key!=item->key)//key is unique not the data
            {
            index++;
            index%=size1;
            }
            hashArray[index]=NULL;//data is deleted
    }
    void show()
    {
        for(int i=0;i<size1;i++)
            if(hashArray[i]!=NULL)
            printf("value: %d ,key %d\n",hashArray[i]->data,hashArray[i]->key);
    }
int main()
{
int n;
   cin>>n;
   int i=0;
   int key1,data1;
   while(i<n)
   {
       cin>>data1>>key1;
       struct DataItem * item =(struct DataItem*)malloc(sizeof(struct DataItem));
       item->data=data1;
       item->key=key1;
insertInTable(item);
i+=1;
   }
   show();
    return 0;
}
