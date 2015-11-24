import os
import subprocess
import modifyPIR
import shutil
import traceStats
from time import localtime

currentPwd=os.path.dirname(os.path.abspath(__file__))

trace_dir = '../myTraces/'
configFile=trace_dir+'myConfigs/config16x16.yaml'

timeStamp = str(localtime().tm_mday)+'_'+str(localtime().tm_mon)+'_'+str(localtime().tm_year)+'_'+str(localtime().tm_hour)+':'+str(localtime().tm_min)+':'+str(localtime().tm_sec)
savePath  = trace_dir+'OE_NOP_Transpose_trace_'+timeStamp+'/'
os.mkdir(savePath)

pir=0.005
increment=0.0003
pirList=[]

for epoch_count in range(1,50):

	print epoch_count, pir+increment

	pir = modifyPIR.modify_pir(pir,increment,configFile)
	command='../bin/noxim -config '+ configFile+">>"+savePath+'trace_'+str(pir)+'.txt'
	my_process=subprocess.call(command,shell=True)

	pirList.append(pir)



simStat = []
print pirList

for each in pirList:
	currentStat=traceStats.Stats(each,savePath)
	simStat.append((each,currentStat.getDelay()))

for each in simStat:
	p,d=each
	print p,d

fpTrace = open(savePath+'PIRlist.txt','w')
for each in pirList:
	fpTrace.write(str(each)+'\n')
fpTrace.close()




# out,error =my_process.communicate()

# print error
# print out
# os.system('cmd /d:/btp/python generate_input.py')