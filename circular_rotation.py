#|RIGHT| rotation--------------------------------
def leftrotate(arr, d, n):
    c = 0
    while c < d:
        x = arr[n-1]
        for i in range(n-1,0,-1):
            arr[i] = arr[i - 1]
        arr[0] = x
        c += 1
    return arr
if __name__ == '__main__':
    arr = [1,2,3,4,5,6]
    N = len(arr)
    d = 2
    c = 0
    arr = leftrotate(arr, d, N)
    for i in arr:
        print(i, end=" ")

        
 #|LEFT| rotation-------------------------------------------------------------------------------------

def leftrotate(arr, d, n):
    c = 0
    while c < d:
        x = arr[0]
        for i in range(0,n-1,1):
            arr[i] = arr[i + 1]
        arr[n-1] = x
        c += 1
    return arr
if __name__ == '__main__':
    arr = [1,2,3,4,5,6]
    N = len(arr)
    d = 2
    c = 0
    arr = leftrotate(arr, d, N)
    for i in arr:
        print(i, end=" ")




