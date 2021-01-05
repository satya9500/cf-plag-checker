for _ in range(int(input())):
    s=list(input());c=0
    for i in range(1,len(s)):
        if i>=2 and s[i]==s[i-2] or s[i]==s[i-1]:c+=1;s[i]='A'
    print(c)