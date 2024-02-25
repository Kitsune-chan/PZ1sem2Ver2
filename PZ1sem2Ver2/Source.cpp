#include <stdio.h>
#include <iostream>


struct List {
    List* next;
    char str;
};


List* AddElementList(char letter, List* p)
{

    List* newItem = new List;

    p->next = newItem;
    newItem->str = letter;
    newItem->next = NULL;

    return newItem;
}

int Input(FILE* ptr, List* list)
{
    int flag = 1;
    char letter = '0';


    while (letter != '.')
    {
        fscanf_s(ptr, "%c", &letter, 1);
        printf_s("%c ", letter);
        list = AddElementList(letter, list);
    }

    fclose(ptr);

    return flag;

}

int CountElements(List* list)
{
    int flag = 0;
    while (list != NULL)
    {
        flag++;
        list = list->next;
    }

    return flag;

}

int Output(List* Letters, int flag)
{
    FILE* resFile;

    fopen_s(&resFile, "result.txt", "w+");
    if (resFile != NULL) {
        if ((flag % 2) == 1)
        {
            Letters = Letters->next;
            while (Letters != NULL)
            {
                fputc(Letters->str, resFile);
                Letters = Letters->next->next;
            }
        }
        else
        {
            Letters = Letters->next->next;
            while (Letters != NULL)
            {
                fputc(Letters->str, resFile);
                Letters = Letters->next->next;
            }
        }
    }
    else {
        printf_s("Could not open file result.txt\n");
    }

    return 0;
}

int main()
{
    List* list;
    FILE* ptr;
    int flag;

    setlocale(LC_ALL, "Russian");

    fopen_s(&ptr, "Test.txt", "r");

    list = new List;
    list->next = NULL;


    Input(ptr, list);

    flag = CountElements(list);

    Output(list, flag);

    return 0;
}
