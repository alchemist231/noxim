import os
import subprocess
import modifyPIR
import shutil
from time import localtime

currentPwd=os.path.dirname(os.path.abspath(__file__))

trace_dir = '../myTraces/'
configFile=trace_dir+'myConfigs/config16x16.yaml'


timeStamp = str(localtime().tm_mday)+'_'+str(localtime().tm_mon)+'_'+str(localtime().tm_year)+'_'+str(localtime().tm_hour)+':'+str(localtime().tm_min)+':'+str(localtime().tm_sec)
savePath  = trace_dir+'trace_'+timeStamp+'/'
os.mkdir(savePath)

pir=0.01
increment=0.002

for epoch_count in range(1,9):

	pir = modifyPIR.modify_pir(pir,increment)
	command='../bin/noxim -config '+ configFile+">>"+savePath+'trace_'+str(pir)+'.txt'
	my_process=subprocess.call(command,shell=True)


# out,error =my_process.communicate()

# print error
# print out
# os.system('cmd /d:/btp/python generate_input.py')