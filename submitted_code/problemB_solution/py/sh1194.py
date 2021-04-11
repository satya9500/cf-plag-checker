for _ in range(int(input())):
 n=int(input());lis=list(map(int,input().split()));li=set()
 for i in lis:li.add((i+1) if i in li else i)
 print(len(li))