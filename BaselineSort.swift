import Foundation

func moveLeft(_ a: inout [Int], n: Int) {
    var pos = 0
    for i in 0..<n {
        if a[i] != 0 {
            a[pos] = a[i]
            pos += 1
        }
    }
    for i in pos..<n {
        a[i] = 0
    }
}

print("write your numbers")
let n = Int(readLine()!)!
let inputStr = readLine()!
let parts = inputStr.components(separatedBy: " ").filter{!$0.isEmpty}

var arr:[Int] = []
for s in parts {
    arr.append(Int(s)!)
}

var data = arr
var res = [Int]()
var baseSum = 0
var removed = Array(repeating: false, count: n) //标记线段是否取出

while res.count < n {
    // 找当前未移除、非0元素的最小高度
    var minH = 999999
    for i in 0..<n {
        if (!removed[i]) && data[i] != 0 && data[i] < minH {
            minH = data[i]
        }
    }
    
    baseSum += minH
    
    // 所有未移除的线段减去minH
    for i in 0..<n {
        if (!removed[i]) {
            data[i] -= minH
        }
    }
    
    // 收集本轮归零的线段
    for i in 0..<n {
        if (!removed[i] && data[i] == 0) {
            res.append(baseSum)
            removed[i] = true //标记这条线段已经拿走
        }
    }
    
    moveLeft(&data, n: n)
}

print("The result is: \(res)")
let resDesc = Array(res.reversed())
print("The descending result is: \(resDesc)")