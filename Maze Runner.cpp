#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

template <class T>

class stack
{
private:
    struct Node
    {
    public:
        T data;
        Node *next;
        Node() { next = 0; }
        Node(T d, Node *n = 0)
        {
            next = n;
            data = d;
        }
    };

public:
    Node *top;
    int size;
    int max;
    stack(int m = 200)
    {
        top = 0;
        size = 0;
        max = m;
    }
    bool isempty() { return top == 0; }
    bool insert(T d)
    {
        if (size == max)
            return false;
        if (top == 0)
        {
            top = new Node(d);
            size++;
            return true;
        }
        top = new Node(d, top);
        size++;
        return true;
    }
    T pop()
    {
        T ele = top->data;
        Node *temp = top->next;
        delete top;
        top = temp;
        size--;
        return ele;
    }
    void print()
    {
        Node *temp = top;
        while (temp != 0)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
    void clear()
    {
        Node *temp = top;
        while (temp != 0)
        {
            temp = temp->next;
            delete top;
            top = temp;
        }
    }
    char t() { return top->data; }
};

void print2(stack<int> &row, stack<int> &col, stack<string> &stage)
{
    system("cls");
    cout << endl
         << "------------------YOU WON------------------" << endl
         << endl;

    while (!row.isempty() && !col.isempty())
    {
        cout << stage.pop() << "  "
             << "(" << row.pop() << "," << col.pop() << ")" << endl;
    }
    exit(0);
}

void print(char **map, int rows, int cols, int srow, int scol)
{
    system("cls");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (i == srow && j == scol)
                cout << "0";
            else
                cout << map[i][j];
    }
    cout << endl
         << endl;
}
void exit_ed()
{
    system("cls");
    cout << "            ----------YOU DIED----------" << endl;
    exit(0);
}
void exit_edP()
{

    cout << "            ----------YOU DIED----------" << endl;
    exit(0);
}

int game(int a, char **arr, int &rows, int &cols, int &srow, int &scol, stack<int> &row, stack<int> &col, stack<string> &stage)
{

    bool flag = true;
    char c;

    while (flag)
    {

        switch (c = _getch())
        {
        case 'w':

            if (srow - 1 != -1 && arr[srow - 1][scol] != 'X')
            {
                if (arr[srow - 1][scol] == 'D')
                {
                    exit_ed();
                    break;
                }
                else if (arr[srow - 1][scol] == 'G')
                {
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");

                    row.insert(srow - 1);
                    col.insert(scol);

                    return 1;
                }
                else if (arr[srow - 1][scol] == 'P')
                {
                    row.insert(srow - 1);
                    col.insert(scol);
                    return 2;
                }

                else
                {

                    arr[srow][scol] = '.';
                    srow = srow - 1;
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");
                    row.insert(srow);
                    col.insert(scol);

                    print(arr, rows, cols, srow, scol);
                    break;
                }
            }
            // else if (arr[srow + 1][scol] == 'X')
            // {
            //     break;
            // }
            else if (srow - 1 < 0)
            {

                break;
            }
            else if (arr[srow - 1][scol] == 'X')
            {
                break;
            }

        case 'a':

            if (arr[srow][scol - 2] != 'X' && scol - 2 != -2)
            {
                if (arr[srow][scol - 2] == 'D')
                {
                    exit_ed();
                    break;
                }
                else if (arr[srow][scol - 2] == 'G')
                {
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");
                    row.insert(srow);
                    col.insert(scol - 2);

                    return 1;
                }
                else if (arr[srow][scol - 2] == 'P')
                {
                    row.insert(srow);
                    col.insert(scol - 2);
                    return 2;
                }
                else
                {
                    arr[srow][scol] = '.';
                    scol = scol - 2;
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");
                    row.insert(srow);
                    col.insert(scol);

                    print(arr, rows, cols, srow, scol);
                    break;
                }
            }
            else if (scol - 2 == -2 || arr[srow][scol - 2] == 'X')
            {

                break;
            }

        case 's':

            if (srow + 1 != rows && arr[srow + 1][scol] != 'X')
            {
                if (arr[srow + 1][scol] == 'D')
                {
                    exit_ed();
                    break;
                }
                else if (arr[srow + 1][scol] == 'T')
                {

                    print2(row, col, stage);
                }
                else if (arr[srow + 1][scol] == 'G')
                {
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");

                    row.insert(srow + 1);
                    col.insert(scol);

                    return 1;
                }
                else if (arr[srow + 1][scol] == 'P')
                {
                    row.insert(srow + 1);
                    col.insert(scol);
                    return 2;
                }

                else
                {

                    arr[srow][scol] = '.';
                    srow = srow + 1;
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");
                    row.insert(srow);
                    col.insert(scol);

                    print(arr, rows, cols, srow, scol);
                    break;
                }
            }
            else if (srow + 1 == rows || arr[srow + 1][scol] == 'X')
            {

                break;
            }
            // else if (arr[srow + 1][scol] == 'X')
            // {
            // 	break;
            // }

            /*else if (arr[srow - 1][scol] == 'X')
            {
                break;
            }*/
        case 'd':

            if (arr[srow][scol + 2] != 'X' && scol + 2 != cols)
            {
                if (arr[srow][scol + 2] == 'D')
                {
                    exit_ed();
                    break;
                }
                else if (arr[srow][scol + 2] == 'G')
                {
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");
                    row.insert(srow);
                    col.insert(scol + 2);

                    return 1;
                }
                else if (arr[srow][scol + 2] == 'P')
                {
                    row.insert(srow);
                    col.insert(scol + 2);
                    return 2;
                }

                else
                {
                    arr[srow][scol] = '.';
                    scol = scol + 2;
                    if (a == 1)
                        stage.insert("stage 1");
                    else
                        stage.insert("stage 2");
                    row.insert(srow);
                    col.insert(scol);

                    print(arr, rows, cols, srow, scol);
                    break;
                }
            }
            else if (scol + 2 == cols || arr[srow][scol + 2] == 'X')
            {

                break;
            }
        }
    }
}

