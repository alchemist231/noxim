class Stats:

	def __init__(self,pir,path):
		self.maxDelay                   = []
		self.routedFlits 				= []
		self.Total_received_packets 	= 0
		self.Total_received_flits   	= 0
		self.Global_average_delay		= 0.0	
		self.Global_average_throughput	= 0.0
		self.Throughput 				= 0.0
		self.Max_delay 					= 0
		self.Total_energy				= 0.0
		self.Dynamic_energy				= 0.0
		self.Static_energy 				= 0.0
		self.extract(pir,path)


	def assign(self,ls):
		self.Total_received_packets 	= int(ls[0])
		self.Total_received_flits   	= int(ls[1])
		self.Global_average_delay		= float(ls[2])	
		self.Global_average_throughput	= float(ls[3])
		self.Throughput 				= float(ls[4])
		self.Max_delay 					= int(ls[5])
		self.Total_energy				= float(ls[6])
		self.Dynamic_energy				= float(ls[7])
		self.Static_energy 				= float(ls[8])

	def extract(self,pir,path):

		fp=open(path+'trace_'+ str(pir) + '.txt','r')

		maxDelayFlag = False
		maxFlitFlag  = False
		mainStats	 = False
		stats 		 = []
		
		for line in fp:

			if(maxDelayFlag == True and line!='];'):
				self.maxDelay.append(map(int,line.split()))

			if(maxFlitFlag == True and line!='];'):
				self.routedFlits.append(map(int,line.split()))

			if(line=='max_delay = ['):
				maxDelayFlag = True
			
			if(line=='routed_flits = ['):
				maxFlitFlag = True

			if(line=='];'):
				maxDelayFlag = False
				maxFlitFlag  = False

			if mainStats == True :
				in1=line.split()
				stats.append(in1[-1])

			if(line=='------->> Global Statistics <<--------\n'):
				mainStats = True

		self.assign(stats)

	def getDelay(self):
		return self.Global_average_delay






