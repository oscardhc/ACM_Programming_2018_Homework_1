from random import *

with open('G.in','w') as f:
	n = 200000
	print >>f, n
	for i in range(n) :
		ty = randint(0,2)
		if ty == 0 :
			print >>f,'QUERY'
		elif ty == 1 :
			print >>f,'REVERSE'
		else :
			print >>f,'PUSH',randint(0,1)

			
