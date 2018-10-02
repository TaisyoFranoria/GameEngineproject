import random


#基底クラス'BaseMap'
class BaseMap(object):	
	def __init__(self):
		self.hight = random.randint(1,50)
		self.width = self.hight

		self.defMaps = [[1]*self.width for i in range(self.hight)]

		#firstpoint
		#領域確保における始点 左上に位置する
		self.fp_x = 0
		self.fp_y = 0

		#endpoint
		#領域確保における終点 右下に位置する
		self.ep_x = 0
		self.ep_y = 0
		
		self.room = 0
	
	def export(self):
		for i in range(self.hight):
			for j in range(self.width):
				print('%02d,' % (self.defMaps[i][j]),end="")
			print('')
		

class  randomMap(BaseMap):
	def __init__(self):
		self.hight = random.randint(1,50)
		self.width = self.hight

		self.defMaps = [[1]*self.width for i in range(self.hight)]

		#firstpoint
		#領域確保における始点 左上に位置する
		self.fp_x = 0
		self.fp_y = 0

		#endpoint
		#領域確保における終点 右下に位置する
		self.ep_x = 0
		self.ep_y = 0
		
		self.room = 0
	
		#部屋を作る	
	def makeROOM(self):
		#firstpoint
		#領域確保における始点 左上に位置する
		self.fp_x = random.randint(0,self.width-1)
		self.fp_y = random.randint(0,self.hight-1)


		#endpoint
		#領域確保における終点 右下に位置する
		self.ep_x=random.randint(self.fp_x+1,self.width)
		self.ep_y=random.randint(self.fp_y+1,self.hight)
		
		#確保した領域を0で埋める
		for y in range(self.fp_y,self.ep_y):
			for x in range(self.fp_x,self.ep_x):
				self.defMaps[x][y] = 0


		#export
	def export(self):
		for i in range(self.hight):
			for j in range(self.width):
				print('%02d,' % (self.defMaps[i][j]),end="")
			print('')

		#output
	def outputdata(self):
		print('(%d,%d)' % (self.fp_x,self.fp_y))
		print('(%d,%d)' % (self.ep_x,self.ep_y))
	def makeROOM(self):
		#firstpoint
		#領域確保における始点 左上に位置する
		self.fp_x = random.randint(0,self.width-1)
		self.fp_y = random.randint(0,self.hight-1)


		#endpoint
		#領域確保における終点 右下に位置する
		self.ep_x=random.randint(self.fp_x+1,self.width)
		self.ep_y=random.randint(self.fp_y+1,self.hight)
		
		#確保した領域を0で埋める
		for y in range(self.fp_y,self.ep_y):
			for x in range(self.fp_x,self.ep_x):
				self.defMaps[x][y] = 0


#入力から広さを決める
class MakeMap(BaseMap):
	def __init__(self,hight,width):
		self.hight = hight
		self.width = width

		self.defMaps = [[1]*self.width for i in range(self.hight)]

		#firstpoint
		#領域確保における始点 左上に位置する
		self.fp_x = 0
		self.fp_y = 0

		#endpoint
		#領域確保における終点 右下に位置する
		self.ep_x = 0
		self.ep_y = 0
		
		self.room = 0
		
	def makeROOM_R(self):
		#firstpoint
		#領域確保における始点 左上に位置する
		self.fp_x = random.randint(0,self.width-1)
		self.fp_y = random.randint(0,self.hight-1)


		#endpoint
		#領域確保における終点 右下に位置する
		self.ep_x=random.randint(self.fp_x+1,self.width)
		self.ep_y=random.randint(self.fp_y+1,self.hight)
		
		#確保した領域を0で埋める
		for y in range(self.fp_y,self.ep_y):
			for x in range(self.fp_x,self.ep_x):
				self.defMaps[x][y] = 0
	

	#このプログラムはフィールド全体を定義し、そのうち一部の領域を取得するプログラム
	#目的はフィールドの自動生成するため
	#領域を取得し、その広さに見合ったモデルを配置するためである
	#二元配列をマップに見立てている
basemap = randomMap()
basemap.makeROOM()#1
basemap.makeROOM()#2
basemap.export()
basemap.outputdata()

bmap = MakeMap(9,9)
bmap.makeROOM_R()
bmap.export()

path = 'data/basemap.csv'
strin = 'test'

with open(path,mode='w') as f:
	for i in range(basemap.hight):
		for j in range(basemap.width):
			f.write(str(basemap.defMaps[i][j]))
			f.write(',')
		f.write('\n')

f.close()
print('process end')
