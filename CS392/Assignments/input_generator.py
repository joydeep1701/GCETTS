import random as rnd
up = 100000
f = open('sorted-input','w')
f.write(str(up)+'\n')
for i in range(up):
    f.write(str(i)+'\n')
f.close()
f = open('rev_sorted-input','w')
f.write(str(up)+'\n')
for i in range(up):
    f.write(str(up-i-1)+'\n')
f.close()
f = open('rand-input','w')
f.write(str(up)+'\n')
for i in range(up):
    f.write(str(int(rnd.random()*up))+'\n')
f.close()
