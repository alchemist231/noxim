fp1=open("testData.txt",'r')
val1={}
val2={}


for i in range(0,111):
	src,dst,current=map(int,fp1.readline().split())
	if current not in val1 :
		val1[current]=[]
		val1[current].append((src,dst))
	else :
		val1[current].append((src,dst))

	if (src,dst) not in val2:
		val2[(src,dst)]=1
	else :
		val2[(src,dst)]+=1 


cnt=0

for key,values in val1.iteritems():
	for every in set(values):
		val=values.count(every)
		print key,":",val
		cnt=cnt+val

print "-"*100
for key,val in val2.iteritems():
	print key,":",val

print "count: ",cnt 