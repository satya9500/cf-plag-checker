for _ in range(int(input())):
    n = int(input())
    x = list(map(int,input().split()))
    print(len(set(abs(i-j) for i in x for j in x if i != j)))