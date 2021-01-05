for _ in range(int(input())):
 n = int(input());l=list(map(int,input().split()));deg=[0]*n;ar=[]
 for i in range(n-1):u,v=map(int,input().split());deg[u-1]+=1;deg[v-1]+=1 
 for i in range(n):
  if len(ar)<n:ar+=[l[i]]*(deg[i]-1)
 ar.sort(reverse=True);an=[sum(l)]
 for i in range(n-2):an.append(an[-1]+ar[i])
 print(*an)