#include <bits/stdc++.h>
// #include "linked_list.h"
using namespace std;

int32_t main()
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

    myarr.show();

    int q,p;
    cin>>q;
    for (int i = 1; i < 11; i++)
    {
        cin>>p;
        switch (p)
        {
        case 0:
            return 0;
            break;
        case 1:
            myarr.insert(34);
            myarr.show();
            break;
        case 2:
            myarr.moveToPos(3);
            myarr.show();

            break;
        case 3:
            myarr.moveToStart();
            myarr.show();
            break;
        case 4:
            myarr.moveToEnd();
            myarr.show();
            break;
        case 5:
            myarr.prev();
            myarr.show();
            break;
        case 6:
            myarr.next();
            myarr.show();
            break;
        case 7:
            myarr.length();
            break;
        case 8:
            myarr.currPos();
            break;
        case 9:
            myarr.remove();
            myarr.show();
            break;
        case 10:
            myarr.getValue();
            break;
        default:

            break;
        }
    }

    return 0;
}