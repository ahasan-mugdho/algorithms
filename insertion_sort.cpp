void insertion_sort(int array[],int size)
{
    int i,j,item;
    for(i=1;i<size;i++)
    {
        item=array[i];
        j=i-1;
        while(j>=0&&array[j]>item)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=item;

    }
}
