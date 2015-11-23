traffic=[]
with open ('trafficTrace.txt','r') as fp:
	for line in fp:
		if line[0]!='%':
			in1=line
			in1=in1.split()
			src=in1[0]
			dst=in1[1]
			traffic.append((src,dst))
	fp.close()

with open('traffic.txt','w') as fp:
	for each in traffic:
		src,dst=each
		fp.write(str(src)+' '+str(dst)+'\n')

	fp.close()

