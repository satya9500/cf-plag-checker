for s in[*open(0)][1:]:
 t=0,0;r=0
 for x in s:
  if x in t:x=0;r+=1
  t=t[1],x
 print(r)