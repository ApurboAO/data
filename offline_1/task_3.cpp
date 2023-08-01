#include <bits/stdc++.h>
#include "Arr.cpp"
// #include "LL.cpp"
using namespace std;

class Garage
{
// private:
public:
    int no_car;
    int no_garage;
    int garage_capacity;
    List cars;
    Garage(int _no_car, int _no_garage, int _garage_capacity)
    {
        no_car = _no_car;
        no_garage = _no_garage; 
        garage_capacity = _garage_capacity;
        cars = List(garage_capacity);
    }

    Garage()
    {
    }
    ~Garage()
    {
    }
};

int find_garage_for_park(Garage garages[])
{
    for (int i = garages[0].no_garage-1; i >= 0; i--)
    {
        if ((garages[i].cars.length()) < garages[i].garage_capacity)
        {

            return i;
        }
    }
    return -1;
}

void rent_car(int _car_no, Garage garages[])
{
    int parking_garage = find_garage_for_park(garages);
    if (parking_garage == -1)
    {
        return;
    }
    else
    {
        // garages[parking_garage].cars.append(_car_no);
    }
}
int find_garage_to_remove(Garage garages[])
{
    for (int i = 0; i < garages[0].no_garage; i++)
    {
        if (garages[i].cars.length() > 0)
        {
            return i;
        }
    }
    return -1;
}
void req_car(Garage garages[])
{
    int parking_garage = find_garage_to_remove(garages);
    if (parking_garage == -1)
    {
        cout << "There is no  car" << endl;
        return;
    }
    else
    {
        garages[parking_garage].cars.moveToStart();
        garages[parking_garage].cars.remove();
    }

}



int32_t main()
{
    int x, y, z;
    cin >> x >> y >> z;
    cin.ignore();
    Garage garages[y];
    for (int i = 0; i < y; i++)
    {
        garages[i] = Garage(x, y, (z + 1));
        string input;
        getline(cin, input);
        string token;
        istringstream iss(input);
        while (getline(iss, token, ' '))
        {
            garages[i].cars.insert(stoi(token));
            garages[i].cars.next();
        }
        garages[i].cars.moveToStart();
    }
    int q;
    cin>>q;
    cin.ignore();
    for(int i=0;i<q;i++){
        string queries;
        getline(cin,queries);
        istringstream iss(queries);
        string command;
        int car_val;
        iss>>command>>car_val;
        
        if(command=="ret"){
            rent_car(car_val,garages);
        }
        else if(command=="req"){
            req_car(garages);
        }

    }

    for (int i = 0; i < y; i++)
    {

        garages[i].cars.show();
    }

    return 0;
}
/*
10 4 4
1 2 3 4 5
3 4
3
3 4 5 6
*/