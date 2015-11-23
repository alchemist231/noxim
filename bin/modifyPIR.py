def modify_pir(pir,increment,configFile):
	in1=[]
	with open(configFile, 'r') as fp:
		line=''
		while line!='# PIR\n':
			line=fp.readline()
			in1.append(line)
		fp.readline()
		in1.append('packet_injection_rate: '+str(pir+increment)+'\n')

		while True :
			line = fp.readline()
			if line == '':
				break
			in1.append(line)

	with open(configFile,'w') as fp:
		for each in in1:
			fp.write(each)

	return pir + increment