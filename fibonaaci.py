i = 0
sum,sum1,sum2,sum3  = 0,0,1,0
arr = []
count = int(input("Enter the number for which you want to print the fabicino series:"))
p = 0
while p < count:
    arr.append(sum1)
    sum = sum1 + sum2
    if p == count - 1:
        print(sum1)
        break
    sum1 = sum2
    sum2 = sum
    p += 1
print()
print("Number of fabicino series is:"," ",sum1)
for i in arr:
    print(i,end=" ")

