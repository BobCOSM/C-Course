#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//参数在传入时需要验证
static DATANODE *get_data(int id,char *name)
{
    DATANODE *data = (DATANODE*)malloc(sizeof(DATANODE));
    memset(data,0,sizeof(DATANODE));
    data->id = id;
    strcpy(data->name,name);
    data->next = NULL;
    return data;
}

static void print_list(DATALIST list)
{
    if(list == NULL)
    {
        return ;
    }
    DATANODE *p = list->next;
    while(p != NULL)
    {
        printf("id : %d,name : %s\n",p->id,p->name);
        p = p->next;
    }
}

static void print_data(DATANODE *data)
{
    printf("id : %d,name : %s\n",data->id,data->name);
}

int main()
{
    DATALIST list = (DATALIST)malloc(sizeof(DATANODE));
    memset(list,0,sizeof(DATANODE));
    DATANODE *data = get_data(12,"Bob");
    print_data(data);
    add(list,data);
    data = get_data(16,"Tom");
    print_data(data);
    add(list,data);
    data = get_data(13,"Jim");
    print_data(data);
    add(list,data);
    print_list(list);
    printf("\n select\n");
    data = select_node_by_id(list,13);
    print_data(data);
    printf("\nchange\n");
    change_name_by_id(list,12,"Bobby");
    print_list(list);
    printf("\nremove\n");
    remove_by_id(list,16);
    print_list(list);
    return 0;
}
