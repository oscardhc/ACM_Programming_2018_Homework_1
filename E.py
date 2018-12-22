from random import *

with open('E.in','w') as f:
	n = 100000
	print >>f,n
	for i in range(n):
		print >>f,randint(0,100000000)
	m = 100000
	print >>f,m
	for i in range(m):
		l = randint(1,n)
		r = randint(1,n)
		if(l > r):
			l,r = r,l
		print >>f,randint(0,1),l,r
