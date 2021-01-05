for s in[*open(0)][2::2]:
 t=set();
 for x in map(int,s.split()):t|={x+(x in t)}
 print(len(t))