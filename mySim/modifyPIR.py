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

def modify_RoutingAlgo(algo,configFile):
	in1=[]
	with open(configFile, 'r') as fp:
		line=''
		while line!='# RA\n':
			line=fp.readline()
			in1.append(line)
		fp.readline()
		in1.append('routing_algorithm: '+ algo +'\n')

		while True :
			line = fp.readline()
			if line == '':
				break
			in1.append(line)

	with open(configFile,'w') as fp:
		for each in in1:
			fp.write(each)

def modify_Traffic(TrafficType,configFile):
	in1=[]
	with open(configFile, 'r') as fp:
		line=''
		while line!='traffic_distribution: TRAFFIC_TABLE_BASED\n':
			line=fp.readline()
			in1.append(line)
		fp.readline()
		in1.append('traffic_table_filename: '+ TrafficType +'\n')

		while True :
			line = fp.readline()
			if line == '':
				break
			in1.append(line)

	with open(configFile,'w') as fp:
		for each in in1:
			fp.write(each)


