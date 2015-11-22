def modify_pir(pir,increment):
	filedata = ''
	with open('config16x16.yaml', 'r') as fp:
		filedata = fp.read()
		fp.close()

	newdata = filedata.replace("packet_injection_rate: "+str(pir),"packet_injection_rate: "+str(pir+increment))

	with open('config16x16.yaml', 'w') as fp:
		fp.write(newdata)
		fp.close()

	return pir + increment