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
    int base[100]; // 保存每一轮减去的最小值
    int n;
    cout << "输入数字个数：";
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int data[100];
    for(int i = 0; i < n; i++)
        data[i] = arr[i];

    // 一共n轮
    for(int round = 0; round < n; round++)
    {
        // 找当前非0最小值
        int minv = 9999;
        for(int i = 0; i < n; i++)
        {
            if(data[i] != 0 && data[i] < minv)
            {
                minv = data[i];
            }
        }
        base[round] = minv; // 存本轮减掉的值

        // 所有非0数字减去minv
        for(int i = 0; i < n; i++)
        {
            if(data[i] != 0)
                data[i] -= minv;
        }
        moveLeft(data, n);
    }

    // ========= 累加base，还原原始数值 =========
    int res[100] = {0};
    for(int i = 0; i < n; i++)
    {
        int sum_base = 0;
        // base从第i项加到最后
        for(int k = i; k < n; k++)
        {
            sum_base += base[k];
        }
        res[i] = sum_base;
    }

    cout << "降序结果：";
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}
