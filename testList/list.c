#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*
*用于想list中插入data
*@param list 要插入数据的链表
*@param data 要加入链表的数据
*/
void add(DATALIST list,DATANODE *data)
{
    if(list == NULL)//初始化链表 才用头指针方式存储
    {
        list = (DATALIST)malloc(sizeof(DATANODE));
        memset(list,0,sizeof(DATANODE));
    }
    else
    {
        DATANODE *p = list;
        if(p->next == NULL)
        {
            p->next = data;
            printf(" first add \n");
        }
        else
        {
            DATANODE *q = p->next;
            while(q != NULL)
            {
                if(q->id > data->id) //由小到大插入
                {
                    data->next = q;
                    p->next = data;
                    printf("find seat \n");
                    break;
                }
                p = q;
                q = p->next;
            }
            if(q == NULL)   //data 的id当前最大
            {
                p->next = data;
                printf("insert to last seat\n");
            }
        }
    }
}

/*
*用于移除list中id为data_id的数据
*/
bool remove_by_id(DATALIST list,int data_id)
{
    bool res = false;
    if(list == NULL)
    {
        return res;
    }
    DATANODE *p = list;
    DATANODE *q = p->next;
    while(q != NULL)
    {
        if(q->id == data_id)
        {
            printf("remove find data\n");
            p->next = q->next;
            free(q);
            res = true;
            break;
        }
        p = q;
        q = p->next;
    }
    return res;
}

/*
*用于查找list中id为data_id的数据
*/
DATANODE *select_node_by_id(DATALIST list,int data_id)
{
    DATANODE *res = NULL;
    if(list == NULL)
    {
        return res;
    }
    res = list->next;
    while(res != NULL)
    {
        if(res->id == data_id)
        {
            break;
        }
        res = res->next;
    }
    return res;
}

/*
*用于将list中id为data_id的元素的名字改为name_str
*/
void change_name_by_id(DATALIST list,int data_id,char *name_str)
{
    DATANODE *node = select_node_by_id(list,data_id);
    strcpy(node->name,name_str);
}

