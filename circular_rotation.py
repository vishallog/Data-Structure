arr = [1,2,3,4,5,6]
n = len(arr)
d = 2
c = 0
while c < d:
    x = arr[n-1]
    for i in range(n-1,0,-1):
        arr[i] = arr[i - 1]
    arr[0] = x
    c += 1

for i in arr:
    print(i, end=" ")


