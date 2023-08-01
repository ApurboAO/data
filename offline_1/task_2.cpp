#include <bits/stdc++.h>
// #include "Arr.cpp"
#include "LL.cpp"
using namespace std;

void clear(List &obj)
{
    obj.moveToStart();
    for (int i = 0; i < obj.length(); i++)
    {

        obj.remove();
    }
}

void append(List &obj, int item)
{
    int initialPos = obj.currPos();

    obj.moveToEnd();
    obj.next();
    obj.insert(item);
    obj.moveToPos(initialPos);

}
// int *search(List &obj, int item)
// {
//     for (int i = 0; i < obj.used_size; i++)
//     {
//         if (obj.ptr[i] == item)
//         {
//             return &(obj.ptr[i]);
//         }
//     }
//     return nullptr;
// }

int main()
{

    int x, k;
    cin >> x >> k;

    List myarr(x);
    for (int i = 0; i < k; i++)
    {
        int input_num;
        cin >> input_num;
        myarr.insert(input_num);
        myarr.next();
    }
    myarr.moveToStart();
    // cout<<myarr.currPos()<<endl;
    myarr.show();

    int q, p;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> p;
        switch (p)
        {
        case 0:
            return 0;
            break;
        case 1:
            append(myarr, 34);
            myarr.show();
            break;
        case 2:
            // search(myarr, 3);
            // myarr.show();
            break;
        case 3:
            clear(myarr);
            myarr.show();
            break;

        default:
            break;
        }
    }
}