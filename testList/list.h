
typedef struct data_node
{
    int id;
    char name[16];
    struct data_node *next;
}DATANODE,*DATALIST;

/*
*用于想list中插入data
*@param list 要插入数据的链表
*@param data 要加入链表的数据
*/
void add(DATALIST list,DATANODE *data);

/*
*用于移除list中id为data_id的数据
*/
bool remove_by_id(DATALIST list,int data_id);

/*
*用于查找list中id为data_id的数据
*/
DATANODE *selet_node_by_id(DATALIST list,int data_id);

/*
*用于将list中id为data_id的元素的名字改为name_str
*/
void change_name_by_id(DATALIST list,int data_id,char *name_str);

