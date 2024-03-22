

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int min = 0, max = 10;
    const int ROW = 4, COLUMN = 4;
    int arr[ROW][COLUMN];
    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int e = 0; e < COLUMN; e++) {
            arr[i][e] = min + rand() % (max - min + 1);
            cout << arr[i][e] << " ";
        }
        cout << endl;
    }

    //1
    //int count=0, s=0;
    //for (int i = 0; i < 1; i++) {
    // s = 0;
    // for (int e = 0; e < COLUMN; e++) {
    //  count += arr[i][e];
    // }
    //}
    //cout << count << endl;
    //for (int i = 1; i < ROW; i++) {
    // s = 0;
    // for (int e = 0; e < COLUMN; e++) {
    //  s += arr[i][e];
    // }
    // cout << s << " " << endl;
    // if (count > s)count = s;
    //}
    //cout << count;

    //2
     //int a,count=0;
     //cin >> a;
     //for (int i = 0; i < ROW; i++) {
     // count = 0;
     // for (int e = 0; e < COLUMN; e++) {
     //  if (arr[i][e]%10 == a)count++;
     // }
     // cout << count << " ";
     //}


    //3
    bool flag = true;
    for (int i = 0; i < ROW; i++) {
        for (int e = i+1; e < COLUMN;e++) {
            if (arr[i][e] == arr[e][i]) flag = true;
            else {
                flag = false;
                break;
            }
        }
        if (flag == false) break;
    }
    if (flag) cout << "YES";
    else cout << "NO";

}
