#include <iostream>
using namespace std;
void moveLeft(int a[], int n){
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            a[pos] = a[i];
            pos++;
        }
    }
    for(int i = pos; i < n; i++)
        a[i] = 0;
}

int main()
{
    int arr[100];
    int n;
    cout << "输入数字个数：";
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int data[100];
    for(int i = 0; i < n; i++)
        data[i] = arr[i];

    int res[100] = {0};
    int resCnt = 0;
    int totalBase = 0; // 累计减去的总和！！

    for(int round = 0; round < n; round++)
    {
        int minv = 1000000000;
        for(int i = 0; i < n; i++)
        {
            if(data[i] != 0 && data[i] < minv)
            {
                minv = data[i];
            }
        }
        if(minv == 1000000000)
            break;

        totalBase += minv; // 叠加基线
        res[resCnt] = totalBase; // 累加后的才是原始数值！

        for(int i = 0; i < n; i++)
        {
            if(data[i] != 0)
                data[i] -= minv;
        }
        moveLeft(data, n);

        resCnt++;
    }

    cout << "升序结果：";
    for(int i = 0; i < resCnt; i++)
        cout << res[i] << " ";
    return 0;
}
