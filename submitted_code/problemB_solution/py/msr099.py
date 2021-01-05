for _ in range(int(input())):
    n=int(input())
    s=set()
    l=list(map(int,input().split()))
    for i in l:
        if i in s:
            s.add(i+1)
        else:
            s.add(i)
    print(len(s))