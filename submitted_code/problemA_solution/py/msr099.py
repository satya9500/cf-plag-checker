for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=set()
    for i in range(n):
        for j in range(i,n):
            s.add(l[i]-l[j])
    print(len(s)-1)