char **maze(char **arr, int rows, int cols, int srow, int scol)
{
    system("cls");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == '0')
            {
                arr[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == srow && j == scol)
                arr[i][j] = '0';
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j];
        }
    }
    return arr;
}

char **readfile(string a, int &rows, int &cols, int &srow, int &scol)
{

    ifstream ifstream_ob, obj;

    ifstream_ob.open(a, ios::in);

    char ch;
    int p = 0;

    while (ifstream_ob)
    {
        ch = ifstream_ob.get();
        if (p == 0)
        {

            rows = ch - '0';
        }
        if (p == 3)
        {

            cols = (ch - '0') * 2;
        }
        if (p == 5)
        {

            srow = ch - '0';
        }
        if (p == 8)
        {

            scol = (ch - '0') * 2;
        }

        p++;
    }
    p = 0;

    char **room;
    room = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        room[i] = new char[cols + 1];
    }

    int i = 0, j = 0;

    obj.open(a, ios::in);
    while (obj)

    {
        ch = obj.get();
        if (p > 9)
        {

            room[i][j] = ch;
            j++;
            if (j == cols)
            {
                j = 0;
                i++;
            }
        }
        p++;
    }

    obj.close();
    ifstream_ob.close();
    return room;
}
// void gasper(char **arr, int rows, int cols, int srow, int scol, stack<int> &row, stack<int> &col, stack<string> &stage)
// {
//     game(arr, rows, cols, srow, scol, row, col, stage);
// }

int portal(int &u)
{
    system("cls");

    char t;
    cout << "press T to toss the coin" << endl;
    t = _getch();
    /*srand(time(0));
    int x = (rand() % 2);*/
    int x = 0;
    if (x == 1)
    {
        cout << "You got heads" << endl;
        u++;
        return 3;
    }
    else
    {
        if (u == 0)
        {
            cout << "You got tails on the first try" << endl;
            exit_edP();
        }
        else
        {

            cout << "You got tails" << endl;

            u++;
            return 4;
        }
    }
}

int main()
{
    stack<int> row;
    stack<int> col;
    stack<string> stage;

    srand(time(0));
    int x = (rand() % 2);
    int u = 0;

    int y;
    char **room1, **room2;
    int rows, cols, srow, scol;
    room1 = readfile("room1.txt", rows, cols, srow, scol);
    int dsrow = srow;
    int dscol = scol;
    room2 = readfile("room2.txt", rows, cols, srow, scol);
    int dsrow2 = srow;
    int dscol2 = scol;

    if (x == 1)
    {
        room1 = readfile("room1.txt", rows, cols, srow, scol);
        room1 = maze(room1, rows, cols, srow, scol);
        y = game(x, room1, rows, cols, srow, scol, row, col, stage);

        if (y == 1)
        {
            room1 = readfile("room2.txt", rows, cols, dsrow2, dscol2);
            room1 = maze(room2, rows, cols, dsrow2, dscol2);
            y = game(0, room2, rows, cols, dsrow2, dscol2, row, col, stage);
        }
        if (y == 2)
        {
            int t = portal(u);
            if (t == 3)
            {
                srand(time(0));
                int r = (rand() % 2);
                if (r == 1)
                {
                    room1 = readfile("room2.txt", rows, cols, dsrow2, dscol2);
                    room1 = maze(room1, rows, cols, dsrow2, dscol2);
                    y = game(0, room1, rows, cols, dsrow2, dscol2, row, col, stage);
                }
                else
                {
                    room1 = readfile("room1.txt", rows, cols, dsrow2, dscol2);
                    room1 = maze(room1, rows, cols, dsrow2, dscol2);
                    y = game(0, room1, rows, cols, dsrow2, dscol2, row, col, stage);
                }
            }
            if (t == 4)
            {
                room1 = readfile("room1.txt", rows, cols, dsrow2, dscol2);
                room1 = maze(room1, rows, cols, srow, scol);
                y = game(0, room1, rows, cols, srow, scol, row, col, stage);
            }
        }
    }
    if (x == 0)
    {
        room2 = readfile("room2.txt", rows, cols, srow, scol);
        room2 = maze(room2, rows, cols, srow, scol);
        y = game(x, room2, rows, cols, dsrow2, dscol2, row, col, stage);
        if (y == 2)
        {
            int t = portal(u);
            if (t == 3)
            {
                srand(time(0));
                int r = (rand() % 2);
                if (r == 1)
                {
                    room2 = readfile("room2.txt", rows, cols, dsrow2, dscol2);
                    room2 = maze(room2, rows, cols, dsrow2, dscol2);
                    y = game(0, room2, rows, cols, dsrow2, dscol2, row, col, stage);
                }
                else
                {
                    room2 = readfile("room1.txt", rows, cols, dsrow2, dscol2);
                    room2 = maze(room2, rows, cols, dsrow2, dscol2);
                    y = game(0, room2, rows, cols, dsrow2, dscol2, row, col, stage);
                }
            }
            if (t == 4)
            {
                room2 = readfile("room2.txt", rows, cols, dsrow2, dscol2);
                room2 = maze(room2, rows, cols, dsrow2, dscol2);
                y = game(0, room2, rows, cols, dsrow2, dscol2, row, col, stage);
            }
        }
    }

    system("pause");

    return 0;
}